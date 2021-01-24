//Esme Rubinstein and Nuriel Leve                                                                           

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char * convertWordBack(){
  char str[100];
  bool uppercasep[100];
  char * newString;
  int len;

  if(scanf("%[A-Za-z]", str) == 1){
    len = strlen(str);
    for (int i = 0; i<len; i++){
      if (isupper(str[i])) {
        uppercasep[i] = true;
        str[i] = tolower(str[i]);
      }
      else{
        uppercasep[i] = false;
      }
    }
    //test the last three letters                                                                           
    if ((str[len-1] == 'y') && (str[len-2] == 'a') && (str[len-3] == 'y')) {
      newString = (char*)malloc(sizeof(str));
      strncpy(newString, str, len-3);
    }
    else if (str[len-1] == 'y' && str[len-2] == 'a'){
      newString = (char*)malloc(sizeof(str));
      str[len-2] = '\0';
      //save the last letter before the 'ay' and move them to the front of the word, delete the 'ay'     
      strcpy(newString, &str[len-3]);
      strncat(newString, str, len-3);
      newString[len] = '\0';
    }
    else{
      newString = (char*)malloc(sizeof(str));
      strcpy(newString, str);
    }
    for (int i = 0; i < len; i++){
      if (uppercasep[i]){
        newString[i] = toupper(newString[i]);
      }
    }
  }
  else {
    newString = "";
  }
  return newString;
}

