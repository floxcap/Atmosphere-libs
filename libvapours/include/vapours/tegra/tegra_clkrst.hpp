/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <vapours/common.hpp>
#include <vapours/assert.hpp>
#include <vapours/literals.hpp>
#include <vapours/util.hpp>
#include <vapours/results.hpp>
#include <vapours/reg.hpp>

/* Clock source enums. */
#define CLK_RST_REG_BITS_MASK(NAME)                                      REG_NAMED_BITS_MASK    (CLK_RST_CONTROLLER, NAME)
#define CLK_RST_REG_BITS_VALUE(NAME, VALUE)                              REG_NAMED_BITS_VALUE   (CLK_RST_CONTROLLER, NAME, VALUE)
#define CLK_RST_REG_BITS_ENUM(NAME, ENUM)                                REG_NAMED_BITS_ENUM    (CLK_RST_CONTROLLER, NAME, ENUM)
#define CLK_RST_REG_BITS_ENUM_SEL(NAME, __COND__, TRUE_ENUM, FALSE_ENUM) REG_NAMED_BITS_ENUM_SEL(CLK_RST_CONTROLLER, NAME, __COND__, TRUE_ENUM, FALSE_ENUM)

#define DEFINE_CLK_RST_REG(NAME, __OFFSET__, __WIDTH__)                                                                                                                  REG_DEFINE_NAMED_REG           (CLK_RST_CONTROLLER, NAME, __OFFSET__, __WIDTH__)
#define DEFINE_CLK_RST_REG_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE)                                                                                                         REG_DEFINE_NAMED_BIT_ENUM      (CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE)
#define DEFINE_CLK_RST_REG_TWO_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE)                                                                                         REG_DEFINE_NAMED_TWO_BIT_ENUM  (CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE, TWO, THREE)
#define DEFINE_CLK_RST_REG_THREE_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)                                                               REG_DEFINE_NAMED_THREE_BIT_ENUM(CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)
#define DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN) REG_DEFINE_NAMED_FOUR_BIT_ENUM (CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN)


#define CLK_RST_CONTROLLER_RST_SOURCE            (0x000)

#define CLK_RST_CONTROLLER_SCLK_BURST_POLICY     (0x028)
#define CLK_RST_CONTROLLER_SUPER_SCLK_DIVIDER    (0x02C)
#define CLK_RST_CONTROLLER_CLK_SYSTEM_RATE       (0x030)
#define CLK_RST_CONTROLLER_MISC_CLK_ENB          (0x048)
#define CLK_RST_CONTROLLER_OSC_CTRL              (0x050)
#define CLK_RST_CONTROLLER_PLLC_BASE             (0x080)
#define CLK_RST_CONTROLLER_PLLC_OUT              (0x084)
#define CLK_RST_CONTROLLER_PLLC_MISC             (0x088)
#define CLK_RST_CONTROLLER_PLLC_MISC1            (0x08C)
#define CLK_RST_CONTROLLER_PLLM_BASE             (0x090)
#define CLK_RST_CONTROLLER_PLLM_MISC1            (0x098)
#define CLK_RST_CONTROLLER_PLLM_MISC2            (0x09C)
#define CLK_RST_CONTROLLER_PLLD_BASE             (0x0D0)
#define CLK_RST_CONTROLLER_PLLD_MISC1            (0x0D8)
#define CLK_RST_CONTROLLER_PLLD_MISC             (0x0DC)
#define CLK_RST_CONTROLLER_PLLX_BASE             (0x0E0)
#define CLK_RST_CONTROLLER_PLLX_MISC             (0x0E4)
#define CLK_RST_CONTROLLER_CCLKG_BURST_POLICY    (0x368)
#define CLK_RST_CONTROLLER_SUPER_CCLKG_DIVIDER   (0x36C)
#define CLK_RST_CONTROLLER_CCLKLP_BURST_POLICY   (0x370)
#define CLK_RST_CONTROLLER_SUPER_CCLKLP_DIVIDER  (0x374)
#define CLK_RST_CONTROLLER_CPU_SOFTRST_CTRL2     (0x388)
#define CLK_RST_CONTROLLER_SPARE_REG0            (0x55C)
#define CLK_RST_CONTROLLER_PLLC4_BASE            (0x5A4)
#define CLK_RST_CONTROLLER_PLLC_MISC2            (0x5D0)
#define CLK_RST_CONTROLLER_PLLMB_BASE            (0x5E8)

#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRA (0x0F8)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRB (0x0FC)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRC (0x3A0)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRD (0x3A4)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRE (0x554)

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(SCLK_BURST_POLICY_SWAKEUP_IDLE_SOURCE,  0, CLKM, PLLC_OUT1, PLLC4_OUT3PLLP_OUT4, PLLP_OUT0, PLLP_OUT2, PLLC4_OUT1PLLC_OUT0, CLK_SCLKS, PLLC4_OUT2);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(SCLK_BURST_POLICY_SWAKEUP_RUN_SOURCE,   4, CLKM, PLLC_OUT1, PLLC4_OUT3PLLP_OUT4, PLLP_OUT0, PLLP_OUT2, PLLC4_OUT1PLLC_OUT0, CLK_SCLKS, PLLC4_OUT2);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(SCLK_BURST_POLICY_SWAKEUP_IRQ_SOURCE,   8, CLKM, PLLC_OUT1, PLLC4_OUT3PLLP_OUT4, PLLP_OUT0, PLLP_OUT2, PLLC4_OUT1PLLC_OUT0, CLK_SCLKS, PLLC4_OUT2);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(SCLK_BURST_POLICY_SWAKEUP_FIQ_SOURCE,  12, CLKM, PLLC_OUT1, PLLC4_OUT3PLLP_OUT4, PLLP_OUT0, PLLP_OUT2, PLLC4_OUT1PLLC_OUT0, CLK_SCLKS, PLLC4_OUT2);
DEFINE_CLK_RST_REG_BIT_ENUM(SCLK_BURST_POLICY_CPU_AUTO_SWAKEUP_FROM_IRQ, 24, NOP, BURST);
DEFINE_CLK_RST_REG_BIT_ENUM(SCLK_BURST_POLICY_COP_AUTO_SWAKEUP_FROM_IRQ, 25, NOP, BURST);
DEFINE_CLK_RST_REG_BIT_ENUM(SCLK_BURST_POLICY_CPU_AUTO_SWAKEUP_FROM_FIQ, 26, NOP, BURST);
DEFINE_CLK_RST_REG_BIT_ENUM(SCLK_BURST_POLICY_COP_AUTO_SWAKEUP_FROM_FIQ, 27, NOP, BURST);
DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(SCLK_BURST_POLICY_SYS_STATE, 28, STDBY, IDLE, RUN, RSVD3, IRQ, RSVD5, RSVD6, RSVD7, FIQ, RSVD9, RSVD10, RSVD11, RSVD12, RSVD13, RSVD14, RSVD15);

DEFINE_CLK_RST_REG(SUPER_SCLK_DIVIDER_SUPER_SDIV_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG(SUPER_SCLK_DIVIDER_SUPER_SDIV_DIVIDEND, 8, 8);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_SCLK_DIVIDER_SUPER_SDIV_DIS_FROM_CPU_IRQ, 24, NOP, DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_SCLK_DIVIDER_SUPER_SDIV_DIS_FROM_COP_IRQ, 25, NOP, DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_SCLK_DIVIDER_SUPER_SDIV_DIS_FROM_CPU_FIQ, 26, NOP, DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_SCLK_DIVIDER_SUPER_SDIV_DIS_FROM_COP_FIQ, 27, NOP, DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_SCLK_DIVIDER_SUPER_SDIV_ENB, 31, DISABLE, ENABLE);

DEFINE_CLK_RST_REG(CLK_SYSTEM_RATE_APB_RATE, 0, 2);
DEFINE_CLK_RST_REG(CLK_SYSTEM_RATE_PCLK_DIS, 3, 1);
DEFINE_CLK_RST_REG(CLK_SYSTEM_RATE_AHB_RATE, 4, 2);
DEFINE_CLK_RST_REG(CLK_SYSTEM_RATE_HCLK_DIS, 7, 1);

DEFINE_CLK_RST_REG(MISC_CLK_ENB_CFG_ALL_VISIBLE, 28, 1);

DEFINE_CLK_RST_REG_BIT_ENUM(OSC_CTRL_XOE, 0, DISABLE, ENABLE);
DEFINE_CLK_RST_REG(OSC_CTRL_XOFS, 4, 6);
DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(OSC_CTRL_OSC_FREQ, 28, OSC13, OSC16P8, RSVD2, RSVD3, OSC19P2, OSC38P4, RSVD6, RSVD7, OSC12, OSC48, RSVD10, RSVD11, OSC26, RSVD13, RSVD14, RSVD15);

DEFINE_CLK_RST_REG(PLLC_BASE_PLLC_DIVM, 0, 8);
DEFINE_CLK_RST_REG(PLLC_BASE_PLLC_DIVN, 10, 8);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC_BASE_PLLC_LOCK, 27, NOT_LOCK, LOCK);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC_BASE_PLLC_REF_DIS, 29, REF_ENABLE, REF_DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC_BASE_PLLC_ENABLE, 30, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC_BASE_PLLC_BYPASS, 31, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(PLLC_OUT_PLLC_OUT1_RSTN, 0, RESET_ENABLE, RESET_DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC_OUT_PLLC_OUT1_CLKEN, 1, DISABLE, ENABLE);
DEFINE_CLK_RST_REG(PLLC_OUT_PLLC_OUT1_RATIO, 8, 8);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC_OUT_PLLC_OUT1_DIV_BYP, 16, DISABLE, ENABLE);

DEFINE_CLK_RST_REG(PLLM_BASE_PLLM_DIVM, 0, 8);
DEFINE_CLK_RST_REG(PLLM_BASE_PLLM_DIVN, 8, 8);
DEFINE_CLK_RST_REG(PLLM_BASE_PLLM_DIVP, 20, 5);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLM_BASE_PLLM_LOCK, 27, NOT_LOCK, LOCK);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLM_BASE_PLLM_REF_DIS, 29, REF_ENABLE, REF_DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLM_BASE_PLLM_ENABLE, 30, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLM_BASE_PLLM_BYPASSPLL, 31, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(PLLM_MISC2_PLLM_EN_LCKDET, 4, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(PLLD_BASE_CSI_CLK_SRC,  23, BRICK, PLL_D);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLD_BASE_PLLD_REF_DIS, 29, REF_ENABLE, REF_DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLD_BASE_PLLD_ENABLE,  30, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLD_BASE_PLLD_BYPASS,  31, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(PLLX_BASE_PLLX_ENABLE, 30, DISABLE, ENABLE);

DEFINE_CLK_RST_REG(SUPER_CCLK_DIVIDER_SUPER_CDIV_DIVISOR,  0, 8);
DEFINE_CLK_RST_REG(SUPER_CCLK_DIVIDER_SUPER_CDIV_DIVIDEND, 8, 8);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_CCLK_DIVIDER_SUPER_CDIV_DIS_FROM_CPU_IRQ, 24, NO_IMPACT, DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_CCLK_DIVIDER_SUPER_CDIV_DIS_FROM_COP_IRQ, 25, NO_IMPACT, DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_CCLK_DIVIDER_SUPER_CDIV_DIS_FROM_CPU_FIQ, 26, NO_IMPACT, DISABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_CCLK_DIVIDER_SUPER_CDIV_DIS_FROM_COP_FIQ, 27, NO_IMPACT, DISABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_CCLKG_DIVIDER_SUPER_CDIV_ENB, 31, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(SUPER_CCLKLP_DIVIDER_SUPER_CDIV_ENB, 31, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(CCLK_BURST_POLICY_CWAKEUP_IDLE_SOURCE,  0, CLKM, RSVD1, CLKS, RSVD3, PLLP_OUT0, PLLP_OUT4, RSVD6, RSVD7, PLLX_OUT0_LJ, DVFS_CPU_CLK, RSVD10, RSVD11, RSVD12, RSVD13, PLLX_OUT0, DVFS_CPU_CLK_LJ);
DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(CCLK_BURST_POLICY_CWAKEUP_RUN_SOURCE,   4, CLKM, RSVD1, CLKS, RSVD3, PLLP_OUT0, PLLP_OUT4, RSVD6, RSVD7, PLLX_OUT0_LJ, DVFS_CPU_CLK, RSVD10, RSVD11, RSVD12, RSVD13, PLLX_OUT0, DVFS_CPU_CLK_LJ);
DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(CCLK_BURST_POLICY_CWAKEUP_IRQ_SOURCE,   8, CLKM, RSVD1, CLKS, RSVD3, PLLP_OUT0, PLLP_OUT4, RSVD6, RSVD7, PLLX_OUT0_LJ, DVFS_CPU_CLK, RSVD10, RSVD11, RSVD12, RSVD13, PLLX_OUT0, DVFS_CPU_CLK_LJ);
DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(CCLK_BURST_POLICY_CWAKEUP_FIQ_SOURCE,  12, CLKM, RSVD1, CLKS, RSVD3, PLLP_OUT0, PLLP_OUT4, RSVD6, RSVD7, PLLX_OUT0_LJ, DVFS_CPU_CLK, RSVD10, RSVD11, RSVD12, RSVD13, PLLX_OUT0, DVFS_CPU_CLK_LJ);
DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(CCLK_BURST_POLICY_CPU_STATE,           28, STDBY, IDLE, RUN, RSVD3, IRQ, RSVD5, RSVD6, RSVD7, FIQ, RSVD9, RSVD10, RSVD11, RSVD12, RSVD13, RSVD14, RSVD15);

DEFINE_CLK_RST_REG(CPU_SOFTRST_CTRL2_CAR2PMC_CPU_ACK_WIDTH, 0, 12);

DEFINE_CLK_RST_REG_TWO_BIT_ENUM(SPARE_REG0_CLK_M_DIVISOR, 2, CLK_M_DIVISOR1, CLK_M_DIVISOR2, CLK_M_DIVISOR3, CLK_M_DIVISOR4);

DEFINE_CLK_RST_REG_BIT_ENUM(PLLC4_BASE_PLLC4_IDDQ,   18, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC4_BASE_PLLC4_LOCK,   27, NOT_LOCK, LOCK_FEQ_AND_PHASE);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLC4_BASE_PLLC4_ENABLE, 30, DISABLE, ENABLE);

DEFINE_CLK_RST_REG(PLLMB_BASE_PLLMB_DIVM, 0, 8);
DEFINE_CLK_RST_REG(PLLMB_BASE_PLLMB_DIVN, 8, 8);
DEFINE_CLK_RST_REG(PLLMB_BASE_PLLMB_DIVP, 20, 5);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLMB_BASE_PLLMB_LOCK, 27, NOT_LOCK, LOCK);
DEFINE_CLK_RST_REG_BIT_ENUM(PLLMB_BASE_PLLMB_ENABLE, 30, DISABLE, ENABLE);

/* RST_DEVICES */
#define CLK_RST_CONTROLLER_RST_DEVICES_L (0x004)
#define CLK_RST_CONTROLLER_RST_DEVICES_H (0x008)
#define CLK_RST_CONTROLLER_RST_DEVICES_U (0x00C)
#define CLK_RST_CONTROLLER_RST_DEVICES_X (0x28C)
#define CLK_RST_CONTROLLER_RST_DEVICES_Y (0x2A4)
#define CLK_RST_CONTROLLER_RST_DEVICES_V (0x358)
#define CLK_RST_CONTROLLER_RST_DEVICES_W (0x35C)

/* CLK_OUT_ENB */
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_L (0x010)
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_H (0x014)
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_U (0x018)
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_X (0x280)
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_Y (0x298)
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_V (0x360)
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_W (0x364)

/* CLK_SOURCE */
#define CLK_RST_CONTROLLER_CLK_SOURCE_PWM               (0x110)
#define CLK_RST_CONTROLLER_CLK_SOURCE_I2C1              (0x124)
#define CLK_RST_CONTROLLER_CLK_SOURCE_I2C5              (0x128)
#define CLK_RST_CONTROLLER_CLK_SOURCE_DISP1             (0x138)
#define CLK_RST_CONTROLLER_CLK_SOURCE_VI                (0x148)
#define CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC1            (0x150)
#define CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC2            (0x154)
#define CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC4            (0x164)
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTA             (0x178)
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTB             (0x17C)
#define CLK_RST_CONTROLLER_CLK_SOURCE_HOST1X            (0x180)
#define CLK_RST_CONTROLLER_CLK_SOURCE_I2C2              (0x198)
#define CLK_RST_CONTROLLER_CLK_SOURCE_EMC               (0x19C)
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC             (0x1A0)
#define CLK_RST_CONTROLLER_CLK_SOURCE_I2C3              (0x1B8)
#define CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC3            (0x1BC)
#define CLK_RST_CONTROLLER_CLK_SOURCE_CSITE             (0x1D4)
#define CLK_RST_CONTROLLER_CLK_SOURCE_TSEC              (0x1F4)
#define CLK_RST_CONTROLLER_CLK_SOURCE_MSELECT           (0x3B4)
#define CLK_RST_CONTROLLER_CLK_SOURCE_I2C4              (0x3C4)
#define CLK_RST_CONTROLLER_CLK_SOURCE_ACTMON            (0x3E8)
#define CLK_RST_CONTROLLER_CLK_SOURCE_SOR1              (0x410)
#define CLK_RST_CONTROLLER_CLK_SOURCE_SE                (0x42C)
#define CLK_RST_CONTROLLER_CLK_SOURCE_DSIA_LP           (0x620)
#define CLK_RST_CONTROLLER_CLK_SOURCE_DVFS_REF          (0x62C)
#define CLK_RST_CONTROLLER_CLK_SOURCE_DVFS_SOC          (0x630)
#define CLK_RST_CONTROLLER_CLK_SOURCE_I2C6              (0x65C)
#define CLK_RST_CONTROLLER_CLK_SOURCE_EMC_DLL           (0x664)
#define CLK_RST_CONTROLLER_CLK_SOURCE_UART_FST_MIPI_CAL (0x66C)
#define CLK_RST_CONTROLLER_CLK_SOURCE_SDMMC_LEGACY_TM   (0x694)
#define CLK_RST_CONTROLLER_CLK_SOURCE_NVENC             (0x6A4)

/* RST_DEV_*_SET */
#define CLK_RST_CONTROLLER_RST_DEV_L_SET (0x300)
#define CLK_RST_CONTROLLER_RST_DEV_H_SET (0x308)
#define CLK_RST_CONTROLLER_RST_DEV_U_SET (0x310)
#define CLK_RST_CONTROLLER_RST_DEV_V_SET (0x430)
#define CLK_RST_CONTROLLER_RST_DEV_W_SET (0x438)
#define CLK_RST_CONTROLLER_RST_DEV_X_SET (0x290)
#define CLK_RST_CONTROLLER_RST_DEV_Y_SET (0x2A8)

/* RST_DEV_*_CLR */
#define CLK_RST_CONTROLLER_RST_DEV_L_CLR (0x304)
#define CLK_RST_CONTROLLER_RST_DEV_H_CLR (0x30C)
#define CLK_RST_CONTROLLER_RST_DEV_U_CLR (0x314)
#define CLK_RST_CONTROLLER_RST_DEV_V_CLR (0x434)
#define CLK_RST_CONTROLLER_RST_DEV_W_CLR (0x43C)
#define CLK_RST_CONTROLLER_RST_DEV_X_CLR (0x294)
#define CLK_RST_CONTROLLER_RST_DEV_Y_CLR (0x2AC)

/* CLK_ENB_*_SET */
#define CLK_RST_CONTROLLER_CLK_ENB_L_SET (0x320)
#define CLK_RST_CONTROLLER_CLK_ENB_H_SET (0x328)
#define CLK_RST_CONTROLLER_CLK_ENB_U_SET (0x330)
#define CLK_RST_CONTROLLER_CLK_ENB_V_SET (0x440)
#define CLK_RST_CONTROLLER_CLK_ENB_W_SET (0x448)
#define CLK_RST_CONTROLLER_CLK_ENB_X_SET (0x284)
#define CLK_RST_CONTROLLER_CLK_ENB_Y_SET (0x29C)

/* CLK_ENB_*_CLR */
#define CLK_RST_CONTROLLER_CLK_ENB_L_CLR (0x324)
#define CLK_RST_CONTROLLER_CLK_ENB_H_CLR (0x32C)
#define CLK_RST_CONTROLLER_CLK_ENB_U_CLR (0x334)
#define CLK_RST_CONTROLLER_CLK_ENB_X_CLR (0x288)
#define CLK_RST_CONTROLLER_CLK_ENB_Y_CLR (0x2A0)
#define CLK_RST_CONTROLLER_CLK_ENB_V_CLR (0x444)
#define CLK_RST_CONTROLLER_CLK_ENB_W_CLR (0x44C)

/* RST_*_INDEX */
#define CLK_RST_CONTROLLER_RST_I2C1_INDEX   (0x0C)
#define CLK_RST_CONTROLLER_RST_I2C2_INDEX   (0x16)
#define CLK_RST_CONTROLLER_RST_I2C3_INDEX   (0x03)
#define CLK_RST_CONTROLLER_RST_I2C4_INDEX   (0x07)
#define CLK_RST_CONTROLLER_RST_I2C5_INDEX   (0x0F)
#define CLK_RST_CONTROLLER_RST_I2C6_INDEX   (0x06)

#define CLK_RST_CONTROLLER_RST_PWM_INDEX    (0x11)

#define CLK_RST_CONTROLLER_RST_UARTA_INDEX  (0x06)
#define CLK_RST_CONTROLLER_RST_UARTB_INDEX  (0x07)
#define CLK_RST_CONTROLLER_RST_UARTC_INDEX  (0x17)

#define CLK_RST_CONTROLLER_RST_ACTMON_INDEX (0x17)

/* CLK_ENB_*_INDEX */
#define CLK_RST_CONTROLLER_CLK_ENB_I2C1_INDEX   (0x0C)
#define CLK_RST_CONTROLLER_CLK_ENB_I2C2_INDEX   (0x16)
#define CLK_RST_CONTROLLER_CLK_ENB_I2C3_INDEX   (0x03)
#define CLK_RST_CONTROLLER_CLK_ENB_I2C4_INDEX   (0x07)
#define CLK_RST_CONTROLLER_CLK_ENB_I2C5_INDEX   (0x0F)
#define CLK_RST_CONTROLLER_CLK_ENB_I2C6_INDEX   (0x06)

#define CLK_RST_CONTROLLER_CLK_ENB_PWM_INDEX    (0x11)

#define CLK_RST_CONTROLLER_CLK_ENB_UARTA_INDEX  (0x06)
#define CLK_RST_CONTROLLER_CLK_ENB_UARTB_INDEX  (0x07)
#define CLK_RST_CONTROLLER_CLK_ENB_UARTC_INDEX  (0x17)

#define CLK_RST_CONTROLLER_CLK_ENB_ACTMON_INDEX (0x17)

#define CLK_RST_CONTROLLER_CLK_ENB_DVFS_INDEX (0x1B)

#define CLK_RST_CONTROLLER_CLK_ENB_TZRAM_INDEX (0x1E)

#define CLK_RST_CONTROLLER_CLK_ENB_CACHE2_INDEX (0x1F)
#define CLK_RST_CONTROLLER_CLK_ENB_CRAM2_INDEX (0x18)

#define CLK_RST_CONTROLLER_CLK_ENB_SE_INDEX (0x1F)

#define CLK_RST_CONTROLLER_CLK_ENB_HOST1X_INDEX   (0x1C)
#define CLK_RST_CONTROLLER_CLK_ENB_TSEC_INDEX     (0x13)
#define CLK_RST_CONTROLLER_CLK_ENB_SOR0_INDEX     (0x16)
#define CLK_RST_CONTROLLER_CLK_ENB_SOR1_INDEX     (0x17)
#define CLK_RST_CONTROLLER_CLK_ENB_SOR_SAFE_INDEX (0x1E)
#define CLK_RST_CONTROLLER_CLK_ENB_KFUSE_INDEX    (0x08)

/* RST_CPUG_CMPLX_* */
#define CLK_RST_CONTROLLER_RST_CPUG_CMPLX_SET   (0x450)
#define CLK_RST_CONTROLLER_RST_CPUG_CMPLX_CLR   (0x454)

DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_ARC_CLK_OVR_ON,             19, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_TSEC_CLK_OVR_ON,            20, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_TSECB_CLK_OVR_ON,           21, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_ISPB_CLK_OVR_ON,            22, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_TZRAM_CLK_OVR_ON,           23, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_QSPI_CLK_OVR_ON,            24, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_A9AVP_CLK_OVR_ON,           26, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_MPCORE_MSELECT_CLK_OVR_ON,  27, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_SDMMC1_LEGACY_TMCLK_OVR_ON, 28, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_SDMMC2_LEGACY_TMCLK_OVR_ON, 29, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_SDMMC3_LEGACY_TMCLK_OVR_ON, 30, OFF, ON);
DEFINE_CLK_RST_REG_BIT_ENUM(LVL2_CLK_GATE_OVRD_SDMMC4_LEGACY_TMCLK_OVR_ON, 31, OFF, ON);

DEFINE_CLK_RST_REG(CLK_SOURCE_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG(CLK_SOURCE_CLK_SOURCE, 29, 3);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_I2C1_I2C1_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2);
DEFINE_CLK_RST_REG(CLK_SOURCE_I2C1_I2C1_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_I2C5_I2C5_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2);
DEFINE_CLK_RST_REG(CLK_SOURCE_I2C5_I2C5_CLK_DIVISOR, 0, 8);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SDMMC1_SDMMC1_CLK_SRC, 29, PLLP_OUT0, PLLA_OUT,        PLLC_OUT0,      PLLC4_OUT2, PLLM_OUT0,  PLLE_OUT0,      CLK_M, PLLC4_OUT0);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SDMMC2_SDMMC2_CLK_SRC, 29, PLLP_OUT0, PLLC4_OUT2_LJ,   PLLC4_OUT0_LJ,  PLLC4_OUT2, PLLC4_OUT1, PLLC4_OUT1_LJ,  CLK_M, PLLC4_OUT0);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SDMMC4_SDMMC4_CLK_SRC, 29, PLLP_OUT0, PLLC4_OUT2_LJ,   PLLC4_OUT0_LJ,  PLLC4_OUT2, PLLC4_OUT1, PLLC4_OUT1_LJ,  CLK_M, PLLC4_OUT0);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SDMMC3_SDMMC3_CLK_SRC, 29, PLLP_OUT0, PLLA_OUT,        PLLC_OUT0,      PLLC4_OUT2, PLLC4_OUT1, PLLE_OUT0,      CLK_M, PLLC4_OUT0);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SDMMCX_SDMMCX_CLK_SRC, 29, PLLP_OUT0, _RSVD1_,         _RSVD2_,        PLLC4_OUT2, _RSVD4_,    _RSVD5_,        CLK_M, PLLC4_OUT0);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SDMMC24_SDMMC24_CLK_SRC, 29, PLLP_OUT0, PLLC4_OUT2_LJ,   PLLC4_OUT0_LJ,  PLLC4_OUT2, PLLC4_OUT1, PLLC4_OUT1_LJ,  CLK_M, PLLC4_OUT0);

DEFINE_CLK_RST_REG(CLK_SOURCE_SDMMC1_SDMMC1_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG(CLK_SOURCE_SDMMC2_SDMMC2_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG(CLK_SOURCE_SDMMC4_SDMMC4_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG(CLK_SOURCE_SDMMC3_SDMMC3_CLK_DIVISOR, 0, 8);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_UARTA_UARTA_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_UARTB_UARTB_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_UARTC_UARTC_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_VI_VI_CLK_SRC, 29, RESERVED0, PLLC2_OUT0, PLLC_OUT, PLLC3_OUT0, PLLP_OUT0, CLK_M, PLLA1_OUT0, PLLC4_OUT0);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_HOST1X_HOST1X_CLK_SRC, 29, PLLC4_OUT1, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT2, PLLP_OUT0, CLK_M, PLLA_OUT0, PLLC4_OUT0);

DEFINE_CLK_RST_REG(CLK_SOURCE_EMC_EMC_2X_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_EMC_EMC_2X_CLK_SRC, 29, PLLM_OUT0, PLLC_OUT0, PLLP_OUT0, CLK_M, PLLM_UD, PLLMB_UD, PLLMB_OUT0, PLLP_UD);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_NVENC_NVENC_CLK_SRC, 29, RESERVED0, PLLC2_OUT0, PLLC_OUT0, PLLC3_OUT0, PLLP_OUT0, RESERVED5, PLLA1_OUT0, CLK_M);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_TSEC_TSEC_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC3_OUT0, RESERVED4, PLLA1_OUT0, CLK_M, PLLC4_OUT0);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SE_SE_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC3_OUT0, RSVD4, PLLA1_OUT0, CLK_M, PLLC4_OUT0);
DEFINE_CLK_RST_REG_BIT_ENUM(CLK_SOURCE_SE_CLK_LOCK, 8, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(CLK_SOURCE_SOR1_SOR1_CLK_SEL0, 14, MUX, SOR1_BRICK_OUTPUT);
DEFINE_CLK_RST_REG_BIT_ENUM(CLK_SOURCE_SOR1_SOR1_CLK_SEL1, 15, SAFE_CLOCK, SOR1_CLOCK_SWITCH);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_SOR1_SOR1_CLK_SRC, 29, PLLP_OUT0, RESERVED1, PLLD_OUT0, RESERVED3, RESERVED4, PLLD2_OUT0, CLK_M, RESERVED7);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_MSELECT_MSELECT_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT2, PLLC4_OUT1, CLK_S, CLK_M, PLLC4_OUT0);
DEFINE_CLK_RST_REG(CLK_SOURCE_MSELECT_MSELECT_CLK_DIVISOR, 0, 8);

DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_ACTMON_ACTMON_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, CLK_S, PLLC4_OUT1, CLK_M, PLLC4_OUT2);

DEFINE_CLK_RST_REG(CLK_SOURCE_DSIA_LP_DSIA_LP_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_DSIA_LP_DSIA_LP_CLK_SRC, 29, PLLP_OUT0, RSVD1, PLLC_OUT0, PLLC4_OUT0, PLLC4_OUT1, PLLC4_OUT2, CLK_M, RSVD7);

DEFINE_CLK_RST_REG(CLK_SOURCE_DVFS_REF_DVFS_REF_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_DVFS_REF_DVFS_REF_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2);

DEFINE_CLK_RST_REG(CLK_SOURCE_DVFS_SOC_DVFS_SOC_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_DVFS_SOC_DVFS_SOC_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2);

DEFINE_CLK_RST_REG(CLK_SOURCE_UART_FST_MIPI_CAL_UART_FST_MIPI_CAL_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_UART_FST_MIPI_CAL_UART_FST_MIPI_CAL_CLK_SRC, 29, PLLP_OUT3, PLLC_OUT0, PLLC2_OUT0_2, RSVD3, PLLC2_OUT0_4, RSVD5, CLK_M, RSVD7);

DEFINE_CLK_RST_REG(CLK_SOURCE_LEGACY_TM_CLK_DIVISOR, 0, 8);
DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_LEGACY_TM_CLK_SRC, 29, PLLP_OUT3, PLLC_OUT0, PLLC2_OUT0, CLK_M, PLLP_OUT0, PLLC4_OUT0, PLLC4_OUT1, PLLC4_OUT2);

DEFINE_CLK_RST_REG_BIT_ENUM(RST_DEV_L_SET_SET_COP_RST, 1, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(RST_DEV_L_CLR_CLR_COP_RST, 1, DISABLE, ENABLE);

DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CPURESET0,    0, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CPURESET1,    1, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CPURESET2,    2, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CPURESET3,    3, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CORERESET0,  16, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CORERESET1,  17, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CORERESET2,  18, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_CORERESET3,  19, DISABLE, ENABLE);
DEFINE_CLK_RST_REG_BIT_ENUM(RST_CPUG_CMPLX_CLR_CLR_NONCPURESET, 29, DISABLE, ENABLE);

/* TODO: Actually include all devices. */
#define CLK_RST_FOREACH_DEVICE(HANDLER)     \
    HANDLER(L, CPU,               0,  0)    \
    HANDLER(L, RTC,               0,  4)    \
    HANDLER(L, TMR,               0,  5)    \
    HANDLER(L, GPIO,              0,  8)    \
    HANDLER(L, SDMMC2,            0,  9)    \
    HANDLER(L, SDMMC1,            0, 14)    \
    HANDLER(L, SDMMC4,            0, 15)    \
    HANDLER(L, USBD,              0, 22)    \
    HANDLER(L, DISP1,             0, 27)    \
    HANDLER(L, HOST1X,            0, 28)    \
    HANDLER(L, CACHE2,            0, 31)    \
    HANDLER(H, MEM,               1,  0)    \
    HANDLER(H, AHBDMA,            1,  1)    \
    HANDLER(H, APBDMA,            1,  2)    \
    HANDLER(H, PMC,               1,  6)    \
    HANDLER(H, FUSE,              1,  7)    \
    HANDLER(H, KFUSE,             1,  8)    \
    HANDLER(H, I2C5,              1, 15)    \
    HANDLER(H, DSI,               1, 16)    \
    HANDLER(H, MIPI_CAL,          1, 24)    \
    HANDLER(H, EMC,               1, 25)    \
    HANDLER(H, USB2,              1, 26)    \
    HANDLER(U, SDMMC3,            2,  5)    \
    HANDLER(U, CSITE,             2,  9)    \
    HANDLER(U, IRAMA,             2, 20)    \
    HANDLER(U, IRAMB,             2, 21)    \
    HANDLER(U, IRAMC,             2, 22)    \
    HANDLER(U, IRAMD,             2, 23)    \
    HANDLER(U, CRAM2,             2, 24)    \
    HANDLER(V, CPUG,              3,  0)    \
    HANDLER(V, MSELECT,           3,  3)    \
    HANDLER(V, APB2APE,           3, 11)    \
    HANDLER(V, SPDIF_DOUBLER,     3, 22)    \
    HANDLER(V, ACTMON,            3, 23)    \
    HANDLER(V, TZRAM,             3, 30)    \
    HANDLER(V, SE,                3, 31)    \
    HANDLER(W, PCIERX0,           4,  2)    \
    HANDLER(W, PCIERX1,           4,  3)    \
    HANDLER(W, PCIERX2,           4,  4)    \
    HANDLER(W, PCIERX3,           4,  5)    \
    HANDLER(W, PCIERX4,           4,  6)    \
    HANDLER(W, PCIERX5,           4,  7)    \
    HANDLER(W, DSIA_LP,           4, 19)    \
    HANDLER(W, ENTROPY,           4, 21)    \
    HANDLER(W, DVFS,              4, 27)    \
    HANDLER(W, MC1,               4, 30)    \
    HANDLER(X, MC_CAPA,           5,  7)    \
    HANDLER(X, MC_CBPA,           5,  8)    \
    HANDLER(X, MC_CPU,            5,  9)    \
    HANDLER(X, MC_BBC,            5, 10)    \
    HANDLER(X, EMC_DLL,           5, 14)    \
    HANDLER(X, UART_FST_MIPI_CAL, 5, 17)    \
    HANDLER(X, VIC,               5, 18)    \
    HANDLER(X, GPU,               5, 24)    \
    HANDLER(X, DBGAPB,            5, 25)    \
    HANDLER(X, PLLG_REF,          5, 29)    \
    HANDLER(Y, LEGACY_TM,         6,  1)    \
    HANDLER(Y, APE,               6,  6)    \
    HANDLER(Y, MC_CCPA,           6,  8)    \
    HANDLER(Y, MC_CDPA,           6,  9)    \
    HANDLER(Y, PLLP_OUT_CPU,      6, 31)

#define CLK_RST_DEFINE_SET_CLR_REG(REGISTER, DEVICE, REGISTER_INDEX, DEVICE_INDEX)                             \
    DEFINE_CLK_RST_REG_BIT_ENUM(CLK_ENB_##REGISTER##_SET_SET_CLK_ENB_##DEVICE, DEVICE_INDEX, DISABLE, ENABLE); \
    DEFINE_CLK_RST_REG_BIT_ENUM(CLK_ENB_##REGISTER##_CLR_CLR_CLK_ENB_##DEVICE, DEVICE_INDEX, DISABLE, ENABLE); \
    DEFINE_CLK_RST_REG_BIT_ENUM(CLK_OUT_ENB_##REGISTER##_CLK_ENB_##DEVICE,     DEVICE_INDEX, DISABLE, ENABLE); \
    DEFINE_CLK_RST_REG_BIT_ENUM(CLK_ENB_##REGISTER##_CLK_ENB_##DEVICE,         DEVICE_INDEX, DISABLE, ENABLE); \
    DEFINE_CLK_RST_REG_BIT_ENUM(RST_DEV_##REGISTER##_SET_SET_##DEVICE##_RST,   DEVICE_INDEX, DISABLE, ENABLE); \
    DEFINE_CLK_RST_REG_BIT_ENUM(RST_DEV_##REGISTER##_CLR_CLR_##DEVICE##_RST,   DEVICE_INDEX, DISABLE, ENABLE); \
    DEFINE_CLK_RST_REG_BIT_ENUM(RST_DEV_##REGISTER##_##DEVICE##_RST,           DEVICE_INDEX, DISABLE, ENABLE); \
    DEFINE_CLK_RST_REG_BIT_ENUM(RST_DEVICES_##REGISTER##_SWR_##DEVICE##_RST,   DEVICE_INDEX, DISABLE, ENABLE);

CLK_RST_FOREACH_DEVICE(CLK_RST_DEFINE_SET_CLR_REG)

#undef CLK_RST_DEFINE_SET_CLR_REG

