//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2013 - 2015 Joe Ciccone
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __WM8731_H_
#define __WM8731_H_

#include <types.h>

#define WM8731_TWI_ADDR             0x1B

#define WM8731_REG_ADDR             0b1111111000000000
#define WM8731_REG_DATA             0b0000000111111111

#define WM8731_LLIR_Def             0b0000000010010111
#define WM8731_RLIR_Def             0b0000001010010111
#define WM8731_LHOR_Def             0b0000010001111001
#define WM8731_RHOR_Def             0b0000011001111001
#define WM8731_AAPCR_Def            0b0000100000001010
#define WM8731_DAPCR_Def            0b0000101000001000
#define WM8731_PDCR_Def             0b0000110010011111
#define WM8731_DAIFR_Def            0b0000111010011111
#define WM8731_SCR_Def              0b0001000000000000
#define WM8731_ACR_Def              0b0001001000000000
#define WM8731_RR_Def               0b0001111000000000

// WM8731_LLIR - Left Line In Register

#define WM8731_LLIR_LINVOL_Msk      0x001F
#define WM8731_LLIR_LINVOL_Off      0x00
#define WM8731_LLIR_LINMUTE         0x0080
#define WM8731_LLIR_LRINBOTH        0x0100

extern int32_t wm8731_set_linein_left_volume(uint8_t volume);
extern int32_t wm8731_set_linein_left_mute(uint8_t mute);

// WM8731_RLIR - Right Line In Register

#define WM8731_RLIR_RINVOL_Msk      0x001F
#define WM8731_RLIR_RINVOL_Off      0x00
#define WM8731_RLIR_RINMUTE         0x0080
#define WM8731_RLIR_LINBOTH         0x0100

extern int32_t wm8731_set_linein_right_volume(uint8_t volume);
extern int32_t wm8731_set_linein_right_mute(uint8_t mute);

// WM8731_LHOR - Left Headpone Out Register

#define WM8731_LHOR_LHPVOL_Msk      0x007F
#define WM8731_LHOR_LHPVOL_Off      0x00
#define WM8731_LHOR_LZCEN           0x0080
#define WM8731_LHOR_LRHPBOTH        0x0100

extern int32_t wm8731_set_headphone_left_volume(uint8_t volume);
extern int32_t wm8731_set_headphone_left_zcen(uint8_t zcen);

// WM8731_RHOR - Right Headphone Out Register

#define WM8731_RHOR_RHPVOL_Msk      0x007F
#define WM8731_RHOR_RHPVOL_Off      0x00
#define WM8731_RHOR_RZCEN           0x0080
#define WM8731_RHOR_RLHPBOTH        0x0100

extern int32_t wm8731_set_headphone_right_volume(uint8_t volume);
extern int32_t wm8731_set_headphone_right_zcen(uint8_t zcen);

// WM8731_AAPCR - Analogue Audio Path Control Register

#define WM8731_AAPCR_MICBOOST       0x0001
#define WM8731_AAPCR_MUTEMIC        0x0002
#define WM8731_AAPCR_INSEL          0x0004
#define WM8731_AAPCR_BYPASS         0x0008
#define WM8731_AAPCR_DACSEL         0x0010
#define WM8731_AAPCR_SIDETONE       0x0020
#define WM8731_AAPCR_SIDEATT_Msk    0x00C0
#define WM8731_AAPCR_SIDEATT_Off    0x06

extern int32_t wm8731_set_mic_boost(uint8_t enable);
extern int32_t wm8731_set_mic_mute(uint8_t mute);
extern int32_t wm8731_set_input_select(uint8_t input);
extern int32_t wm8731_set_bypass(uint8_t enable);
extern int32_t wm8731_set_dac_select(uint8_t dac);
extern int32_t wm8731_set_side_tone_enable(uint8_t enable);
extern int32_t wm8731_set_side_tone_attenuation(uint8_t att);

// WM8731_DAPCR - Digital Audio Path Control Register

#define WM8731_DAPCR_ADCHPD         0x0001
#define WM8731_DAPCR_DEEMPH_Msk     0x0006
#define WM8731_DAPCR_DEEMPH_Off     0x02
#define WM8731_DAPCR_DACMU          0x0008
#define WM8731_DAPCR_HPOR           0x0010

extern int32_t wm8731_set_adc_highpass_filter(uint8_t enable);
extern int32_t wm8731_set_deemphasis(uint8_t deemph);
extern int32_t wm8731_set_dac_soft_mute(uint8_t mute);
extern int32_t wm8731_set_store_dc_offset(uint8_t enable);

// WM8731_PDCR - Power Down Control Register

#define WM8731_PDCR_LINEINPD        0x0001
#define WM8731_PDCR_MICPD           0x0002
#define WM8731_PDCR_ADCPD           0x0004
#define WM8731_PDCR_DACPD           0x0008
#define WM8731_PDCR_OUTPD           0x0010
#define WM8731_PDCR_OSCPD           0x0020
#define WM8731_PDCR_CLKOUTPD        0x0040
#define WM8731_PDCR_POWEROFF        0x0080

extern int32_t wm8731_set_powerdown_linein(uint8_t pd_linein);
extern int32_t wm8731_set_powerdown_mic(uint8_t pd_mic);
extern int32_t wm8731_set_powerdown_adc(uint8_t pd_adc);
extern int32_t wm8731_set_powerdown_dac(uint8_t pd_dac);
extern int32_t wm8731_set_powerdown_out(uint8_t pd_out);
extern int32_t wm8731_set_powerdown_osc(uint8_t pd_osc);
extern int32_t wm8731_set_powerdown_clkout(uint8_t pd_clkout);
extern int32_t wm8731_set_powerdown_poweroff(uint8_t poweroff);

// WM8731_DAIFR - Digital Audio Interface Format Register

#define WM8731_DAIFR_FORMAT_Msk     0x0003
#define WM8731_DAIFR_FORMAT_Off     0x00
#define WM8731_DAIFR_IWL_Msk        0x000C
#define WM8731_DAIFR_IWL_Off        0x02
#define WM8731_DAIFR_LRP            0x0010
#define WM8731_DAIFR_LRSWAP         0x0020
#define WM8731_DAIFR_MS             0x0040
#define WM8731_DAIFR_BCLKINV        0x0080

extern int32_t wm8731_set_digital_audio_format(uint8_t format);
extern int32_t wm8731_set_digital_audio_data_bit_length(uint8_t len);
extern int32_t wm8731_set_dac_lrp(uint8_t phase);
extern int32_t wm8731_set_dac_lrswap(uint8_t swap);
extern int32_t wm8731_set_ms_mode(uint8_t msmode);
extern int32_t wm8731_set_bit_clk_invert(uint8_t bclkinv);

// WM8731_SCR - Sampling Control Register

#define WM8731_SCR_USB              0x0001
#define WM8731_SCR_BOSR             0x0002
#define WM8731_SCR_SR_Msk           0x003C
#define WM8731_SCR_SR_Off           0x02
#define WM8731_SCR_CLKIDIV2         0x0040
#define WM8731_SCR_CLKODIV2         0x0080

extern int32_t wm8731_set_sampling(uint8_t mode, uint8_t bosr, uint8_t rate);
extern int32_t wm8731_set_core_clock_divider(uint8_t div2);
extern int32_t wm8731_set_clkout_divider(uint8_t div2);

// WM8731_ACR - Active Control Register

#define WM8731_ACR_ACTIVE           0x0001

extern int32_t wm8731_set_active(uint8_t active);

// WM8731_RR - Reset Register

#define WM8731_RR_RESET_Msk         0x01FF
#define WM8731_RR_RESET_Off         0x00

int32_t wm8731_reset(void);

#endif // __WM8731_H_
