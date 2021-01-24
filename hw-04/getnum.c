//Nuriel Leve and Esme Rubinstein

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "globals.h"
#include <ctype.h>

bool error_flag;

long getnum(){
  //read in a signed integer in one of 4 formats and then return the value. skip leading whitespace and stop reading in a number on the next occurrence of the whitespace.  all formats optionally begin with a - to indicate a negative value; positive values do not have this
  char str[256];
  int index = 0, len, base = 0;
  bool negative_p = false;
  long num = 0;

  error_flag = false;
  if (scanf("%s", str) == 1) {
    len = strlen(str);
    if (len >= 1){
      if (str[index] == '-') {
	negative_p = true;
	index++;
      }
      if (str[index] == '0') {
	index ++;
	if (str[index] == 'b') {
	  index ++;
	  base = 2;
	  for (int i = index; i<len; i++){
	    if ((str[i] - '0') > 2) {
	      error_flag = true;
	    }
	  }
	}
	else if (str[index] == 'x') {
	  index ++;
	  base = 16;
	  for (int i = index; i<len; i++){
	    if (!isxdigit(str[index])){
	      error_flag = true;
	    }
	  }
	}
 
	else if (isdigit(str[index])) {
	  base = 8;
	  for (int i = index; i<len; i++) {
	    if ((str[i] - '0') > 7) {
	      base = 10;
	      index --;
	      break;
	    }
	  }
	}
      }
      else if (isdigit(str[index])) {
	base = 10;
      }
      if (base > 0){
	int pos = 1;
	int increment;

	for (int i = (len-1); i >= index; i--) {
	  if ((base == 16) && (!isdigit(str[i]))) {
	    if (islower(str[i])) {
	      str[i] = toupper(str[i]);
	    }
	    increment = str[i] - 'A' + 10;
	  }
	  else {
	    increment = str[i] - '0';
	  }
	  num += pos * increment;
	  pos *= base;
	}
	if (negative_p){
	  num = - num;
	}
      }
      else{
	error_flag = true;
      }
    }
  }
  else{
    error_flag = true;
  }
  return num;
	
}
