//Esme RUbinstein and Nuriel Leve

#include <stdio.h>
#include "convertWord.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char*argv[]){
  char *word;
  int cint;
  int len;
  if (argv[1][0] == '-') {
	 if ( argv[1][1] == 'h' || argv[1][1] == '?') {
		 printf("pigLatin.1 takes in a string or a textfile of strings and translates it to pig latin.\n");
	  exit(1);
	 }
  }
  while ((cint = getchar()) != EOF) {
    // cint isn't a character, so just output it.
    if (!isalpha(cint)) {
      putchar(cint);
    }
    // cint is a character, so put it back into the read buffer so
    // that it can be read by convertWord.
    else {
      ungetc(cint, stdin);
      word = convertWord();
      printf("%s", word);
      // Free the memory that was allocated in convertWord through a
      // call to malloc.
      free(word);
    }
  }
  return 0;
}
