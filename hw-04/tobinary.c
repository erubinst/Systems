#include <stdio.h>
#include <stdbool.h>
#include "getnum.h"
#include "globals.h"

int main() {
  long num;
  int k, buffer[64];
  bool start_printing_p = false;
  int ch;

  while ((ch = getchar()) != EOF) {
    ungetc(ch, stdin);
    num = getnum();
    if (!error_flag) {
      if (num<0){
	printf("-");
	num = -num;
      }
      if (num == 0){
	printf("0");
      }
      else{
	printf("0b");
	for (int c = 63; c>= 0; c--){
	  k = num >> c;

	  if (k & 1) {
	    start_printing_p = true;
	    printf("1");
	  }
	  else if (start_printing_p){
	    printf("0");
	  }
	}
      }
      printf("\n");
      start_printing_p = false;
    }
  }
  return 0;
}
