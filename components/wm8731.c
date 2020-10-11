//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2015 Joe Ciccone
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

#include <stdio.h>
#include <system.h>
#include <types.h>
#include <wm8731.h>

// Local Register Values
uint16_t wm8731_llir  = WM8731_LLIR_Def;
uint16_t wm8731_rlir  = WM8731_RLIR_Def;
uint16_t wm8731_lhor  = WM8731_LHOR_Def;
uint16_t wm8731_rhor  = WM8731_RHOR_Def;
uint16_t wm8731_aapcr = WM8731_AAPCR_Def;
uint16_t wm8731_dapcr = WM8731_DAPCR_Def;
uint16_t wm8731_pdcr  = WM8731_PDCR_Def;
uint16_t wm8731_daifr = WM8731_DAIFR_Def;
uint16_t wm8731_scr   = WM8731_SCR_Def;
uint16_t wm8731_acr   = WM8731_ACR_Def;
uint16_t wm8731_rr    = WM8731_RR_Def;

int32_t wm8731_write(uint16_t reg) {
    // Write the 7-bit Register Value and 9-Bit Data Value
    uint8_t data[2] = { (reg >> 8) & 0xFF, reg & 0xFF };
    return twi_write(WM8731_TWI_ADDR, 0x00000000, data, 2);
}

// WM8731_LLIR - Left Line In Register

int32_t wm8731_set_linein_left_volume(uint8_t volume) {
    wm8731_llir = (wm8731_llir & ~WM8731_LLIR_LINVOL_Msk) |
        ((volume << WM8731_LLIR_LINVOL_Off) & WM8731_LLIR_LINVOL_Msk);
    return wm8731_write(wm8731_llir);
}

int32_t wm8731_set_linein_left_mute(uint8_t mute) {
    if (mute) {
        wm8731_llir |=  WM8731_LLIR_LINMUTE;
    } else {
        wm8731_llir &= ~WM8731_LLIR_LINMUTE;
    }
    return wm8731_write(wm8731_llir);
}

// WM8731_RLIR - Right Line In Register

int32_t wm8731_set_linein_right_volume(uint8_t volume) {
    wm8731_rlir = (wm8731_rlir & ~WM8731_RLIR_RINVOL_Msk) |
        ((volume << WM8731_RLIR_RINVOL_Off) & WM8731_RLIR_RINVOL_Msk);
    return wm8731_write(wm8731_rlir);
}

int32_t wm8731_set_linein_right_mute(uint8_t mute) {
    if (mute) {
        wm8731_rlir |=  WM8731_RLIR_RINMUTE;
    } else {
        wm8731_rlir &= ~WM8731_RLIR_RINMUTE;
    }
    return wm8731_write(wm8731_rlir);
}

// WM8731_LHOR - Left Headphone Output Register

int32_t wm8731_set_headphone_left_volume(uint8_t volume) {
    wm8731_lhor = (wm8731_lhor & ~WM8731_LHOR_LHPVOL_Msk) |
        ((volume << WM8731_LHOR_LHPVOL_Off) & WM8731_LHOR_LHPVOL_Msk);
    return wm8731_write(wm8731_lhor);
}

int32_t wm8731_set_headphone_left_zcen(uint8_t zcen) {
    if (zcen) {
        wm8731_lhor |=  WM8731_LHOR_LZCEN;
    } else {
        wm8731_lhor &= ~WM8731_LHOR_LZCEN;
    }
    return wm8731_write(wm8731_lhor);
}

// WM8731_RHOR - Right Headphone Output Register

int32_t wm8731_set_headphone_right_volume(uint8_t volume) {
    wm8731_rhor = (wm8731_rhor & ~WM8731_RHOR_RHPVOL_Msk) |
        ((volume << WM8731_RHOR_RHPVOL_Off) & WM8731_RHOR_RHPVOL_Msk);
    return wm8731_write(wm8731_rhor);
}

int32_t wm8731_set_headphone_right_zcen(uint8_t zcen) {
    if (zcen) {
        wm8731_rhor |=  WM8731_RHOR_RZCEN;
    } else {
        wm8731_rhor &= ~WM8731_RHOR_RZCEN;
    }
    return wm8731_write(wm8731_rhor);
}

// WM8731_AAPCR - Analogue Audio Path Control Register

int32_t wm8731_set_mic_boost(uint8_t enable) {
    if (enable) {
        wm8731_aapcr |=  WM8731_AAPCR_MICBOOST;
    } else {
        wm8731_aapcr &= ~WM8731_AAPCR_MICBOOST;
    }
    return wm8731_write(wm8731_aapcr);
}

int32_t wm8731_set_mic_mute(uint8_t mute) {
    if (mute) {
        wm8731_aapcr |=  WM8731_AAPCR_MUTEMIC;
    } else {
        wm8731_aapcr &= ~WM8731_AAPCR_MUTEMIC;
    }
    return wm8731_write(wm8731_aapcr);
}

int32_t wm8731_set_input_select(uint8_t input) {
    if (input) {
        wm8731_aapcr |=  WM8731_AAPCR_INSEL;
    } else {
        wm8731_aapcr &= ~WM8731_AAPCR_INSEL;
    }
    return wm8731_write(wm8731_aapcr);
}

int32_t wm8731_set_bypass(uint8_t enable) {
    if (enable) {
        wm8731_aapcr |=  WM8731_AAPCR_BYPASS;
    } else {
        wm8731_aapcr &= ~WM8731_AAPCR_BYPASS;
    }
    return wm8731_write(wm8731_aapcr);
}

int32_t wm8731_set_dac_select(uint8_t dac) {
    if (dac) {
        wm8731_aapcr |=  WM8731_AAPCR_DACSEL;
    } else {
        wm8731_aapcr &= ~WM8731_AAPCR_DACSEL;
    }
    return wm8731_write(wm8731_aapcr);
}

int32_t wm8731_set_side_tone_enable(uint8_t enable) {
    if (enable) {
        wm8731_aapcr |=  WM8731_AAPCR_SIDETONE;
    } else {
        wm8731_aapcr &= ~WM8731_AAPCR_SIDETONE;
    }
    return wm8731_write(wm8731_aapcr);
}

int32_t wm8731_set_side_tone_attenuation(uint8_t att) {
    wm8731_aapcr = (wm8731_aapcr & ~WM8731_AAPCR_SIDEATT_Msk) |
        ((att << WM8731_AAPCR_SIDEATT_Off) & WM8731_AAPCR_SIDEATT_Msk);
    return wm8731_write(wm8731_aapcr);
}

// WM8731_DAPCR - Digital Audio Path Control Register

int32_t wm8731_set_adc_highpass_filter(uint8_t enable) {
    if (enable) {
        wm8731_dapcr |=  WM8731_DAPCR_ADCHPD;
    } else {
        wm8731_dapcr &= ~WM8731_DAPCR_ADCHPD;
    }
    return wm8731_write(wm8731_dapcr);
}

int32_t wm8731_set_deemphasis(uint8_t deemph) {
    wm8731_dapcr = (wm8731_dapcr & ~WM8731_DAPCR_DEEMPH_Msk) |
        ((deemph << WM8731_DAPCR_DEEMPH_Off) & WM8731_DAPCR_DEEMPH_Msk);
    return wm8731_write(wm8731_dapcr);
}

int32_t wm8731_set_dac_soft_mute(uint8_t mute) {
    if (mute) {
        wm8731_dapcr |=  WM8731_DAPCR_DACMU;
    } else {
        wm8731_dapcr &= ~WM8731_DAPCR_DACMU;
    }
    return wm8731_write(wm8731_dapcr);
}

int32_t wm8731_set_store_dc_offset(uint8_t enable) {
    if (enable) {
        wm8731_dapcr |=  WM8731_DAPCR_HPOR;
    } else {
        wm8731_dapcr &= ~WM8731_DAPCR_HPOR;
    }
    return wm8731_write(wm8731_dapcr);
}

// WM8731_PDCR - Power Down Control Register

int32_t wm8731_set_powerdown_linein(uint8_t pd_linein) {
    if (pd_linein) {
        wm8731_pdcr |=  WM8731_PDCR_LINEINPD;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_LINEINPD;
    }
    return wm8731_write(wm8731_pdcr);
}

int32_t wm8731_set_powerdown_mic(uint8_t pd_mic) {
    if (pd_mic) {
        wm8731_pdcr |=  WM8731_PDCR_MICPD;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_MICPD;
    }
    return wm8731_write(wm8731_pdcr);
}

int32_t wm8731_set_powerdown_adc(uint8_t pd_adc) {
    if (pd_adc) {
        wm8731_pdcr |=  WM8731_PDCR_ADCPD;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_ADCPD;
    }
    return wm8731_write(wm8731_pdcr);
}

int32_t wm8731_set_powerdown_dac(uint8_t pd_dac) {
    if (pd_dac) {
        wm8731_pdcr |=  WM8731_PDCR_DACPD;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_DACPD;
    }
    return wm8731_write(wm8731_pdcr);
}

int32_t wm8731_set_powerdown_out(uint8_t pd_out) {
    if (pd_out) {
        wm8731_pdcr |=  WM8731_PDCR_OUTPD;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_OUTPD;
    }
    return wm8731_write(wm8731_pdcr);
}

int32_t wm8731_set_powerdown_osc(uint8_t pd_osc) {
    if (pd_osc) {
        wm8731_pdcr |=  WM8731_PDCR_OSCPD;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_OSCPD;
    }
    return wm8731_write(wm8731_pdcr);
}

int32_t wm8731_set_powerdown_clkout(uint8_t pd_clkout) {
    if (pd_clkout) {
        wm8731_pdcr |=  WM8731_PDCR_CLKOUTPD;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_CLKOUTPD;
    }
    return wm8731_write(wm8731_pdcr);
}

int32_t wm8731_set_powerdown_poweroff(uint8_t poweroff) {
    if (poweroff) {
        wm8731_pdcr |=  WM8731_PDCR_POWEROFF;
    } else {
        wm8731_pdcr &= ~WM8731_PDCR_POWEROFF;
    }
    return wm8731_write(wm8731_pdcr);
}

// WM8731_DAIFR - Digital Audio Interface Format Register

int32_t wm8731_set_digital_audio_format(uint8_t format) {
    wm8731_daifr = (wm8731_daifr & ~WM8731_DAIFR_FORMAT_Msk) |
        ((format << WM8731_DAIFR_FORMAT_Off) & WM8731_DAIFR_FORMAT_Msk);
    return wm8731_write(wm8731_daifr);
}

int32_t wm8731_set_digital_audio_data_bit_length(uint8_t len) {
    wm8731_daifr = (wm8731_daifr & ~WM8731_DAIFR_IWL_Msk) |
        ((len << WM8731_DAIFR_IWL_Off) & WM8731_DAIFR_IWL_Msk);
    return wm8731_write(wm8731_daifr);
}

int32_t wm8731_set_dac_lrp(uint8_t phase) {
    if (phase) {
        wm8731_daifr |=  WM8731_DAIFR_LRP;
    } else {
        wm8731_daifr &= ~WM8731_DAIFR_LRP;
    }
    return wm8731_write(wm8731_daifr);
}

int32_t wm8731_set_dac_lrswap(uint8_t swap) {
    if (swap) {
        wm8731_daifr |=  WM8731_DAIFR_LRSWAP;
    } else {
        wm8731_daifr &= ~WM8731_DAIFR_LRSWAP;
    }
    return wm8731_write(wm8731_daifr);
}

int32_t wm8731_set_ms_mode(uint8_t msmode) {
    if (msmode) {
        wm8731_daifr |=  WM8731_DAIFR_MS;
    } else {
        wm8731_daifr &= ~WM8731_DAIFR_MS;
    }
    return wm8731_write(wm8731_daifr);
}

int32_t wm8731_set_bit_clk_invert(uint8_t bclkinv) {
    if (bclkinv) {
        wm8731_daifr |=  WM8731_DAIFR_BCLKINV;
    } else {
        wm8731_daifr &= ~WM8731_DAIFR_BCLKINV;
    }
    return wm8731_write(wm8731_daifr);
}

// WM8731_SCR - Sampling Control Register

int32_t wm8731_set_sampling(uint8_t mode, uint8_t bosr, uint8_t rate) {
    if (mode) {
        wm8731_scr |=  WM8731_SCR_USB;
    } else {
        wm8731_scr &= ~WM8731_SCR_USB;
    }
    if (bosr) {
        wm8731_scr |=  WM8731_SCR_BOSR;
    } else {
        wm8731_scr &= ~WM8731_SCR_BOSR;
    }
    wm8731_scr = (wm8731_scr & ~WM8731_SCR_SR_Msk) |
        ((rate << WM8731_SCR_SR_Off) & WM8731_SCR_SR_Msk);
    return wm8731_write(wm8731_scr);
}

int32_t wm8731_set_core_clock_divider(uint8_t div2) {
    if (div2) {
        wm8731_scr |=  WM8731_SCR_CLKIDIV2;
    } else {
        wm8731_scr &= ~WM8731_SCR_CLKIDIV2;
    }
    return wm8731_write(wm8731_scr);
}

int32_t wm8731_set_clkout_divider(uint8_t div2) {
    if (div2) {
        wm8731_scr |=  WM8731_SCR_CLKODIV2;
    } else {
        wm8731_scr &= ~WM8731_SCR_CLKODIV2;
    }
    return wm8731_write(wm8731_scr);
}

// WM8731_ACR - Active Control Register

int32_t wm8731_set_active(uint8_t active) {
    if (active) {
        wm8731_acr |=  WM8731_ACR_ACTIVE;
    } else {
        wm8731_acr &= ~WM8731_ACR_ACTIVE;
    }
    return wm8731_write(wm8731_acr);
}

// WM8731_RR - Reset Register

int32_t wm8731_reset(void) {
    // Reset Local Registers to Default State
    wm8731_llir  = WM8731_LLIR_Def;
    wm8731_rlir  = WM8731_RLIR_Def;
    wm8731_lhor  = WM8731_LHOR_Def;
    wm8731_rhor  = WM8731_RHOR_Def;
    wm8731_aapcr = WM8731_AAPCR_Def;
    wm8731_dapcr = WM8731_DAPCR_Def;
    wm8731_pdcr  = WM8731_PDCR_Def;
    wm8731_daifr = WM8731_DAIFR_Def;
    wm8731_scr   = WM8731_SCR_Def;
    wm8731_acr   = WM8731_ACR_Def;
    wm8731_rr    = WM8731_RR_Def;

    // Write the Reset Register
    return wm8731_write(wm8731_rr);
}
