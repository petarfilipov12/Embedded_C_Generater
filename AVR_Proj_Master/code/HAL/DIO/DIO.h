#ifndef DIO_H
#define DIO_H

#include <avr/io.h>

#include "Types.h"

#define DIO_PIN_INPUT      0
#define DIO_PIN_OUTPUT     1

#define DIO_PIN_LOW        0
#define DIO_PIN_HIGH       1

typedef struct{
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t* read_reg;
    uint8_t pin;
}DIO_sPinDataCfg_t;

#define DIO_PIN_COUNT  2

#define DIO_PinDataCfg_INIT                \
/*     ddr, port, ,read_reg, pin    */      \
    {&DDRB, &PORTB, &PINB, PB0},            \
    {&DDRD, &PORTD, &PIND, PD4}

extern DIO_sPinDataCfg_t asDIOPinsCfg[DIO_PIN_COUNT];

#define DIO_SET_PIN_AS_INPUT(index)        (*asDIOPinsCfg[index].ddr &= ~(1 << asDIOPinsCfg[index].pin))
#define DIO_SET_PIN_PULL_UP(index)         (*asDIOPinsCfg[index].port |= (1 << asDIOPinsCfg[index].pin))
#define DIO_SET_PIN_PULL_DOWN(index)       (*asDIOPinsCfg[index].port &= ~ (1 << asDIOPinsCfg[index].pin))
#define DIO_READ_PIN(index)                ((*asDIOPinsCfg[index].read_reg & (1 << asDIOPinsCfg[index].pin)) >> asDIOPinsCfg[index].pin)

#define DIO_SET_PIN_AS_OUTPUT(index)       (*asDIOPinsCfg[index].ddr |= (1 << asDIOPinsCfg[index].pin))
#define DIO_SET_PIN_HIGH(index)            (*asDIOPinsCfg[index].port |= (1 << asDIOPinsCfg[index].pin))
#define DIO_SET_PIN_LOW(index)             (*asDIOPinsCfg[index].port &= ~(1 << asDIOPinsCfg[index].pin))
#define DIO_TOGGLE_PIN(index)              (*asDIOPinsCfg[index].port ^= (1 << asDIOPinsCfg[index].pin))

extern Func_ReturnType DIO_Init_PIN(uint8 pin_id, uint8 pin_type);

#endif