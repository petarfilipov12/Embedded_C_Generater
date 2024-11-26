#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

#include "Types.h"
#include "IO_Service.h"

typedef uint8 GPIO_PinInputOutputType;
#define GPIO_PIN_INPUT       0
#define GPIO_PIN_OUTPUT      1
#define GPIO_PIN_UNDEFINED   0xffu

typedef struct{
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    uint8_t pin;
}GPIO_sPinDataCfg_t;

typedef enum{
    eGPIO_PIN_0,
    eGPIO_count
}GPIO_eGPIOPins;

#define GPIO_PinDataCfg_INIT    \
/*     ddr, port, pin    */     \
    {&DDRB, &PORTB, PB0}

extern GPIO_sPinDataCfg_t asPinsCfg[eGPIO_count];

#define GPIO_SET_PIN_AS_INPUT(index)     (*asPinsCfg[index].ddr &= ~(1 << asPinsCfg[index].pin))
#define GPIO_SET_PIN_PULL_UP(index)      (*asPinsCfg[index].port |= (1 << asPinsCfg[index].pin))
#define GPIO_SET_PIN_PULL_DOWN(index)    (*asPinsCfg[index].port &= ~ (1 << asPinsCfg[index].pin))
//#define GPIO_READ_PIN()

#define GPIO_SET_PIN_AS_OUTPUT(index)    (*asPinsCfg[index].ddr |= (1 << asPinsCfg[index].pin))
#define GPIO_SET_PIN(index)              (*asPinsCfg[index].port |= (1 << asPinsCfg[index].pin))
#define GPIO_UNSET_PIN(index)            (*asPinsCfg[index].port &= ~(1 << asPinsCfg[index].pin))
#define GPIO_TOGGLE_PIN(index)           (*asPinsCfg[index].port ^= (1 << asPinsCfg[index].pin))

extern uint8 HAL_GPIO_Init_PIN(uint8 pin_id, GPIO_PinInputOutputType pin_type);

#endif