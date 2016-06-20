/*
   Demo of the simplest on/off button code
   Button connected to PD2
   LEDs connected to PB0..PB7
*/

// ------- Preamble -------- //
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // -------- Inits --------- //
  PORTB |= (1 << PB0);  /* initialize pullup resistor on our input pin */
  DDRB = 0x01;             /* set up all LEDs but one for output */

  // ------ Event loop ------ //
  while (1) {
    if (bit_is_clear(PINB, PB0)) {            /* look for button press */
                      /* equivalent to if ((PIND & (1 << PD2)) == 0 ){ */
      set_PORTB_bit(1,1);
      //PORTB = 0b00000010;                                   /* pressed */
    }
    else {
      set_PORTB_bit(1,0);
      //PORTB = 0b00000000;                             /* not pressed */
    }
  }                                                  /* End event loop */
  return 0;
}

// Function code
int set_PORTB_bit(int position, int value)
{
  // Sets or clears the bit in position 'position' 
  // either high or low (1 or 0) to match 'value'.
  // Leaves all other bits in PORTB unchanged.
                
  if (value == 0)
  {
    PORTB &= ~(1 << position);      // Set bit position low
  }
  else
  {
    PORTB |= (1 << position);       // Set high, leave others alone
  }

  return 1;
}
