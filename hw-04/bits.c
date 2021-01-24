// Nuriel Leve and Esme Rubinstein
//
// A program that contains print_bits() and decode_bits()
//
//print_bits() will take in a character and print out its value in binary format
//decode_bits() will take in a character and print out its corresponding characger 
//


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "bits.h"


void decode_bits(int ch){
  static int buffer[CHAR_BIT];
  static int index = 0;
  if(isspace(ch) == 0){
    if (ch == '1' || ch == '0') {
      buffer[index++] = (ch - '0');
      if (index == CHAR_BIT){
	int accum = 0;
	int position = 1;
	for (int i = CHAR_BIT-1; i >= 0; i--){
	  accum += position*buffer[i];
	  position *= 2;
	}
	printf("%c\n", (char)accum);
	index = 0;
      }
    }
    else{
      printf("not a valid binary representation \n");
      exit(0);
    }
  }
}


void print_bits(int ch) {
	int j, i = 1, binNum [100];
	while(ch != 0) {
		binNum[i++] = ch % 2;
		ch = ch / 2;
	}
	int p = CHAR_BIT - ((i-1) % CHAR_BIT);
	if (p != CHAR_BIT) {
		while (p-- != 0) {
			binNum[i++] = 0;
		}
	}
	for (j = i-1; j>0; j--) {
		printf("%d", binNum[j]); //prints out each array entry of 8 bits
	} printf("\n");
		
}

