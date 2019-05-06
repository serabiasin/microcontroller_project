#ifndef LIB_LCD_H
#define LIB_LCD_H
#include "stm32f1xx_hal.h"

typedef struct {
        GPIO_TypeDef *GPIOSEKTOR;
        uint16_t PIN;
} PIN_PERIPHERAL;

typedef struct {
        PIN_PERIPHERAL enPin;
        PIN_PERIPHERAL rsPin;
        PIN_PERIPHERAL rwPin;

        PIN_PERIPHERAL BIT0;
        PIN_PERIPHERAL BIT1;
        PIN_PERIPHERAL BIT2;
        PIN_PERIPHERAL BIT3;
        PIN_PERIPHERAL BIT4;
        PIN_PERIPHERAL BIT5;
        PIN_PERIPHERAL BIT6;
        PIN_PERIPHERAL BIT7;

} LCD_DRIVER;

/*ESSENTIAL ROUTINE SET*/
void sendInstruction(uint16_t instruct, LCD_DRIVER *this);
void splitBit(uint8_t byte, LCD_DRIVER *this); // 8 bit format
GPIO_PinState getState(uint8_t data, uint8_t bit);

void turnOn(PIN_PERIPHERAL *this);
void turnOff(PIN_PERIPHERAL *this);

/**
 * ROUTINE FOR LCD PROCESS
 */
void beginLCD(LCD_DRIVER *this);

/*MISC Features for LCD*/
void sendcharTolcd(const char *string, LCD_DRIVER *this);

/* IMPLEMENT SOON */
void resetDisplay(LCD_DRIVER *this);
void setPosition(uint8_t x, uint8_t y);
#endif
