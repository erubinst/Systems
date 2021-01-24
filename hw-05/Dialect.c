//Esme Rubinstein and Nuriel Leve                                                                                                 
//
//A program that takes in a string and converts it into a different dialect: for every consonant, add 'ong' at the end of it           

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool vowelP(char ch){
  return (ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A'|| ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') ;
}

char * translateWord() {
	char str[100];
	bool uppercasep[100];
	char realStr[100];
	char * newString;
	int j=0, len;
	
	if(scanf("%[A-Za-z]", str) == 1){
		len = strlen(str);
		//checks each lettter if its capital or not and saves as true if so, false if not
		for (int i = 0; i<len; i++){
			if (isupper(str[i])) {
				uppercasep[i] = true;
				str[i] = tolower(str[i]);
			} else {
				uppercasep[i] = false;
			}
		}
		for (int i = 0; i < len; i++) {
			if (vowelP(str[i])) {
				realStr[j] = str[i];
				j += 1;
			} else {
				realStr[j] = str[i];
				realStr[j+1] = 'o';
				realStr[j+2] = 'n';
				realStr[j+3] = 'g';
				j = j + 4;
			}
		}
		//save the memory and copy the tranlated string to newString
		newString = (char*)malloc(sizeof(realStr));
		strncpy(newString, realStr, j);
	}

	else {
		newString = "";
	}
	return newString;
}

int main() {
  char *word;
  int cint;
  int len;
  while ((cint = getchar()) != EOF){
    if  (!isalpha(cint)) {
      putchar(cint);
    }
    else{
      ungetc(cint, stdin);
      word = translateWord();
      word[0] = toupper(word[0]);
      printf("%s", word);
      free(word);
    }
  }
  return 0;
}

