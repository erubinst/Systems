// Nuriel Leve & Esme Rubinstein 

//
// This program reads in characters one at a time and calls print_bits() to  print them out as a sequence of '1's and '0's.

#include <stdio.h>
#include <stdlib.h>
#include "bits.h"



int main() {
  int decNum;
  while ((decNum = getchar()) != EOF) {
    long int q = (long int)decNum;
    print_bits(q);
  }
  return 0;
}
