#include <stdio.h>

#include <string.h>     /* strcat, fls */
#include <stdlib.h>     /* strtol */
#include <math.h>       /* pow */

#define WIDTH 18

const char *byte_to_binary(int x)
{
    static char b[WIDTH + 1];
    b[0] = '\0';

    int z;
    for (z = pow(2, WIDTH - 1); z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

/* 
   the following has a lot of redundancy. we should be able to derive
   BITS and MASK from PATTERN. OK, lost MASK; can we get BITS from 
   PATTERN? Yes.
*/
#define PATTERN 0b111011010110

/*Function to left rotate n by d bits*/
// DOES NOT WORK -- adds bits above the desired width.
int leftRotate(int n, int b, unsigned int d)
{
   /* In n<<d, last d bits are 0. To put first 3 bits of n at 
     last, do bitwise or of n<<d with n >>(INT_BITS - d) */
   return (n << d)|(n >> (b - d));
}
 
/*Function to left rotate n by d bits*/
int leftRotateWithMask(int n, int b, unsigned int d)
{
   /* In n<<d, last d bits are 0. To put first 3 bits of n at 
     last, do bitwise or of n<<d with n >>(INT_BITS - d) */
  int mask = (1 << b) - 1;
  printf("mask: %s\n", byte_to_binary(mask));
  return ((n << d)|(n >> (b - d))) & mask;
}
 
int main(void) {

  int score = PATTERN;
  int bits = fls(PATTERN);
  int mask = (1 << bits) - 1;
  //printf("bits: %d\n", bits);
  //int mymask = mybits - 1;
  for (int i = 0 ; i <= bits ; i++) {
    printf("PATT: %s\n", byte_to_binary(PATTERN));
    printf("scor: %s\n", byte_to_binary(score));
    printf("resu: %s\n\n", byte_to_binary(score | PATTERN));
    //score = leftRotateWithMask(score, bits, 1);
    score = ((score << 1)|(score >> (bits - 1))) & mask;
  }
  return 0;
}
