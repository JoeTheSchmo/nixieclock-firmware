/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _WM8731_H_
#define _WM8731_H_

#include <stdint.h>

/**
 * Register Definitions
 */

#define WM8731_LLIR  0x00
#define WM8731_RLIR  0x01
#define WM8731_LHOR  0x02
#define WM8731_RHOR  0x03
#define WM8731_AAPCR 0x04
#define WM8731_DAPCR 0x05
#define WM8731_PDCR  0x06
#define WM8731_DAIFR 0x07
#define WM8731_SCR   0x08
#define WM8731_ACR   0x09
#define WM8731_RR    0x0F

// LLIR

#define WM8731_LLIR_LINVOL(v) (((v) & 0x1F) << 0)
#define WM8731_LLIR_LINVOL_Pos (0)
#define WM8731_LLIR_LINVOL_Len (5)
#define WM8731_LLIR_LINVOL_Msk (0x1F << 0)

#define WM8731_LLIR_MUTE     (0x01 << 7)
#define WM8731_LLIR_MUTE_Pos (7)
#define WM8731_LLIR_MUTE_Len (1)
#define WM8731_LLIR_MUTE_Msk (0x01 << 7)

#define WM8731_LLIR_LRINBOTH     (0x01 << 8)
#define WM8731_LLIR_LRINBOTH_Pos (8)
#define WM8731_LLIR_LRINBOTH_Len (1)
#define WM8731_LLIR_LRINBOTH_Msk (0x01 << 8)

// RLIR

#define WM8731_RLIR_LINVOL(v) (((v) & 0x1F) << 0)
#define WM8731_RLIR_LINVOL_Pos (0)
#define WM8731_RLIR_LINVOL_Len (5)
#define WM8731_RLIR_LINVOL_Msk (0x1F << 0)

#define WM8731_RLIR_MUTE     (0x01 << 7)
#define WM8731_RLIR_MUTE_Pos (7)
#define WM8731_RLIR_MUTE_Len (1)
#define WM8731_RLIR_MUTE_Msk (0x01 << 7)

#define WM8731_RLIR_LRINBOTH     (0x01 << 8)
#define WM8731_RLIR_LRINBOTH_Pos (8)
#define WM8731_RLIR_LRINBOTH_Len (1)
#define WM8731_RLIR_LRINBOTH_Msk (0x01 << 8)

// LHOR

#define WM8731_LHOR_LHPVOL(v) (((v) & 0x7F) << 0)
#define WM8731_LHOR_LHPVOL_Pos (0)
#define WM8731_LHOR_LHPVOL_Len (7)
#define WM8731_LHOR_LHPVOL_Msk (0x7F << 0)

#define WM8731_LHOR_LZCEN     (0x01 << 7)
#define WM8731_LHOR_LZCEN_Pos (7)
#define WM8731_LHOR_LZCEN_Len (1)
#define WM8731_LHOR_LZCEN_Msk (0x01 << 7)

#define WM8731_LHOR_LRHPBOTH     (0x01 << 8)
#define WM8731_LHOR_LRHPBOTH_Pos (8)
#define WM8731_LHOR_LRHPBOTH_Len (1)
#define WM8731_LHOR_LRHPBOTH_Msk (0x01 << 8)

// RHOR

#define WM8731_RHOR_RHPVOL(v) (((v) & 0x7F) << 0)
#define WM8731_RHOR_RHPVOL_Pos (0)
#define WM8731_RHOR_RHPVOL_Len (7)
#define WM8731_RHOR_RHPVOL_Msk (0x7F << 0)

#define WM8731_RHOR_RZCEN     (0x01 << 7)
#define WM8731_RHOR_RZCEN_Pos (7)
#define WM8731_RHOR_RZCEN_Len (1)
#define WM8731_RHOR_RZCEN_Msk (0x01 << 7)

#define WM8731_RHOR_RRHPBOTH     (0x01 << 8)
#define WM8731_RHOR_RRHPBOTH_Pos (8)
#define WM8731_RHOR_RRHPBOTH_Len (1)
#define WM8731_RHOR_RRHPBOTH_Msk (0x01 << 8)

// AAPCR

#define WM8731_AAPCR_MICBOOST     (0x01 << 0)
#define WM8731_AAPCR_MICBOOST_Pos (0)
#define WM8731_AAPCR_MICBOOST_Len (1)
#define WM8731_AAPCR_MICBOOST_Msk (0x01 << 0)

#define WM8731_AAPCR_MUTEMIC     (0x01 << 1)
#define WM8731_AAPCR_MUTEMIC_Pos (1)
#define WM8731_AAPCR_MUTEMIC_Len (1)
#define WM8731_AAPCR_MUTEMIC_Msk (0x01 << 1)

#define WM8731_AAPCR_INSEL     (0x01 << 2)
#define WM8731_AAPCR_INSEL_Pos (2)
#define WM8731_AAPCR_INSEL_Len (1)
#define WM8731_AAPCR_INSEL_Msk (0x01 << 2)

#define WM8731_AAPCR_BYPASS     (0x01 << 3)
#define WM8731_AAPCR_BYPASS_Pos (3)
#define WM8731_AAPCR_BYPASS_Len (1)
#define WM8731_AAPCR_BYPASS_Msk (0x01 << 3)

#define WM8731_AAPCR_DACSEL     (0x01 << 4)
#define WM8731_AAPCR_DACSEL_Pos (4)
#define WM8731_AAPCR_DACSEL_Len (1)
#define WM8731_AAPCR_DACSEL_Msk (0x01 << 4)

#define WM8731_AAPCR_SIDETONE     (0x01 << 5)
#define WM8731_AAPCR_SIDETONE_Pos (5)
#define WM8731_AAPCR_SIDETONE_Len (1)
#define WM8731_AAPCR_SIDETONE_Msk (0x01 << 5)

#define WM8731_AAPCR_SIDEATT(v)  (((v) & 0x03) << 6)
#define WM8731_AAPCR_SIDEATT_Pos (6)
#define WM8731_AAPCR_SIDEATT_Len (2)
#define WM8731_AAPCR_SIDEATT_Msk (0x03 << 6)

// DAPCR

#define WM8731_DAPCR_ADCHPD     (0x01 << 0)
#define WM8731_DAPCR_ADCHPD_Pos (0)
#define WM8731_DAPCR_ADCHPD_Len (1)
#define WM8731_DAPCR_ADCHPD_Msk (0x01 << 0)

#define WM8731_DAPCR_DEEMPH(v)  (((v) & 0x03) << 1)
#define WM8731_DAPCR_DEEMPH_Pos (1)
#define WM8731_DAPCR_DEEMPH_Len (2)
#define WM8731_DAPCR_DEEMPH_Msk (0x03 << 1)

#define WM8731_DAPCR_DACMU     (0x01 << 4)
#define WM8731_DAPCR_DACMU_Pos (3)
#define WM8731_DAPCR_DACMU_Len (1)
#define WM8731_DAPCR_DACMU_Msk (0x01 << 3)

#define WM8731_DAPCR_HPOR     (0x01 << 4)
#define WM8731_DAPCR_HPOR_Pos (4)
#define WM8731_DAPCR_HPOR_Len (1)
#define WM8731_DAPCR_HPOR_Msk (0x01 << 4)

// PDCR

#define WM8731_PDCR_LINEINPD     (0x01 << 0)
#define WM8731_PDCR_LINEINPD_Pos (0)
#define WM8731_PDCR_LINEINPD_Len (1)
#define WM8731_PDCR_LINEINPD_Msk (0x01 << 0)

#define WM8731_PDCR_MICPD     (0x01 << 1)
#define WM8731_PDCR_MICPD_Pos (1)
#define WM8731_PDCR_MICPD_Len (1)
#define WM8731_PDCR_MICPD_Msk (0x01 << 1)

#define WM8731_PDCR_ADCPD     (0x01 << 2)
#define WM8731_PDCR_ADCPD_Pos (2)
#define WM8731_PDCR_ADCPD_Len (1)
#define WM8731_PDCR_ADCPD_Msk (0x01 << 2)

#define WM8731_PDCR_DACPD     (0x01 << 3)
#define WM8731_PDCR_DACPD_Pos (3)
#define WM8731_PDCR_DACPD_Len (1)
#define WM8731_PDCR_DACPD_Msk (0x01 << 3)

#define WM8731_PDCR_OUTPD     (0x01 << 4)
#define WM8731_PDCR_OUTPD_Pos (4)
#define WM8731_PDCR_OUTPD_Len (1)
#define WM8731_PDCR_OUTPD_Msk (0x01 << 4)

#define WM8731_PDCR_OSCPD     (0x01 << 5)
#define WM8731_PDCR_OSCPD_Pos (5)
#define WM8731_PDCR_OSCPD_Len (1)
#define WM8731_PDCR_OSCPD_Msk (0x01 << 5)

#define WM8731_PDCR_CLKOUTPD     (0x01 << 6)
#define WM8731_PDCR_CLKOUTPD_Pos (6)
#define WM8731_PDCR_CLKOUTPD_Len (1)
#define WM8731_PDCR_CLKOUTPD_Msk (0x01 << 6)

#define WM8731_PDCR_POWEROFF     (0x01 << 7)
#define WM8731_PDCR_POWEROFF_Pos (7)
#define WM8731_PDCR_POWEROFF_Len (1)
#define WM8731_PDCR_POWEROFF_Msk (0x01 << 7)

// DAIFR

#define WM8731_DAIFR_FORMAT(v)  (((v) & 0x03) << 0)
#define WM8731_DAIFR_FORMAT_Pos (0)
#define WM8731_DAIFR_FORMAT_Len (2)
#define WM8731_DAIFR_FORMAT_Msk (0x03 << 0)

#define WM8731_DAIFR_IWL(v)  (((v) & 0x03) << 2)
#define WM8731_DAIFR_IWL_Pos (2)
#define WM8731_DAIFR_IWL_Len (2)
#define WM8731_DAIFR_IWL_Msk (0x03 << 2)

#define WM8731_DAIFR_LRP     (0x01 << 4)
#define WM8731_DAIFR_LRP_Pos (4)
#define WM8731_DAIFR_LRP_Len (1)
#define WM8731_DAIFR_LRP_Msk (0x01 << 4)

#define WM8731_DAIFR_LRSWAP     (0x01 << 5)
#define WM8731_DAIFR_LRSWAP_Pos (5)
#define WM8731_DAIFR_LRSWAP_Len (1)
#define WM8731_DAIFR_LRSWAP_Msk (0x01 << 5)

#define WM8731_DAIFR_MS     (0x01 << 6)
#define WM8731_DAIFR_MS_Pos (6)
#define WM8731_DAIFR_MS_Len (1)
#define WM8731_DAIFR_MS_Msk (0x01 << 6)

#define WM8731_DAIFR_BCLKINV     (0x01 << 7)
#define WM8731_DAIFR_BCLKINV_Pos (7)
#define WM8731_DAIFR_BCLKINV_Len (1)
#define WM8731_DAIFR_BCLKINV_Msk (0x01 << 7)

// SCR

#define WM8731_SCR_USB     (0x01 << 0)
#define WM8731_SCR_USB_Pos (0)
#define WM8731_SCR_USB_Len (1)
#define WM8731_SCR_USB_Msk (0x01 << 0)

#define WM8731_SCR_BOSR     (0x01 << 1)
#define WM8731_SCR_BOSR_Pos (1)
#define WM8731_SCR_BOSR_Len (1)
#define WM8731_SCR_BOSR_Msk (0x01 << 0)

#define WM8731_SCR_SR(v)  (((v) & 0xF) << 2)
#define WM8731_SCR_SR_Pos (2)
#define WM8731_SCR_SR_Len (4)
#define WM8731_SCR_SR_Msk (0xF << 2)

#define WM8731_SCR_CLKIDIV2     (0x01 << 6)
#define WM8731_SCR_CLKIDIV2_Pos (6)
#define WM8731_SCR_CLKIDIV2_Len (1)
#define WM8731_SCR_CLKIDIV2_Msk (0x01 << 6)

#define WM8731_SCR_CLKODIV2     (0x01 << 7)
#define WM8731_SCR_CLKODIV2_Pos (7)
#define WM8731_SCR_CLKODIV2_Len (1)
#define WM8731_SCR_CLKODIV2_Msk (0x01 << 7)

// ACR

#define WM8731_ACR_ACTIVE     (0x01 << 0)
#define WM8731_ACR_ACTIVE_Pos (0)
#define WM8731_ACR_ACTIVE_Len (1)
#define WM8731_ACR_ACTIVE_Msk (0x01 << 0)

// RR

#define WM8731_RR_RESET     (0x00 << 0)
#define WM8731_RR_RESET_Pos (0)
#define WM8731_RR_RESET_Len (8)
#define WM8731_RR_RESET_Msk (0xFF << 0)

/**
 * Function Prototypes
 */

// Communication Functions
extern inline int32_t wm8731_write_register(uint8_t reg, uint16_t value);

// Line In Commands
extern int32_t wm8731_set_linein_left_volume(uint8_t volume);
extern int32_t wm8731_set_linein_left_mute(uint8_t mute);
extern int32_t wm8731_set_linein_right_volume(uint8_t volume);
extern int32_t wm8731_set_linein_right_mute(uint8_t mute);

// Headphone Commands
extern int32_t wm8731_set_headphone_left_volume(uint8_t volume);
extern int32_t wm8731_set_headphone_left_zcen(uint8_t zcen);
extern int32_t wm8731_set_headphone_right_volume(uint8_t volume);
extern int32_t wm8731_set_headphone_right_zcen(uint8_t zcen);

// Analogue Audio Path Control
extern int32_t wm8731_set_mic_boost(uint8_t enable);
extern int32_t wm8731_set_mic_mute(uint8_t mute);
extern int32_t wm8731_set_input_select(uint8_t input);
extern int32_t wm8731_set_bypass(uint8_t enable);
extern int32_t wm8731_set_dac_select(uint8_t dac);
extern int32_t wm8731_set_side_tone_enable(uint8_t enable);
extern int32_t wm8731_set_side_tone_attenuation(uint8_t att);

// Digital Audio Path Control
extern int32_t wm8731_set_adc_highpass_filter(uint8_t enable);
extern int32_t wm8731_set_deemphasis(uint8_t deemph);
extern int32_t wm8731_set_dac_soft_mute(uint8_t mute);
extern int32_t wm8731_set_store_dc_offset(uint8_t enable);

// Power Down Control
extern int32_t wm8731_set_powerdown_linein(uint8_t pd_linein);
extern int32_t wm8731_set_powerdown_mic(uint8_t pd_mic);
extern int32_t wm8731_set_powerdown_adc(uint8_t pd_adc);
extern int32_t wm8731_set_powerdown_dac(uint8_t pd_dac);
extern int32_t wm8731_set_powerdown_out(uint8_t pd_out);
extern int32_t wm8731_set_powerdown_osc(uint8_t pd_osc);
extern int32_t wm8731_set_powerdown_clkout(uint8_t pd_clkout);
extern int32_t wm8731_set_powerdown_poweroff(uint8_t poweroff);

// Digital Audio Interface Control
extern int32_t wm8731_set_digital_audio_format(uint8_t format);
extern int32_t wm8731_set_digital_audio_data_bit_length(uint8_t len);
extern int32_t wm8731_set_dac_lrp(uint8_t phase);
extern int32_t wm8731_set_dac_lrswap(uint8_t swap);
extern int32_t wm8731_set_ms_mode(uint8_t msmode);
extern int32_t wm8731_set_bit_clk_invert(uint8_t bclkinv);

// Sampling Control
extern int32_t wm8731_set_usb_mode(uint8_t mode);
extern int32_t wm8731_set_sampling(uint8_t mode, uint8_t bosr, uint8_t rate);
extern int32_t wm8731_set_core_clock_divider(uint8_t div2);
extern int32_t wm8731_set_clkout_divider(uint8_t div2);

// Active Control
extern int32_t wm8731_set_active(uint8_t active);

// Reset
extern int32_t wm8731_reset();

#endif // _WM8731_H_
