#include <avr/interrupt.h>
#include "TimerHelpers.h"

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void InitADC()                    // Function to initialise ADC Channel
{
  ADMUX = (1 << REFS0);
  ADMUX &= ~((1 << REFS1) | (1 << ADLAR) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ReadADC(uint8_t ch)      // Function to read value of ADC
{
  ch = ch & 0b00000111;
  ADMUX |= ch;
  ADCSRA |= (1 << ADSC);
  while (!(ADCSRA & (1 << ADIF)));
  //_delay_ms(1000);
  ADCSRA |= (1 << ADIF);
  return (ADC);
}


void setup() {
  InitADC();

  pinMode( 9,OUTPUT);  pinMode(10,OUTPUT);
  
  Timer1::setMode(7, Timer0::PRESCALE_1, Timer0::CLEAR_A_ON_COMPARE | Timer0::CLEAR_B_ON_COMPARE);
  
  OCR1A = OCR1B = 0;
  
  ICR1 = 0x3ff;
}

void loop()
{
  static uint16_t n = 0;
  n = ReadADC(0);
  //  n++;
  //  if (n == 0x400) n = 0;
  //  delay(1);


//    OCR0A = n & 0x3FF;
//    OCR0B = n & 0x3FF;

  OCR1A = n;
  OCR1B = n;

  //  OCR2A = n;
  //  OCR2B = n;

}


