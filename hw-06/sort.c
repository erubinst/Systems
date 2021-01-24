// Nuriel Leve & Esme Rubinstein
//
// A program that sorts lines of text based on specific criteria: alphabetical, folding, numerical
// Extra credit: implemented MergeSort for the program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "mystrtol.h"
#define max 1024

enum sort_mode{normal, number, folding};

int mycmp (enum sort_mode mode, char *line1, char *line2) {
  if (mode == number) {
      long num1, num2;
      char *rest1, *rest2;
      num1 = mystrtol(line1,&rest1);
      num2 = mystrtol(line2,&rest2);
      if (num1 < num2) {
	return -1;
      }
      else if (num1 > num2) {
	return 1;
      }
      else {
	return strcmp(rest1, rest2);
      }
    }
  else if (mode == folding) {
    int line1_len = strlen(line1), line2_len = strlen(line2);
    bool line1_case_state[line1_len], line2_case_state[line2_len];

    for (int i = 0; i < line1_len; i++) {
      if (isupper(line1[i])) {
	line1_case_state[i] = true;
	line1[i] = tolower(line1[i]);
      }
      else {
	line1_case_state[i] = false;
      }
    }
    for (int i = 0; i < line2_len; i++) {
      if (isupper(line2[i])) {
	line2_case_state[i] = true;
	line2[i] = tolower(line2[i]);
      }
      else {
	line2_case_state[i] = false;
      }
    }
    int val = strcmp(line1, line2);

    for (int i = 0; i < line1_len; i++) {
      if (line1_case_state[i]) {
	line1[i] = toupper(line1[i]);
      }
    }
    for (int i = 0; i < line2_len; i++) {
      if (line2_case_state[i]) {
	line2[i] = toupper(line2[i]);
      }
    }
    return val;
  }
  else {
    return strcmp(line1, line2);
  }
}

void merge(enum sort_mode mode, bool reverse_flg, char **Arr, int start, int mid, int end) {
  char *temp[end - start + 1];
  int i = start, j = mid+1, k = 0;
  bool cmppred;

  // traverse both arrays and in each iteration add smaller of both elements in temp 
  while(i <= mid && j <= end) {
    if (reverse_flg) {
      cmppred = (mycmp(mode, Arr[i], Arr[j]) >= 0);
    }
    else {
      cmppred = (mycmp(mode, Arr[i], Arr[j]) <= 0);
    }
    if(cmppred) {
      temp[k] = Arr[i];
      k += 1; i += 1;
    }
    else {
      temp[k] = Arr[j];
      k += 1; j += 1;
    }
  }

  // add elements left in the first interval 
  while(i <= mid) {
    temp[k] = Arr[i];
    k += 1; i += 1;
  }

  // add elements left in the second interval 
  while(j <= end) {
    temp[k] = Arr[j];
    k += 1; j += 1;
  }

  // copy temp to original interval
  for(i = start; i <= end; i += 1) {
    Arr[i] = temp[i - start];
      }
}

void mergeSort(enum sort_mode mode, bool reverse_flg, char **Arr, int start, int end) {

  if(start < end) {
    int mid = (start + end) / 2;
    mergeSort(mode, reverse_flg, Arr, start, mid);
    mergeSort(mode, reverse_flg, Arr, mid+1, end);
    merge(mode, reverse_flg, Arr, start, mid, end);
  }
}

void consume_through_eol() {
  bool continueflg = true;

  while (continueflg) {
    char ch = (char)getchar();
    switch (ch) {
    case EOF:
    case '\n':
      continueflg = false;
      break;
    default:
      break;
    }
  }
}
      
int main (int argc, char *argv[]) {
  int size = 1048576;
  //a constant to set the size of array at 1,048,576 lines
  char **sortedWords = malloc(sizeof(char *)* size);
  int index = 0;
  enum sort_mode mode = normal;
  char buffer[max];
  bool reverse_flg = false;
  
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-?") == 0 || strcmp(argv[i], "-h")){
      printf("sort is a program that given a list of words separated by a new line through standard input will print them in alphabetic order.  use -f to fold in uppercase words or -n to numerically sort given a list with a number in front of each word.\n");
      exit(0);
    }
    if (strcmp(argv[i],"-n") == 0) {
      mode = number;
    }
    else if (strcmp(argv[i],"-f") == 0) {
      mode = folding;
    }
    else if (strcmp(argv[i],"-r") == 0) {
      reverse_flg = true;
    }
    
  }
  bool continueflg = true;
  while (continueflg) {
    int scan_matches = scanf("%1024[^\n]s", buffer);
    if (scan_matches == EOF) {
      continueflg = false;
    }
    else if (scan_matches > 0) {
      consume_through_eol();
      sortedWords[index] = malloc(strlen(buffer)+1);
      strcpy(sortedWords[index],buffer);
      index++;
    }
    else {
      consume_through_eol();
    }
  }
  mergeSort(mode, reverse_flg, sortedWords, 0, index-1);
  //prints out the list of sorted words
  for (int i=0; i < index; i++) {
    printf("%s\n", sortedWords[i]);
    free(sortedWords[i]);
  }
  free(sortedWords);
  
  return 0;
}
