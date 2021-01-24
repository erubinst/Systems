// generates a simple ASCII art diamond of variable size based on user input

// Esme Rubinstein and Nuriel Leve
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int getdigit() {
  int cint;
  char c;
  while ((cint = getchar()) != EOF) {
    c = cint;
    if (isdigit(c) != 0) {
      int num = c - '0';
      return num;
    }
  }	
  return -1;
}

int main () {
  printf("I will print a diamond for you, enter a size between 1-9: ");
  int height = getdigit();
  int c,k;
  for (int k = 1; k <= height; k++) {
    for (c = 1; c <= height - k; c++) 
      printf(" ");
    
    for (c = 1; c <= (2 * k) - 1; c++)
      printf("*");
    
    printf("\n");
  }
  for (k = 1; k <= height - 1; k++) {
    for (c = 1; c <= k; c++) 
      printf(" ");
    
    for (c = 1; c <= 2 *(height - k) - 1; c++)
      printf("*");
    
    printf("\n");
  }
  return 0;
}


