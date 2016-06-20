/*
  Steve Reich's Clapping Music for one LED
 */

#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>

// change these
#define BPM  280
#define DUTY 0.15
#define BARS 2

// don't change these
#define MSINSEC  1000.0*60.0
#define BEAT     MSINSEC / BPM
#define TIMEON   DUTY * BEAT
#define TIMEOFF  BEAT - TIMEON

// this is the score
#define PATTERN 0b111011010110
#define BITS 12  /* there's no fls in the AVR string.h! */

int main(void) {
  // pin 5 is an input
  //DDB0 = 0;
  // try pull-up resistor off
  //PORTB0 = 0;

  // pin 6 is an output
  //DDB1 = 1;

  DDRB = 0b10;
  PORTB = 0b00;

  int second = PATTERN;
  int mask = (1 << BITS) - 1;

  for (int cycle = 0 ; cycle <= 12 ; cycle++) {
    for (int bars = 0 ; bars < BARS; bars++) {
      for (int i = 0b100000000000 ; i > 0 ; i >>= 1) {
        if (i & (PATTERN | second)) {
          PORTB = 0b10;
          _delay_ms(TIMEON);
          PORTB = 0b00;
          _delay_ms(TIMEOFF);
        } else {
          _delay_ms(BEAT);
        }
      }
    }
    second = ((second << 1)|(second >> (BITS - 1))) & mask;
  }
}


