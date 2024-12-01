#include "ADC_Service.h"

typedef struct{
    uint8 current_pin_id;
    Func_ReturnType status;
}ADC_Service_AdcCfg_t;

ADC_Service_AdcCfg_t ADC_Service_Adc_data[ADC_Service_ADC_COUNT] = {
    {0xff, RET_NOT_OK}, //ADC_0
};

typedef struct{
    uint8 adc_id;
    uint8 last_value;
    Func_ReturnType status;
}ADC_Service_PinCfg_t;

ADC_Service_PinCfg_t ADC_Service_Pin_data[ADC_Service_PIN_COUNT] = {
    {ADC_Service_ADC_0_ID, RET_OK}, //ADC_PIN_0
};

void ADC_Service_Init(void)
{
    uint8 i = 0;

    for(i=0; i<ADC_Service_ADC_COUNT; i++)
    {
        ADC_Service_Adc_data[i].status = ADC_Enable_ADC(i);
    }
}

void ADC_Service_Cyclic(void)
{
    uint8 adc_id = 0;

    for(adc_id=0; adc_id<ADC_Service_ADC_COUNT; adc_id++)
    {
        if(RET_BUSY == ADC_Service_Adc_data[adc_id].status)
        {
            if(ADC_IS_ADC_READY(adc_id))
            {
                ADC_READ(adc_id, &ADC_Service_Pin_data[ADC_Service_Adc_data[adc_id].current_pin_id].last_value);
                ADC_Service_Adc_data[adc_id].status = RET_OK;
                ADC_Service_Pin_data[ADC_Service_Adc_data[adc_id].current_pin_id].status = RET_READY;
            }
        }
    }
}

Func_ReturnType ADC_Service_Read_Pin(uint8 pin_id, uint8* value)
{
    Func_ReturnType returnL = ADC_Service_Pin_data[pin_id].status;

    if(RET_OK == returnL)
    {
        returnL = ADC_Service_Adc_data[ADC_Service_Pin_data[pin_id].adc_id].status;
        if(RET_OK == returnL)
        {
            returnL = ADC_Start_Measurement(ADC_Service_Pin_data[pin_id].adc_id, pin_id);
            if(RET_OK == returnL)
            {
                ADC_Service_Adc_data[ADC_Service_Pin_data[pin_id].adc_id].current_pin_id = pin_id;
                ADC_Service_Adc_data[ADC_Service_Pin_data[pin_id].adc_id].status = RET_BUSY;
                ADC_Service_Pin_data[pin_id].status = RET_PENDING;
                returnL = RET_PENDING;
            }
        }
    }
    else if(RET_READY == returnL)
    {
        *value = ADC_Service_Pin_data[pin_id].last_value;
        ADC_Service_Pin_data[pin_id].status = RET_OK;
        returnL = RET_OK;
    }

    return returnL;
}