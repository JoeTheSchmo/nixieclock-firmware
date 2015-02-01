/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include <stdio.h>

#include "compiler.h"
#include "ssc.h"
#include "wm8731.h"

//! Audio Service State Flags
volatile enum {
	audio_state_init = 1,  //!< If flag is set, the service has been initialized
} audio_state = 0;

/** Audio Service Initialization
 *
 */
void audio_init(void) {
	// Initialize the Codec

	// reset the WM8731
	if (wm8731_reset() < 0) {
		kprintf("wm8731: failed to reset\r\n");
	} else {
		// select the WM8731 DAC
		wm8731_set_dac_select(1);
		// disable the dsp and digital audio interface
		wm8731_set_active(0);
		// set usb mode and 44.1kHz DAC, requires 12MHz MCLK from programmable clock
		// sampling = 12MHz MCLK / 272fs == 44.100kHz (44,100 Hz)
		wm8731_set_sampling(1, 1, 0x8);
		// put the digital audio in master mode and let it send us clocks
		wm8731_set_ms_mode(1);
		// set audio interface to MSB-first left justified
		wm8731_set_digital_audio_format(1);
		// set the data length to 16 bit
		wm8731_set_digital_audio_data_bit_length(0);
		// swap the left and right channels
		wm8731_set_dac_lrswap(1);
		// disable the soft mute in the dac
		wm8731_set_dac_soft_mute(0);
		// set power control for playback only
		wm8731_set_powerdown_dac(0);
		wm8731_set_powerdown_out(0);
		wm8731_set_powerdown_poweroff(0);
	}

	// Initialize the SSC Controller

	// Reset and Disable the SSC controller
	ssc_reset(SSC);
	ssc_disable_rx(SSC);
	ssc_disable_tx(SSC);

/* TODO: Figure out clocking
	// do not use the master clock divider
	SSC_CMR = SSC_CMR_DIV(0);
	// set the transmit clock mode register
	// - TK Clock Signal Source (From WM8731)
	// - No Clock Output
	// - START on rising edge on TF Signal (Left Channel Select)
	SSC_TCMR = SSC_TCMR_CKS(SSC_TCMR_CKS_RK) | SSC_TCMR_START(SSC_TCMR_START_RF_RISING);
	// set the transmit frame mode register 
	// - DATLEN 16 bits
	// - Most Significant Bit First
	SSC_TFMR = SSC_TFMR_DATLEN(15) | SSC_TFMR_MSBF;
*/

	// TODO: Do we need to connect TK and RK on real board?

	// Set the initialized flag
	audio_state |= audio_state_init;
}
