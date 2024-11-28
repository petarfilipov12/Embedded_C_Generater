#include "ADC.h"

uint8 au8ADCPinsCfg[ADC_PIN_COUNT] = {ADC_PinDataCfg_INIT};

Func_ReturnType ADC_Enable_ADC(void)
{
    ADC_SET_VOLTAGE_REF();
    ADC_SET_OUTPUT_RESOLUTION();
    ADC_SET_CLOCK_PERSCALER();
    ADC_ENABLE_ADC();

    return RET_OK;
}

Func_ReturnType ADC_Start_Measurement(uint8 pin_id)
{
    Func_ReturnType returnL = RET_BUSY;

    if(ADC_IS_READY_TO_MEASURE())
    {
        ADC_SET_PIN_TO_MEASURE(pin_id);
        ADC_START_MESUREMENT();

        returnL = RET_OK;
    }

    return returnL;
}

Func_ReturnType ADC_Read_Pin(uint8 pin_id, uint8* value)
{
    
}