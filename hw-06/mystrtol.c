//Esme Rubinstein and Nuriel Leve

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

long mystrtol(char *start, char **rest) {
  int len = strlen(start), sign_multiplier = 1, num_start = 0, num_end, mag = 1;
  long val = 0;

  for (int i = 0; i < len; i++) {
    if (isspace(start[i])) {
      num_start++;
    }
    else {
      if (start[i] == '-') {
	sign_multiplier = -1;
	num_start++;
      }
      break;
    }
  }
  num_end = num_start;
  for (int i = num_start; i < len; i++) {
    if (isdigit(start[i])) {
      num_end++;
    }
    else {
      break;
    }
  }
  if ( num_end > num_start) {
    for (int i = num_end - 1; i >= num_start; i--) {
      val+=mag*(start[i] - '0');
      mag*=10;
    }
    val = val * sign_multiplier;
    *rest = &start[num_end];
    return val;
  }
  else {
    *rest = NULL;
    return 0;
  }
}
  
   
