#ifndef SEVEN_SEGMENT_H
#include "stm32f4xx_hal.h"
#define SEVEN_SEGMENT_H
 
GPIO_PinState segment_a(uint8_t input);
GPIO_PinState segment_b(uint8_t input);
GPIO_PinState segment_c(uint8_t input);
GPIO_PinState segment_d(uint8_t input);
GPIO_PinState segment_e(uint8_t input);
GPIO_PinState segment_f(uint8_t input);
GPIO_PinState segment_g(uint8_t input);
#endif
