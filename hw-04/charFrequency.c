// Nuriel Leve and Esme Rubinstein

#include <stdio.h>
#include <limits.h>
#define LENGTH 26

int main(int argc, char *argv[]){
  char letters[LENGTH] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  int freq[LENGTH];
  double perc[LENGTH];
  int cint;
  int i;
  int j;
  int sum;
  char max[LENGTH];
  char min[LENGTH];
  //initialize frequency and percentage
  for (cint = 0; cint < LENGTH; cint ++){
    freq[cint] = 0;
    perc[cint] = 0;
  }
  // count frequencies
  while ((cint = getchar()) != EOF) {
    if( 'a' <= cint && cint <= 'z'){
      freq[cint-'a']++;
    }
    else if( 'A' <= cint && cint <= 'Z'){
      freq[cint-'A']++;
    }
  }

  //find total number of letters counted and min and max freq
  sum = 0;
  j = 0;
  int minFreq = INT_MAX;
  int maxFreq = -1;
  for (i=0; i<LENGTH; i++){
    sum += freq[i];
    if (freq[i] < minFreq){
      minFreq = freq[i];
    }
    if (freq[i] > maxFreq){
      maxFreq = freq[i];
    }
  }


  //find percentages
  for (i=0; i<LENGTH; i++){
    perc[i] = ((double)freq[i]/(double)sum)*100;
  }
  
  printf("char\tFrequencies\tPercentage\n");
  for (i = 0; i < LENGTH; i++)
    printf("%c\t%d\t\t%f\n",letters[i],freq[i],perc[i]);
  printf("Minimum Letters: ");
  //find other mins and maxes
  for (i=0; i<LENGTH; i++){
    if (freq[i] == minFreq){
      min[j] = letters[i];
      printf("%c", min[j]);
    }
  }
  printf("\n");
  printf("Maximum Letters: ");
  //find other mins and maxes
  for (i=0; i<LENGTH; i++){
    if (freq[i] == maxFreq){
      max[j] = letters[i];
      printf("%c", max[j]);
    }
  }
  printf("\n");
  return 0;
}
