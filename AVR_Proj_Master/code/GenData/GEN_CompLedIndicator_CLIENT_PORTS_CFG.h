#ifndef GEN_COMPLEDINDICATOR_CLIENT_PORTS_CFG_H
#define GEN_COMPLEDINDICATOR_CLIENT_PORTS_CFG_H

#include "GEN_DIO_Service_SERVER_PORTS_CFG.h"
#include "GEN_DIO_Service_CFG.h"
#include "GEN_UART_Service_SERVER_PORTS_CFG.h"
#include "GEN_UART_Service_CFG.h"

#define CompLedIndicator_DIO_ReadPin	DIO_Service_Read_Pin
#define CompLedIndicator_DIO_TogglePin	DIO_Service_Toggle_Pin
#define CompLedIndicator_UART_Transmit	UART_Service_Transmit
#define CompLedIndicator_UART_Read	UART_Service_Read
#define CompLedIndicator_DIO_WritePin	DIO_Service_Write_Pin

#endif