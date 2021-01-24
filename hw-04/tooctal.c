//Esme Rubinstein and Nuriel Leve
// outputs the signed value in base 8 with a single leading 0
//Esme Rubinstein and Nuriel Leve                                                                                                              
#include <stdio.h>
#include <stdbool.h>
#include "getnum.h"
#include "globals.h"

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
        printf("%lo\n", num);
      }
    }
    else{
      printf("not a valid number\n");
    }
  }
  return 0;
}
