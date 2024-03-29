/********************************************************************\
|*
|* Version : 1.0
|*
|* Copyright : Copyright (C) 2006, Altium
|*
|* Description : Registers Definitions for the LH79520
|*
\********************************************************************/

#ifndef __HARDWARE_H__
#define __HARDWARE_H__


#define SET_BIT(n) (((unsigned int)(1)) << (n))
#define BITMASK(field_width) ( SET_BIT(field_width) - 1)
#define SET_BIT_FIELD(f,v) (((unsigned int)(v)) << (f))

// UART1 Registers and Registers Bit Field constants
#define UART1Base                       0xFFFC1000
#define UART1_BASE(base)                ((volatile unsigned char *) base)
#define UART1_UARTDR(base)              UART1_BASE(base)[0x000]
#define UART1_UARTLCR_H(base)           UART1_BASE(base)[0x02C]
#define UART1_UARTIFLS(base)            UART1_BASE(base)[0x034]
#define UART1_UARTICR(base)             UART1_BASE(base)[0x044]
#define UART1_UARTIMSC(base)            UART1_BASE(base)[0x038]
#define UART1_UARTCR(base)              UART1_BASE(base)[0x030]
#define UART1_UARTFR(base)              UART1_BASE(base)[0x018]

#define UART1_UARTLCR_H_FEN             SET_BIT(4)
#define UART1_UARTLCR_H_WLEN8           SET_BIT_FIELD(5,3)
#define UART1_UARTIFLS_RXIFLSEL(n)      SET_BIT_FIELD(3,((n)&BITMASK(3)))
#define UART1_UARTIFLS_TXIFLSEL(n)      SET_BIT_FIELD(0,((n)&BITMASK(3)))
#define UART1_UARTICR_OEIC              SET_BIT(10)
#define UART1_UARTICR_BEIC              SET_BIT(9)
#define UART1_UARTICR_PEIC              SET_BIT(8)
#define UART1_UARTICR_FEIC              SET_BIT(7)
#define UART1_UARTICR_RTIC              SET_BIT(6)
#define UART1_UARTICR_TXIC              SET_BIT(5)
#define UART1_UARTICR_RXIC              SET_BIT(4)
#define UART1_UARTCR_TXE                SET_BIT(8)
#define UART1_UARTCR_RXE                SET_BIT(9)
#define UART1_UARTCR_UARTEN             SET_BIT(0)
#define UART1_UARTFR_RXFE               SET_BIT(4)
#define UART1_UARTFR_TXFF               SET_BIT(5)

// IOCON Registers and Registers Bit Field constants
#define IOCONBase                       0xFFFE5000
#define IOCON_BASE(base)                ((volatile unsigned char *) base)
#define IOCON_UARTMux(base)             IOCON_BASE(base)[0x010]

#define IOCON_UARTMux_U1RxD             SET_BIT_FIELD(2,1)
#define IOCON_UARTMux_U1TxD             SET_BIT_FIELD(3,1)

// RCPC Registers and Registers Bit Field constants
#define RCPCBase                        0xFFFE2000
#define RCPC_BASE(base)                 ((volatile unsigned char *) base)
#define RCPC_RCPCCTRL(base)             RCPC_BASE(base)[0x000]
#define RCPC_PeriphClkCtrl1(base)       RCPC_BASE(base)[0x024]
#define RCPC_PeriphClkSelect(base)      RCPC_BASE(base)[0x030]


#endif // __HARDWARE_H__



