/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

#include "conf_wm8731.h"

/**
 * \brief  Initial the WM8731 to play back the sample WAV file.
 */
static void init_audio_dac(void)
{
	uint32_t ul_value;
	/* First, disable programmable clock */
	pmc_disable_pck(PMC_PCK_0);
	/* Then, configure PMC Programmable Clock */
	pmc_switch_pck_to_mainck(PMC_PCK_0, PMC_MCKR_PRES_CLK_1);
	/* Finally, enable programmable clock */
	pmc_enable_pck(PMC_PCK_0);
	/* reset the WM8731 */
	wm8731_reset();
	/* Select the WM8731 DAC */
	wm8731_dac_select(1);
	/* Set the WM8731 to usb mode and 48K DAC */
	wm8731_set_sampling_control(1,0,0);
	/* Set the WM8731 audio interface to I2S mode */
	ul_value = WM8731_REG_DIGITAL_AUDIO_INTERFACE_FORMAT_I2S;
	wm8731_set_digital_audio_data_bit_length(ul_value);
	/* Set the WM8731 audio data bit length to 16bit */
	ul_value = WM8731_REG_DIGITAL_AUDIO_INTERFACE_FORMAT_IWL_16_BIT;
	wm8731_set_digital_audio_data_bit_length(ul_value);
	/* Disable the WM8731 DAC soft mute */
	wm8731_set_dac_soft_mute(0);
	/* Power up the WM8731 DAC */
	wm8731_power_mode_dac();
	/* Active the WM8731 */
	wm8731_set_active(1);
}

/**
 * \brief  Initial the ssc interface.
 */
static void init_audio_ssc(void)
{
	clock_opt_t tx_clk_option;
	data_frame_opt_t tx_data_frame_option;

	/* Initialize clock */
	pmc_enable_periph_clk(ID_SSC);

	/* Reset SSC */
	ssc_reset(SSC);
	/* Configure SSC */
	ssc_set_clock_divider(SSC, WM8731_SAMPLE_RATE * (WM8731_BITS_BY_SLOT + 1) * 2, sysclk_get_peripheral_hz());

	/* Transmitter clock mode configuration. */
	tx_clk_option.ul_cks = SSC_TCMR_CKS_MCK;
	tx_clk_option.ul_cko = SSC_TCMR_CKO_CONTINUOUS;
	tx_clk_option.ul_cki = 0;
	tx_clk_option.ul_ckg = SSC_TCMR_CKG_NONE;
	tx_clk_option.ul_start_sel = SSC_TCMR_START_RF_EDGE;
	tx_clk_option.ul_sttdly = 1;
	tx_clk_option.ul_period = WM8731_BITS_BY_SLOT - 1;
	/* Transmitter frame mode configuration. */
	tx_data_frame_option.ul_datlen = WM8731_BITS_BY_SLOT - 1;
	tx_data_frame_option.ul_msbf = SSC_TFMR_MSBF;
	tx_data_frame_option.ul_datnb = 0;
	tx_data_frame_option.ul_fslen = WM8731_BITS_BY_SLOT - 1;
	tx_data_frame_option.ul_fslen_ext = 0;
	tx_data_frame_option.ul_fsos = SSC_TFMR_FSOS_NEGATIVE;
	tx_data_frame_option.ul_fsedge = SSC_TFMR_FSEDGE_POSITIVE;
	/* Configure the SSC transmitter to I2S mode. */
	ssc_set_transmitter(SSC, &tx_clk_option, &tx_data_frame_option);

	/* Disable transmitter first */
	ssc_disable_tx(SSC);

	/* Disable All Interrupt */
	ssc_disable_interrupt(SSC, 0xFFFFFFFF);
}

/**
 * \brief DMA driver configuration
 */
static void init_audio_dma(void)
{
	uint32_t cfg;

	/* Enable DMA controller */
	dmac_enable(DMAC);

	/* Initialize and enable DMA controller */
	pmc_enable_periph_clk(ID_DMAC);
	dmac_init(DMAC);
	dmac_set_priority_mode(DMAC, DMAC_PRIORITY_ROUND_ROBIN);
	dmac_enable(DMAC);

	/* Disable the DMA channel for SSC */
	dmac_channel_disable(DMAC, WM8731_DMA_CH);

	/* Set channel configuration register */
	cfg = DMAC_CFG_SOD_ENABLE |        /* Enable stop on done */
			DMAC_CFG_DST_H2SEL |       /* Hardware Selection for the Destination */
			DMAC_CFG_DST_PER(3) | /* Destination with Peripheral identifier */
			DMAC_CFG_AHB_PROT(1) |     /* Set AHB Protection */
			DMAC_CFG_FIFOCFG_ALAP_CFG; /* FIFO Configuration */

	dmac_channel_set_configuration(DMAC, WM8731_DMA_CH, cfg);

	/* Set interrupt */
	NVIC_EnableIRQ(DMAC_IRQn);
	dmac_enable_interrupt(DMAC, (DMAC_EBCIER_CBTC0 << WM8731_DMA_CH));
}

/**
 * Configure the Audio Service and Peripherals
 */
void audio_init(void) {
	/* Initialize the WM8731 to DAC */
	init_audio_dac();

	/* Initialize the SSC Interface */
	init_audio_ssc();

	/* Configure DMA */
	init_audio_dma();
}
