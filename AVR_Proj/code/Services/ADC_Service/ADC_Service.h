#ifndef ADC_SERVICE_H
#define ADC_SERVICE_H

#include "Types.h"
#include "ADC.h"

#define ADC_Service_PIN_0_ID             0
#define ADC_Service_PIN_COUNT            1

extern Func_ReturnType ADC_Service_Read_Pin(uint8 pin_id, uint8* value);

#endif