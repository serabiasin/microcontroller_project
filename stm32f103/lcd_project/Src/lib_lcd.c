#include "lib_lcd.h"

#define CLEAR_DISPLAY 0x01
#define LCD_16X2 0x0
#define LCD_16X1 0x0
/**
 *  to do :
 *  bikin method untuk parsing string
 *
 * */

/**
 *  Mengirim Instruksi ke LCD
 * @param instruct [kode instruksi register]
 * @param this     [LCD_DRIVER Struct]
 *

 */

void sendInstruction(uint16_t instruct, LCD_DRIVER *this) {
        HAL_Delay(50);
        turnOn(&this->enPin);

        splitBit(instruct, this);

        turnOff(&this->enPin);
        HAL_Delay(50);
}

/**
 * Menampilkan output ke LCD
 * @param string [alphanumeric bisa berupa string maupun karakter]
 * @param this   [object LCD_DRIVER]
 */
void sendcharTolcd(const char *string, LCD_DRIVER *this) {
        turnOn(&this->enPin);
        turnOn(&this->rsPin);
        turnOff(&this->rwPin);
        while (*string != '\0') {
                splitBit((uint8_t)*string, this);
                string++;
        }
        turnOff(&this->enPin);
        turnOff(&this->rsPin);
}

GPIO_PinState getState(uint8_t data, uint8_t bit) {

        if (data & bit) {
                return GPIO_PIN_SET;
        } else {
                return GPIO_PIN_RESET;
        }
}

/**
 * split Byte into bit per GPIO
 * @param byte [the data that want to be splited]
 * @param this [LCD_DRIVER Object]
 */
void splitBit(uint8_t byte, LCD_DRIVER *this) {
        HAL_Delay(50);

        HAL_GPIO_WritePin(this->BIT0.GPIOSEKTOR, this->BIT0.PIN,
                          getState(byte, 0x01));

        HAL_GPIO_WritePin(this->BIT1.GPIOSEKTOR, this->BIT1.PIN,
                          getState(byte, 0x02));

        HAL_GPIO_WritePin(this->BIT2.GPIOSEKTOR, this->BIT2.PIN,
                          getState(byte, 0x04));

        HAL_GPIO_WritePin(this->BIT3.GPIOSEKTOR, this->BIT3.PIN,
                          getState(byte, 0x08));
        HAL_GPIO_WritePin(this->BIT4.GPIOSEKTOR, this->BIT4.PIN,
                          getState(byte, 0x10));

        HAL_GPIO_WritePin(this->BIT5.GPIOSEKTOR, this->BIT5.PIN,
                          getState(byte, 0x20));

        HAL_GPIO_WritePin(this->BIT6.GPIOSEKTOR, this->BIT6.PIN,
                          getState(byte, 0x40));

        HAL_GPIO_WritePin(this->BIT7.GPIOSEKTOR, this->BIT7.PIN,
                          getState(byte, 0x80));

        HAL_Delay(50);
}

/**
 *
 * Set value satu pin I/O
 * @param this [LCD_DRIVER object,di spesifikkan ke Pin I/O ]
 *
 */
void turnOn(PIN_PERIPHERAL *this) {
        HAL_GPIO_WritePin(this->GPIOSEKTOR, this->PIN, GPIO_PIN_SET);
        HAL_Delay(50);
}

/**
 *
 * [Reset value satu pin I/O]
 * @param this [LCD_DRIVER object,di spesifikkan ke Pin I/O]
 *
 */
void turnOff(PIN_PERIPHERAL *this) {
        HAL_GPIO_WritePin(this->GPIOSEKTOR, this->PIN, GPIO_PIN_RESET);
        HAL_Delay(50);
}

void beginLCD(LCD_DRIVER *this) {
        HAL_Delay(100);
        turnOff(&this->enPin); // set pin Enable high to firing data to LCD
        turnOff(&this->rsPin);
        turnOff(&this->rwPin);
        // aktifkan function set, 1 baris saja
        splitBit(0x30, this);
        // enable blink,cursor,dan display
        splitBit(0x0F, this);
        turnOn(&this->enPin);
        // matikan enable agar data register aktif
        turnOff(&this->enPin);
}
