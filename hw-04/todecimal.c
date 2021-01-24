//Esme Rubinstein and Nuriel Leve

#include <stdio.h>
#include <stdbool.h>
#include "getnum.h"
#include "globals.h"
// outputs signed value in base 10 with no leading 0 characters
int main() {
  long num;
  int ch;

  while ((ch = getchar()) != EOF) {
    ungetc(ch, stdin);
    num = getnum();
    if (!error_flag) {
      if (num < 0){
	printf("-");
	num = -num;
      }
      if (num == 0){
	printf("0\n");
      }
      else{
	printf("%ld\n", num);
      }
    }
    else{
      printf("not a valid number\n");
    }
  }
  return 0;
}
