//Esme Rubinstein and Nuriel Leve                                                                           
//                                                                                                          
//A program that takes in a string and converts it from pig latin to English, 'untranslating' it            

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "convertWordBack.h"

int main(int argc, char*argv[]) {
  char *word;
  int cint;
  int len;
  if (argv[1][0] == '-') {
         if ( argv[1][1] == 'h' || argv[1][1] == '?') {
                 printf("unpigLatin.1 takes in a string or a textfile of strings that is in pig latin and translates it back into English.\n");
          exit(1);
         }
  }
  while ((cint = getchar()) != EOF){
    if  (!isalpha(cint)) {
      putchar(cint);
    }
    else{
      ungetc(cint, stdin);
      word = convertWordBack();
      printf("%s", word);
      free(word);
    }
  }
  return 0;

}
