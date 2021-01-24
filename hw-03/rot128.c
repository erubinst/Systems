// Next you will create a program called rot128 that will "encrypt" files by using a rot-128 encryption algorithm. This algorithm is based on the classic text encryption scheme rot-13 which shifts each letter 13 positions in the alphabet (i.e., 'a' becomes 'n', 'b' becomes 'o', 'z' becomes 'm', etc.). Two applications of rot-13 returns you to the original.

// Instead of just rotating 13 positions, I want you to rotate by half the allowed range of a char, that way we can encrypt and decrypt any file on the system. Normally, a char is 8-bits, but since we can't be sure of that, you should have the program calculate using the proper constant. (You will need to #include <limits.h> to use this value.)

// Nuriel Leve and Esme Rubinstein
//


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//rotate char with this value
int main(int argc, char *argv[]) {
  char NUMSHIFT;
  int cint;
  char c;
  if(argc == 1){
    NUMSHIFT = (UCHAR_MAX + 1) / 2;
  }
  else{
    NUMSHIFT = atoi(argv[1]);
  }
  while ((cint = getchar()) != EOF) {
    char newChar;
    c = cint;
    newChar = c + NUMSHIFT;
    putchar(newChar);
  }
  
}


