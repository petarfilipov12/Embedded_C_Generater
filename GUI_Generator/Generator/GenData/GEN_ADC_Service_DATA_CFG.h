#ifndef GEN_ADC_SERVICE_DATA_CFG_H
#define GEN_ADC_SERVICE_DATA_CFG_H

#include "Types.h"
#include "Queue.h"
#include "GEN_ADC_Service_CFG.h"
#include "ADC_Service_.h"

extern ADC_Service_AdcCfg_t ADC_Service_AdcHwCfg_data[ADC_Service_ADC_Service_ADCs_Count];

extern inline void ADC_Service_AdcHwCfg_data_INIT_FUNC(void);

#endif