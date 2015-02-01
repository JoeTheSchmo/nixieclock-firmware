/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include <stdint.h>

#include "twi.h"
#include "wm8731.h"

//! Address of the Slave Device on the TWI Bus
#define WM8731_SLAVE_ADDRESS 0x1B

// Register Values
uint16_t wm8731_r_llir = 0x0097;
uint16_t wm8731_r_rlir = 0x0097;
uint16_t wm8731_r_lhor = 0x0000;
uint16_t wm8731_r_rhor = 0x0000;
uint16_t wm8731_r_aapcr = 0x000A;
uint16_t wm8731_r_dapcr = 0x0008;
uint16_t wm8731_r_pdcr = 0x009F;
uint16_t wm8731_r_daifr = 0x000A;
uint16_t wm8731_r_scr = 0x0000;
uint16_t wm8731_r_acr = 0x0000;
uint16_t wm8731_r_rr = 0x0000;

/** \brief Write to the WM8731 Codec via the TWI Bus
 *
 * \param[in] reg Register Address
 * \param[in] value 9bit data value for this register
 *
 * \return 0 if all bytes were written, -1 if an error occurred.
 */
inline int32_t wm8731_write_register(uint8_t reg, uint16_t value) {
	// 7 bits of address mixed with 1 bit of data
	reg = (reg << 1) | ((value & 0x0100) >> 8);

	// configure packet to be transmitted
	static twi_packet_t pkt;
	pkt.chip = WM8731_SLAVE_ADDRESS;
	pkt.addr[0] = reg;
	pkt.addr_length = 1;
	pkt.buffer = (uint8_t *)&value;
	pkt.length = 1;

	// write the data to the bus
	return twi_master_write(TWI0, &pkt) == TWI_SUCCESS ? 0 : -1;
}

//

int32_t wm8731_set_linein_left_volume(uint8_t volume) {
	wm8731_r_llir = (wm8731_r_llir & ~WM8731_LLIR_LINVOL_Msk) | WM8731_LLIR_LINVOL(volume);
	return wm8731_write_register(WM8731_LLIR, wm8731_r_llir);
}

int32_t wm8731_set_linein_left_mute(uint8_t mute) {
	wm8731_r_llir = (wm8731_r_llir & ~WM8731_LLIR_MUTE_Msk) | (mute ? WM8731_LLIR_MUTE : 0);
	return wm8731_write_register(WM8731_LLIR, wm8731_r_llir);
}

int32_t wm8731_set_linein_right_volume(uint8_t volume) {
	wm8731_r_rlir = (wm8731_r_rlir & ~WM8731_RLIR_LINVOL_Msk) | WM8731_RLIR_LINVOL(volume);
	return wm8731_write_register(WM8731_RLIR, wm8731_r_rlir);
}

int32_t wm8731_set_linein_right_mute(uint8_t mute) {
	wm8731_r_rlir = (wm8731_r_rlir & ~WM8731_RLIR_MUTE_Msk) | (mute ? WM8731_RLIR_MUTE : 0);
	return wm8731_write_register(WM8731_RLIR, wm8731_r_rlir);
}

//

int32_t wm8731_set_headphone_left_volume(uint8_t volume) {
	wm8731_r_lhor = (wm8731_r_lhor & ~WM8731_LHOR_LHPVOL_Msk) | WM8731_LHOR_LHPVOL(volume);
	return wm8731_write_register(WM8731_LHOR, wm8731_r_lhor);
}

int32_t wm8731_set_headphone_left_zcen(uint8_t zcen) {
	wm8731_r_lhor = (wm8731_r_lhor & ~WM8731_LHOR_LZCEN_Msk) | (zcen ? WM8731_LHOR_LZCEN : 0);
	return wm8731_write_register(WM8731_LHOR, wm8731_r_lhor);
}

int32_t wm8731_set_headphone_right_volume(uint8_t volume) {
	wm8731_r_rhor = (wm8731_r_rhor & ~WM8731_RHOR_RHPVOL_Msk) | WM8731_RHOR_RHPVOL(volume);
	return wm8731_write_register(WM8731_RHOR, wm8731_r_rhor);
}

int32_t wm8731_set_headphone_right_zcen(uint8_t zcen) {
	wm8731_r_rhor = (wm8731_r_rhor & ~WM8731_RHOR_RZCEN_Msk) | (zcen ? WM8731_RHOR_RZCEN : 0);
	return wm8731_write_register(WM8731_RHOR, wm8731_r_rhor);
}

//

int32_t wm8731_set_mic_boost(uint8_t enable) {
	wm8731_r_aapcr = (wm8731_r_aapcr & ~WM8731_AAPCR_MICBOOST_Msk) | (enable ? WM8731_AAPCR_MICBOOST : 0);
	return wm8731_write_register(WM8731_AAPCR, wm8731_r_aapcr);
}

int32_t wm8731_set_mic_mute(uint8_t mute) {
	wm8731_r_aapcr = (wm8731_r_aapcr & ~WM8731_AAPCR_MUTEMIC_Msk) | (mute ? WM8731_AAPCR_MUTEMIC : 0);
	return wm8731_write_register(WM8731_AAPCR, wm8731_r_aapcr);
}

int32_t wm8731_set_input_select(uint8_t input) {
	wm8731_r_aapcr = (wm8731_r_aapcr & ~WM8731_AAPCR_INSEL_Msk) | (input ? WM8731_AAPCR_INSEL : 0);
	return wm8731_write_register(WM8731_AAPCR, wm8731_r_aapcr);
}

int32_t wm8731_set_bypass(uint8_t enable) {
	wm8731_r_aapcr = (wm8731_r_aapcr & ~WM8731_AAPCR_BYPASS_Msk) | (enable ? WM8731_AAPCR_BYPASS : 0);
	return wm8731_write_register(WM8731_AAPCR, wm8731_r_aapcr);
}

int32_t wm8731_set_dac_select(uint8_t dac) {
	wm8731_r_aapcr = (wm8731_r_aapcr & ~WM8731_AAPCR_DACSEL_Msk) | (dac ? WM8731_AAPCR_DACSEL : 0);
	return wm8731_write_register(WM8731_AAPCR, wm8731_r_aapcr);
}

int32_t wm8731_set_side_tone_enable(uint8_t enable) {
	wm8731_r_aapcr = (wm8731_r_aapcr & ~WM8731_AAPCR_SIDETONE_Msk) | (enable ? WM8731_AAPCR_SIDETONE : 0);
	return wm8731_write_register(WM8731_AAPCR, wm8731_r_aapcr);
}

int32_t wm8731_set_side_tone_attenuation(uint8_t att) {
	wm8731_r_aapcr = (wm8731_r_aapcr & ~WM8731_AAPCR_SIDEATT_Msk) | WM8731_AAPCR_SIDEATT(att);
	return wm8731_write_register(WM8731_AAPCR, wm8731_r_aapcr);
}

//

int32_t wm8731_set_adc_highpass_filter(uint8_t enable) {
	wm8731_r_dapcr = (wm8731_r_dapcr & ~WM8731_DAPCR_ADCHPD_Msk) | (enable ? WM8731_DAPCR_ADCHPD : 0);
	return wm8731_write_register(WM8731_DAPCR, wm8731_r_dapcr);
}

int32_t wm8731_set_deemphasis(uint8_t deemph) {
	wm8731_r_dapcr = (wm8731_r_dapcr & ~WM8731_DAPCR_DEEMPH_Msk) | WM8731_DAPCR_DEEMPH(deemph);
	return wm8731_write_register(WM8731_DAPCR, wm8731_r_dapcr);
}

int32_t wm8731_set_dac_soft_mute(uint8_t mute) {
	wm8731_r_dapcr = (wm8731_r_dapcr & ~WM8731_DAPCR_DACMU_Msk) | (mute ? WM8731_DAPCR_DACMU : 0);
	return wm8731_write_register(WM8731_DAPCR, wm8731_r_dapcr);
}

int32_t wm8731_set_store_dc_offset(uint8_t enable) {
	wm8731_r_dapcr = (wm8731_r_dapcr & ~WM8731_DAPCR_HPOR_Msk) | (enable ? WM8731_DAPCR_HPOR : 0);
	return wm8731_write_register(WM8731_DAPCR, wm8731_r_dapcr);
}

//

int32_t wm8731_set_powerdown_linein(uint8_t pd_linein) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_LINEINPD_Msk) | (pd_linein ? WM8731_PDCR_LINEINPD : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

int32_t wm8731_set_powerdown_mic(uint8_t pd_mic) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_MICPD_Msk) | (pd_mic ? WM8731_PDCR_MICPD : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

int32_t wm8731_set_powerdown_adc(uint8_t pd_adc) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_ADCPD_Msk) | (pd_adc ? WM8731_PDCR_ADCPD : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

int32_t wm8731_set_powerdown_dac(uint8_t pd_dac) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_DACPD_Msk) | (pd_dac ? WM8731_PDCR_DACPD : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

int32_t wm8731_set_powerdown_out(uint8_t pd_out) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_OUTPD_Msk) | (pd_out ? WM8731_PDCR_OUTPD : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

int32_t wm8731_set_powerdown_osc(uint8_t pd_osc) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_OSCPD_Msk) | (pd_osc ? WM8731_PDCR_OSCPD : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

int32_t wm8731_set_powerdown_clkout(uint8_t pd_clkout) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_CLKOUTPD_Msk) | (pd_clkout ? WM8731_PDCR_CLKOUTPD : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

int32_t wm8731_set_powerdown_poweroff(uint8_t poweroff) {
	wm8731_r_pdcr = (wm8731_r_pdcr & ~WM8731_PDCR_POWEROFF_Msk) | (poweroff ? WM8731_PDCR_POWEROFF : 0);
	return wm8731_write_register(WM8731_PDCR, wm8731_r_pdcr);
}

//

int32_t wm8731_set_digital_audio_format(uint8_t format) {
	wm8731_r_daifr = (wm8731_r_daifr & ~WM8731_DAIFR_FORMAT_Msk) | WM8731_DAIFR_FORMAT(format);
	return wm8731_write_register(WM8731_DAIFR, wm8731_r_daifr);
}

int32_t wm8731_set_digital_audio_data_bit_length(uint8_t len) {
	wm8731_r_daifr = (wm8731_r_daifr & ~WM8731_DAIFR_IWL_Msk) | WM8731_DAIFR_IWL(len);
	return wm8731_write_register(WM8731_DAIFR, wm8731_r_daifr);
}

int32_t wm8731_set_dac_lrp(uint8_t phase) {
	wm8731_r_daifr = (wm8731_r_daifr & ~WM8731_DAIFR_LRP_Msk) | (phase ? WM8731_DAIFR_LRP : 0);
	return wm8731_write_register(WM8731_DAIFR, wm8731_r_daifr);
}

int32_t wm8731_set_dac_lrswap(uint8_t swap) {
	wm8731_r_daifr = (wm8731_r_daifr & ~WM8731_DAIFR_LRSWAP_Msk) | (swap ? WM8731_DAIFR_LRSWAP : 0);
	return wm8731_write_register(WM8731_DAIFR, wm8731_r_daifr);
}

int32_t wm8731_set_ms_mode(uint8_t msmode) {
	wm8731_r_daifr = (wm8731_r_daifr & ~WM8731_DAIFR_MS_Msk) | (msmode ? WM8731_DAIFR_MS : 0);
	return wm8731_write_register(WM8731_DAIFR, wm8731_r_daifr);
}

int32_t wm8731_set_bit_clk_invert(uint8_t bclkinv) {
	wm8731_r_daifr = (wm8731_r_daifr & ~WM8731_DAIFR_BCLKINV_Msk) | (bclkinv ? WM8731_DAIFR_BCLKINV : 0);
	return wm8731_write_register(WM8731_DAIFR, wm8731_r_daifr);
}

//

int32_t wm8731_set_sampling(uint8_t mode, uint8_t bosr, uint8_t rate) {
	wm8731_r_scr = (wm8731_r_scr & ~WM8731_SCR_USB_Msk) | (mode ? WM8731_SCR_USB : 0);
	wm8731_r_scr = (wm8731_r_scr & ~WM8731_SCR_BOSR_Msk) | (bosr ? WM8731_SCR_BOSR : 0);
	wm8731_r_scr = (wm8731_r_scr & ~WM8731_SCR_SR_Msk) | WM8731_SCR_SR(rate);
	return wm8731_write_register(WM8731_SCR, wm8731_r_scr);
}

int32_t wm8731_set_core_clock_divider(uint8_t div2) {
	wm8731_r_scr = (wm8731_r_scr & ~WM8731_SCR_CLKIDIV2_Msk) | (div2 ? WM8731_SCR_CLKIDIV2 : 0);
	return wm8731_write_register(WM8731_SCR, wm8731_r_scr);
}

int32_t wm8731_set_clkout_divider(uint8_t div2) {
	wm8731_r_scr = (wm8731_r_scr & ~WM8731_SCR_CLKODIV2_Msk) | (div2 ? WM8731_SCR_CLKODIV2 : 0);
	return wm8731_write_register(WM8731_SCR, wm8731_r_scr);
}

//

int32_t wm8731_set_active(uint8_t active) {
	wm8731_r_acr = (wm8731_r_acr & ~WM8731_ACR_ACTIVE_Msk) | (active ? WM8731_ACR_ACTIVE : 0);
	return wm8731_write_register(WM8731_ACR, wm8731_r_acr);
}

//

int32_t wm8731_reset() {
	// set the default register states
	wm8731_r_llir = 0x0097;
	wm8731_r_rlir = 0x0097;
	wm8731_r_lhor = 0x0000;
	wm8731_r_rhor = 0x0000;
	wm8731_r_aapcr = 0x000A;
	wm8731_r_dapcr = 0x0008;
	wm8731_r_pdcr = 0x009F;
	wm8731_r_daifr = 0x009F;
	wm8731_r_scr = 0x0000;
	wm8731_r_acr = 0x0000;
	wm8731_r_rr = 0x0000;

	// reset the codec
	return wm8731_write_register(WM8731_RR, wm8731_r_rr);
}
