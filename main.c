#include <stdio.h>
#include <clock.c>
#include <config.c>

#define ADC_SR    (unsigned int*) (0x40012000) //status register controllare il bit 1 per interrupt fine lettura!

#define ADC1_CR2  (unsigned int*) (0x40012008) //control register 2 
#define CONT      (unsigned int)  (1<<1)       //conversione continua
#define SWSTART   (unsigned int)  (1<<30)      //inizia conversione
#define ADCON     (unsigned int)  (1<<0)       //accendi l'adc

#define ADC_DR    (unsigned int*) (0x4001204c) //dove vengono conservati i dati  DATA[15:0]: Regular data

void main (void){

attiva_clock(1,'a');
attiva_clock(2,'a');
gpio_config('a',0,"analog","default","default","default");

unsigned int* puntatore;
unsigned int  valore;
double        risultato;

puntatore=ADC1_CR2;
*puntatore |= ADCON;
*puntatore |= CONT;
*puntatore |= SWSTART;

while(1){  
puntatore=ADC_SR;
  
  if(*puntatore==0x12){
    puntatore=ADC_DR;
    valore=(*puntatore);
    risultato=valore;
    printf("%lf \n",risultato/4095);
    }
  }
}