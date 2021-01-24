// Nuriel Leve and Esme Rubinstein
//
// This prgoram reads in a sequence of '1' and '0' chracters one at a time and outputs them as actual characters using decode_bits()  


#include <stdio.h>
#include <stdlib.h>
#include "bits.h"


int main() {
  int decNum;
  while ((decNum = getchar()) != EOF) {
      decode_bits(decNum);
  }

  return 0;
}

