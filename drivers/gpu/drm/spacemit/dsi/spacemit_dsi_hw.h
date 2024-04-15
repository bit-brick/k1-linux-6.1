// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2023 Spacemit Co., Ltd.
 *
 */

#ifndef _SPACEMIT_DSI_HW_H_
#define _SPACEMIT_DSI_HW_H_

#include <linux/io.h>
#include <drm/drm_print.h>

#define DSI_CTRL_0 0x0
#define DSI_CTRL_1 0x4
#define DSI_IRQ_ST1  0x8
#define DSI_IRQ_MASK1 0xC
#define DSI_IRQ_ST 0x10
#define DSI_IRQ_MASK 0x14
#define DSI_IRQ_PHY_FIFO_UNDERRUN	BIT(23)
#define DSI_IRQ_VPN_BF_UNDERRUN_ERR	BIT(19)
#define DSI_IRQ_VPN_BF_OVERRUN_ERR	BIT(17)
#define DSI_IRQ_MASK_BITS		( DSI_IRQ_PHY_FIFO_UNDERRUN | \
					DSI_IRQ_VPN_BF_UNDERRUN_ERR | \
					DSI_IRQ_VPN_BF_OVERRUN_ERR )

#ifdef CONFIG_SPACEMIT_FPGA
#define DSI_FPGA_PHY_CTRL_0 0x18
#define DSI_FPGA_PHY_CTRL_1 0x1C
#endif

#define DSI_CPU_CMD_0 0x20
#define DSI_CPU_CMD_1 0x24
#define DSI_CPU_CMD_3 0x2C
#define DSI_CPU_WDAT 0x30
#define DSI_CPU_STATUS_0 0x34
#define DSI_CPU_STATUS_1 0x38
#define DSI_CPU_STATUS_2 0x3C
#define DSI_CPU_STATUS_3 0x40
#define DSI_CPU_STATUS_4 0x44

#define DSI_CPN_STATUS_1 0x4C
#define DSI_CPN_CMD 0x50
#define DSI_CPN_CTRL_0 0x54
#define DSI_CPN_CTRL_1 0x58
#define DSI_CPN_STATUS_0 0x5C

#define DSI_RX_PKT_ST_0 0x60
#define DSI_RX_PKT_HDR_0 0x64
#define DSI_RX_PKT_ST_1 0x68
#define DSI_RX_PKT_HDR_1 0x6C
#define DSI_RX_PKT_CTRL 0x70
#define DSI_RX_PKT_CTRL_1 0x74
#define DSI_RX_PKT_ST_2 0x78
#define DSI_RX_PKT_HDR_2 0x7C

#define DSI_LCD_BDG_CTRL0 0x84
#define DSI_LCD_BDG_CTRL1 0x88

#define DSI_TX_TIMER 0xE4
#define DSI_RX_TIMER 0xE8
#define DSI_TURN_TIMER 0xEC

#define DSI_VPN_CTRL_0 0x100
#define DSI_VPN_CTRL_1 0x104
#define DSI_VPN_TIMING_0 0x110
#define DSI_VPN_TIMING_1 0x114
#define DSI_VPN_TIMING_2 0x118
#define DSI_VPN_TIMING_3 0x11C
#define DSI_VPN_WC_0 0x120
#define DSI_VPN_WC_1 0x124
#define DSI_VPN_WC_2 0x128
#define DSI_VPN_SLOT_CNT_0 0x130
#define DSI_VPN_SLOT_CNT_1 0x134
#define DSI_VPN_SYNC_CODE 0x138
#define DSI_VPN_STATUS_0 0x140
#define DSI_VPN_STATUS_1 0x144
#define DSI_VPN_STATUS_2 0x148
#define DSI_VPN_STATUS_3 0x14C
#define DSI_VPN_STATUS_4 0x150

#define DSI_PHY_CTRL_0 0x180
#define DSI_PHY_CTRL_1 0x184
#define DSI_PHY_CTRL_2 0x188
#define DSI_PHY_CTRL_3 0x18C
#define DSI_PHY_STATUS_0 0x190
#define DSI_PHY_STATUS_1 0x194
#define DSI_PHY_LPRX_0 0x198
#define DSI_PHY_LPRX_1 0x19C
#define DSI_PHY_LPTX_0 0x1A0
#define DSI_PHY_LPTX_1 0x1A4
#define DSI_PHY_LPTX_2 0x1A8
#define DSI_PHY_STATUS_2 0x1AC
#define DSI_PHY_TIME_0 0x1C0
#define DSI_PHY_TIME_1 0x1C4
#define DSI_PHY_TIME_2 0x1C8
#define DSI_PHY_TIME_3 0x1CC
#define DSI_PHY_CODE_0 0x1D0
#define DSI_PHY_CODE_1 0x1D4
#define DSI_PHY_ANA_PWR_CTRL 0x1E0
#define DSI_PHY_ANA_CTRL0 0x1E4
#define DSI_PHY_ANA_CTRL1 0x1E8

//DSI_CTRL_0 0x0
#define CFG_SOFT_RST BIT(31)
#define CFG_SOFT_RST_REG BIT(30)
#define CFG_CLR_PHY_FIFO BIT(29)
#define CFG_RST_TXLP BIT(28)
#define CFG_RST_CPU BIT(27)
#define CFG_RST_CPN BIT(26)
#define CFG_RST_VPN BIT(24)
#define CFG_DSI_PHY_RST BIT(23)
#define CFG_VPN_TX_EN BIT(8)
#define CFG_VPN_SLV BIT(4)
#define CFG_CPN_EN BIT(2)
#define CFG_VPN_EN BIT(0)

//DSI_CTRL_1 0x4
#define CFG_EOTP_EN BIT(8)

//DSI_IRQ_ST 0x10
#define IRQ_RX_ERR BIT(25)
#define IRQ_RX_TRG3 BIT(7)
#define IRQ_RX_TRG2 BIT(6)
#define IRQ_RX_TRG1 BIT(5)
#define IRQ_RX_TRG0 BIT(4)
#define IRQ_RX_PKT BIT(2)

#ifdef CONFIG_SPACEMIT_FPGA
//DSI_FPGA_PHY_CTRL_0 0x18
#define CFG_DPHY_RSETZ 0
#define CFG_DPHY_SHUTDOWN 1
#define CFG_DPHY_RSTZCAL 2
#define CFG_DPHY_TXRXZ 3
#define CFG_DPHY_MASSLVZ 4
#define CFG_DPHY_ENABLE0 5
#define CFG_DPHY_ENABLE1 6
#define CFG_DPHY_ENABLECLK 7
#define CFG_DPHY_HSREQ_LANECLK 8
#define CFG_DPHY_HSREQ_LANE0 9
#define CFG_DPHY_HSREQ_LANE1 10
#define CFG_DPHY_HSREQ_LANE2 11
#define CFG_DPHY_HSREQ_LANE3 12
#define CFG_DPHY_TXRX_BYTECLK_REV 13
#define CFG_DPHY_FCLK_REV 14

//DSI_FPGA_PHY_CTRL_1 0x1C
#define CFG_DPHY_TESTCLK 0
#define CFG_DPHY_TESTCLR 1
#define CFG_DPHY_TESTEN 2
#define CFG_DPHY_TXRXZ 3
#define CFG_DPHY_TESTDIN 8
#define CFG_DPHY_TESTDOUT 16
#define CFG_DPHY_LOCK 24
#endif

//DSI_CPU_CMD_0 0x20
#define CFG_CPU_CMD_REQ BIT(31)
#define CFG_CPU_SP BIT(30)
#define CFG_CPU_TURN BIT(29)
#define CFG_CPU_TXLP BIT(27)
#define CFG_CPU_WC_SHIFT 0

//DSI_CPU_CMD_1 0x24
#define CFG_TXLP_LPDT_SHIFT 20

#define CFG_TXLP_LPDT_MASK (0xF << CFG_TXLP_LPDT_SHIFT)

//DSI_CPU_CMD_3 0x2C
#define CFG_CPU_DAT_REQ BIT(31)
#define CFG_CPU_DAT_RW BIT(30)
#define CFG_CPU_DAT_ADDR_SHIFT 16

//DSI_CPN_CMD 0x50
#define CFG_CPN_TE_EN_SHIFT 28
#define CFG_CPN_RGB_TYPE_SHIFT 24
#define CFG_CPN_BURST_MODE_SHIFT 3
#define CFG_CPN_FIRSTP_SEL_SHIFT 2
#define CFG_CPN_DMA_DIS_SHIFT 1
#define CFG_CPN_ADDR0_EN_SHIFT 0

//DSI_CPN_CTRL_1 0X58
#define CFG_CPN_PKT_CNT_SHIFT 	16
#define CFG_CPN_FIFO_FULL_LEVEL_SHIFT 0

//DSI_RX_PKT_ST_0 0x60
#define CFG_RX_PKT0_PTR_SHIFT 16
#define CFG_RX_PKT0_PTR_MASK (0x3F << CFG_RX_PKT0_PTR_SHIFT)

//DSI_RX_PKT_CTRL 0x70
#define CFG_RX_PKT_RD_REQ BIT(31)
#define CFG_RX_PKT_RD_PTR_SHIFT 16
#define CFG_RX_PKT_RD_PTR_MASK (0x3F << CFG_RX_PKT_RD_PTR_SHIFT)
#define CFG_RX_PKT_RD_DATA_SHIFT 0
#define CFG_RX_PKT_RD_DATA_MASK (0x3F << CFG_RX_PKT_RD_DATA_SHIFT)

//DSI_RX_PKT_CTRL_1 0x74
#define CFG_RX_PKT_BCNT_SHIFT 0
#define CFG_RX_PKT_BCNT_MASK (0xff << CFG_RX_PKT_BCNT_SHIFT)

//DSI_LCD_BDG_CTRL0 0x84
#define CFG_VPN_FIFO_AFULL_CNT_SHIT 16
#define CFG_VPN_FIFO_AFULL_CNT_MASK (0xfff << CFG_VPN_FIFO_AFULL_CNT_SHIT)
#define CFG_VPN_FIFO_AFULL_BYPASS BIT(6)
#define CFG_CPN_VSYNC_EDGE_SHIFT 5
#define CFG_CPN_VSYNC_EDGE_MASK (1 << CFG_CPN_VSYNC_EDGE_SHIFT)
#define CFG_CPN_TE_EDGE_SHIFT 4
#define CFG_CPN_TE_EDGE_MASK (1 << CFG_CPN_TE_EDGE_SHIFT)
#define CFG_CPN_TE_MODE_SHIFT 2
#define CFG_CPN_TE_MODE_MASK (3 << CFG_CPN_TE_MODE_SHIFT)
#define CFG_PIXEL_SWAP BIT(1)
#define CFG_SPLIT_EN BIT(0)

//DSI_LCD_BDG_CTRL1 0x88
#define CFG_CPN_TE_DLY_CNT_SHIFT 16
#define CFG_CPN_TE_LINE_CNT_SHIFT 0

//DSI_VPN_CTRL_1 0x104
#define CFG_VPN_VSYNC_RST_EN_SHIFT 31
#define CFG_VPN_AUTO_WC_DIS_SHIFT 27
#define CFG_VPN_HACT_WC_EN_SHIFT 26
#define CFG_VPN_TIMING_CHECK_DIS_SHIFT 25
#define CFG_VPN_AUTO_DLY_DIS_SHIFT 24
#define CFG_VPN_HLP_PKT_EN_SHIFT 22
#define CFG_VPN_HEX_PKT_EN_SHIFT 21
#define CFG_VPN_HFP_PKT_EN_SHIFT 20
#define CFG_VPN_HBP_PKT_EN_SHIFT 18
#define CFG_VPN_HSE_PKT_EN_SHIFT 17
#define CFG_VPN_HSA_PKT_EN_SHIFT 16
#define CFG_VPN_HEX_SLOT_EN_SHIFT 14
#define CFG_VPN_LAST_LINE_TURN_SHIFT 10
#define CFG_VPN_LPM_FRAME_EN_SHIFT 9
#define CFG_VPN_BURST_MODE_SHIFT 2
#define CFG_VPN_BURST_MODE_MASK (0x3 << CFG_VPN_BURST_MODE_SHIFT)
#define CFG_VPN_RGB_TYPE_SHIFT 0
#define CFG_VPN_RGB_TYPE_MASK (0x3 << CFG_VPN_RGB_TYPE_SHIFT)

//DSI_PHY_CTRL_1 0x184
#define CFG_DPHY_ADD_VALID BIT(17)
#define CFG_DPHY_VDD_VALID BIT(16)
#define CFG_DPHY_ULPS_DATA BIT(2)
#define CFG_DPHY_ULPS_CLK BIT(1)
#define CFG_DPHY_CONT_CLK BIT(0)

//DSI_PHY_CTRL_2 0x188
#define CFG_DPHY_HSTX_RX BIT(14)
#define CFG_DPHY_LANE_MAP_SHIFT 12
#define CFG_DPHY_LANE_EN_SHIFT 4
#define CFG_DPHY_FORCE_BTA BIT(0)

#define CFG_DPHY_LANE_MAP_MASK (0x3 << CFG_DPHY_LANE_MAP_SHIFT)
#define CFG_DPHY_LANE_EN_MASK (0xF << CFG_DPHY_LANE_EN_SHIFT)

//DSI_PHY_TIME_0 0x1C0
#define CFG_DPHY_TIME_HS_EXIT_SHIFT 24
#define CFG_DPHY_TIME_HS_TRAIL_SHIFT 16
#define CFG_DPHY_TIME_HS_ZERO_SHIFT 8
#define CFG_DPHY_TIME_HS_PREP_SHIFT 0

#define CFG_DPHY_TIME_HS_EXIT_MASK (0xFF << CFG_DPHY_TIME_HS_EXIT_SHIFT)
#define CFG_DPHY_TIME_HS_TRAIL_MASK (0xFF << CFG_DPHY_TIME_HS_TRAIL_SHIFT)
#define CFG_DPHY_TIME_HS_ZERO_MASK (0xFF << CFG_DPHY_TIME_HS_ZERO_SHIFT)
#define CFG_DPHY_TIME_HS_PREP_MASK (0xFF << CFG_DPHY_TIME_HS_PREP_SHIFT)

//DSI_PHY_TIME_1 0x1C4
#define CFG_DPHY_TIME_TA_GET_SHIFT 24
#define CFG_DPHY_TIME_TA_GO_SHIFT 16
#define CFG_DPHY_TIME_WAKEUP_SHIFT 0

#define CFG_DPHY_TIME_TA_GET_MASK (0xFF << CFG_DPHY_TIME_TA_GET_SHIFT)
#define CFG_DPHY_TIME_TA_GO_MASK (0xFF << CFG_DPHY_TIME_TA_GO_SHIFT)
#define CFG_DPHY_TIME_WAKEUP_MASK (0xFFFF << CFG_DPHY_TIME_WAKEUP_SHIFT)

//DSI_PHY_TIME_2 0x1C8
#define CFG_DPHY_TIME_CLK_EXIT_SHIFT 24
#define CFG_DPHY_TIME_CLK_TRAIL_SHIFT 16
#define CFG_DPHY_TIME_CLK_ZERO_SHIFT 8
#define CFG_DPHY_TIME_CLK_LPX_SHIFT 0

#define CFG_DPHY_TIME_CLK_EXIT_MASK (0xFF << CFG_DPHY_TIME_CLK_EXIT_SHIFT)
#define CFG_DPHY_TIME_CLK_TRAIL_MASK (0xFF << CFG_DPHY_TIME_CLK_TRAIL_SHIFT)
#define CFG_DPHY_TIME_CLK_ZERO_MASK (0xFF << CFG_DPHY_TIME_CLK_ZERO_SHIFT)
#define CFG_DPHY_TIME_CLK_LPX_MASK (0xFF << CFG_DPHY_TIME_CLK_LPX_SHIFT)

//DSI_PHY_TIME_3 0x1CC
#define CFG_DPHY_TIME_LPX_SHIFT 8
#define CFG_DPHY_TIME_REQRDY_SHIFT 0

#define CFG_DPHY_TIME_LPX_MASK (0xFF << CFG_DPHY_TIME_LPX_SHIFT)
#define CFG_DPHY_TIME_REQRDY_MASK (0xFF << CFG_DPHY_TIME_REQRDY_SHIFT)

//DSI_PHY_ANA_PWR_CTRL 0x1E0
#define CFG_DPHY_ANA_RESET BIT(8)
#define CFG_DPHY_ANA_PU BIT(0)

//DSI_PHY_ANA_CTRL1 0x1E8
#ifdef CONFIG_SPACEMIT_FPGA
#define CFG_CLK_SEL BIT(23)
#else
#define CFG_CLK_SEL BIT(21)
#endif
#define CFG_CLK_DIV2 BIT(11)


/*dphy timming*/
#define HS_PREP_CONSTANT_DEFAULT 40
#define HS_PREP_UI_DEFAULT 4
#define HS_ZERO_CONSTANT_DEFAULT 145
#define HS_ZERO_UI_DEFAULT 10
#define HS_TRAIL_CONSTANT_DEFAULT 60
#define HS_TRAIL_UI_DEFAULT 4
#define HS_EXIT_CONSTANT_DEFAULT 100
#define HS_EXIT_UI_DEFAULT 0
#define CK_ZERO_CONSTANT_DEFAULT 300
#define CK_ZERO_UI_DEFAULT 0
#define CK_TRAIL_CONSTANT_DEFAULT 60
#define CK_TRAIL_UI_DEFAULT 0
#define REQ_READY_DEFAULT 0x3C
#define WAKEUP_CONSTANT_DEFAULT 1000000
#define WAKEUP_UI_DEFAULT 0
#define LPX_CONSTANT_DEFAULT 60
#define LPX_UI_DEFAULT 0


static inline uint32_t dsi_read(void __iomem *addr, uint32_t offset)
{
	DRM_DEBUG("DSI_READ [0x%x] = 0x%x\n", offset, __raw_readl(addr + offset));
	return __raw_readl(addr + offset);
}

static inline void dsi_write(void __iomem *addr, uint32_t offset, uint32_t data)
{
	DRM_DEBUG("DSI_WRITE [0x%x] = 0x%x\n", 0xd421a800 + offset, data);
	__raw_writel(data, (addr + offset));
}

static inline void dsi_set_bits(void __iomem *addr, uint32_t offset, uint32_t bits)
{
	dsi_write(addr, offset, (dsi_read(addr, offset) | bits));
}

static inline void dsi_clear_bits(void __iomem *addr, uint32_t offset, uint32_t bits)
{
	dsi_write(addr, offset, (dsi_read(addr, offset) & ~bits));
}

static inline void dsi_write_bits(void __iomem *addr, uint32_t offset, uint32_t mask, uint32_t value)
{
	uint32_t tmp = 0;

	tmp = dsi_read(addr, offset);
	tmp &= ~mask;
	tmp |= value;
	dsi_write(addr, offset, tmp);
}

#endif /*_SPACEMIT_DSI_HW_H_*/