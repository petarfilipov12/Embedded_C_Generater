#ifndef GEN_DIO_SERVICE_DATA_CFG_H
#define GEN_DIO_SERVICE_DATA_CFG_H

#include "Types.h"
#include "Queue.h"
#include "GEN_DIO_Service_CFG.h"
#include "DIO_Service.h"

extern DIO_Service_PinCfg_t DIO_Service_PinCfg_data[DIO_Service_DIO_Service_Pins_Count];

extern inline void DIO_Service_PinCfg_data_INIT_FUNC(void);

#endif