#include <stdio.h>

#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

const char *byte_to_binary(int x)
{
    static char b[13];
    b[0] = '\0';

    int z;
    for (z = 2048; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

#define PATTERN 0b111011010110
#define BITS 12


/*Function to left rotate n by d bits*/
int leftRotate(int n, int b, unsigned int d)
{
   /* In n<<d, last d bits are 0. To put first 3 bits of n at 
     last, do bitwise or of n<<d with n >>(INT_BITS - d) */
   return (n << d)|(n >> (b - d));
}
 
int main(void) {

  printf("%ld\n", sizeof(int));
  int score = PATTERN;
  for (int i = 0 ; i <= 12 ; i++) {
    printf("%s\n", byte_to_binary(PATTERN));
    printf("%s\n", byte_to_binary(score));
    printf("%s\n\n", byte_to_binary(score | PATTERN));
    score = leftRotate(score, BITS, 1);
  }
  return 0;
}
