//Esme Rubinstein and Nuriel Leve


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool vowelP(char ch){
  return (ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A'|| ch == 'E' || ch == 'I\
' || ch == 'O' || ch == 'U') ;
}

char * translateWord() {
  char str[100];
  bool uppercasep[100];
  char * newString;
  int len;

  if(scanf("%[A-Za-z]", str) == 1){
    newString = (char*)malloc(sizeof(str)+10);
    len = strlen(str);
    for (int i = 0; i<len; i++){
      if (isupper(str[i])) {
	uppercasep[i] = true;
	str[i] = tolower(str[i]);
      } else {
	uppercasep[i] = false;
      }
    }
    if (len < 3){
      strcpy(newString,str);
    }
    else{
      strcpy(newString, &str[3]);
      strncat(newString, str, 3);
      len = strlen(newString);
      newString[len] = '\0';
    }
    for (int i = 0; i < len; i++) {
      if (uppercasep[i]) {
	newString[i] = toupper(newString[i]);
      }
    }
    return newString;
  }
}

int main(){
  char *word;
  int cint;
  int len;
  while ((cint = getchar()) != EOF) {
    // cint isn't a character, so just output it.
    if (!isalpha(cint)) {
      putchar(cint);
    }
    // cint is a character, so put it back into the read buffer so
    // that it can be read by convertWord.
    else {
      ungetc(cint, stdin);
      word = translateWord();
      printf("%s", word);
      // Free the memory that was allocated in convertWord through a
      // call to malloc.
      free(word);
    }
  }
  return 0;
}
