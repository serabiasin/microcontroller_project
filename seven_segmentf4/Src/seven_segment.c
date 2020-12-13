#include "seven_segment.h"

GPIO_PinState segment_a(uint8_t input){

uint8_t result =(0x04&~input)>>2&(0x01&~input);
result|=(0x02&input)>>1;
result|=(0x04&input)>>2&(0x01&input);
result|=(0x08&input)>>3; 

if (result==0x01){

    return GPIO_PIN_SET;
 
    }else{

     return GPIO_PIN_RESET;
    } 
     
     
 } 
 


GPIO_PinState segment_b(uint8_t input){
uint8_t result =(~input & 0x04)>>2;
result|=(0x02&~input)>>1&(0x01&~input);
result|=(0x02&input)>>1&(0x01&input);

if(result==1){
    return GPIO_PIN_SET;

 }else{
    return GPIO_PIN_RESET;
 }
}


//fixed
GPIO_PinState segment_c(uint8_t input){
uint8_t result=(~input & 0x02)>>1|(input &0x01)|(input & 0x04)>>2;
if(result ==1){
	return GPIO_PIN_SET;
}else{
	return GPIO_PIN_RESET;
	}

}
//fixed
GPIO_PinState segment_d(uint8_t input){
 uint8_t result=(input & 0x08)>>3;
 result|=(~input&0x04)>>2 & (~input&0x01);
 result|=(~input & 0x04)>>2 & (input & 0x02)>>1;
 result|=(input & 0x02)>>1 & (~input & 0x01);
 result|=(input & 0x04)>>2&(~input & 0x02)>>1&(input & 0x01);

if(result ==1){
	return GPIO_PIN_SET;
}else{
	return GPIO_PIN_RESET;
	}


}

//fixed
GPIO_PinState segment_e(uint8_t input){

uint8_t result = (~input&0x04)>>2 &(~input &0x01);
result|=(input &0x02)>>1 & (~input&0x01); 

if(result ==1){

    return GPIO_PIN_SET;
}else{

    return GPIO_PIN_RESET;
}



}
//fixed
GPIO_PinState segment_f(uint8_t input){
uint8_t result =(~input & 0x02)>>1 & (0x01 & ~input);
result|=(0x04&input)>>2 & (0x02&~input)>>1;
result|=(0x04 & input)>>2&(0x01 & ~input);
result|=(0x08 & input)>>3;

if(result ==1){
	return GPIO_PIN_SET;
}else{
	return GPIO_PIN_RESET;
	}


}

//fixed
GPIO_PinState segment_g(uint8_t input){

uint8_t result =(0x04&~input)>>2 & (0x02&input)>>1;
result|=(0x04&input)>>2 &(0x02&~input)>>1;
result|=(0x08&input)>>3;
result|=(0x04&input)>>2&(0x01&~input);

if(result ==1){
	return GPIO_PIN_SET;
}else{
	return GPIO_PIN_RESET;
	}



}
