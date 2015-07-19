#include <avr/interrupt.h>
#include "TimerHelpers.h"

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0

volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded!
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.



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
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS

  //  InitADC();

  pinMode( 9, OUTPUT);  pinMode(10, OUTPUT);

  Timer1::setMode(7, Timer0::PRESCALE_1, Timer0::CLEAR_A_ON_COMPARE | Timer0::CLEAR_B_ON_COMPARE);

  OCR1A = OCR1B = 0;

  ICR1 = 0x3ff;
}

void loop()
{
  if (BPM < 30 || BPM > 180) return;
  if (Pulse == true) {
    OCR1A = OCR1B = Signal;
  } else {
    OCR1A = OCR1B = 511;
  }
//  delay(20);
}


