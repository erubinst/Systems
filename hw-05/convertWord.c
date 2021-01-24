// program that takes a word in a file and converts it to or out of pig latin
// Esme Rubinstein and Nuriel Leve

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Checks to see if a character is either a lowercase vowel or and
// uppercase vowel
bool vowelP(char ch){
  return (ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' || ch == 'A'|| ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y') ;
}

// Returns the position of the first vowel found in the
// string. Consecutive 'q' and 'u' are treated as a single consonant
// and the 'u' will not be interpreted as a vowel
int firstVowelPos(char* str){
  bool precedingQ = false;
  for (int i = 0; i<strlen(str); i++) {
    // There was preceding 'q' and now there is a following 'u'.
    // Treat them as a consonant.
    if (precedingQ && (str[i] == 'u' || str[i] == 'U')) {
      precedingQ = false;
    }
    // A 'q' was encountered.
    else if (str[i] == 'q' || str[i] == 'Q') {
      precedingQ = true;
    }
    // No 'q' or 'qu', so check for a vowel.
    else if (vowelP(str[i])) {
      return i;
    }
    // if you get here, then the character isn't a vowel or a 'q', so
    // make sure that the precedingQ flag is false.
    else {
      precedingQ = false;
    }
  }
  return -1;
}

// Reads a word in from stdin and converts it to piglatin.
char * convertWord(){
  char str[100], beforeFirstVowel[100], *newString;
  int len, firstVowelIndex, index;
  bool uppercasep[100];

  // The pattern %[A-Za-z] tells scanf to keep reading characters in
  // as long at they are letters
  if(scanf("%[A-Za-z]", str) == 1){
    len = strlen(str);
    // uppercasep is an array of booleans that remembers the positions
    // of the characters in the original string that are capital.
    for (int i = 0; i < len; i++) {
      if (isupper(str[i])) {
	uppercasep[i] = true;
	str[i] = tolower(str[i]);
      }
      else {
	uppercasep[i] = false;
      }
    }
    // Test if the first charact is a 'y'.  If so, then treat it as a
    // consonant.
    if (str[0] == 'y' || str[0] == 'Y') {
      // Since it starts with 'y', search for the first vowel starting
      // with the second character in the string.  We use & on that
      // character to get the pointer to the string starting with the
      // second character.
      firstVowelIndex = firstVowelPos(&str[1]);
      if (firstVowelIndex != -1) {
	// if a vowel is found, then add 1 rto the found index to
	// account for starting at the second character of the string.
	firstVowelIndex++;
      }
    }
    else {
      // No starting 'y', so look for the first vowel starting at the
      // beginning.
      firstVowelIndex = firstVowelPos(str);
    }
    // No vowel is found, add "yay"
    if (firstVowelIndex == 0) {
      newString = (char*)malloc(sizeof(str) + 3);
      strcpy(newString, str);
      strcat(newString,"yay");
    }
    // A vowel is found, so swap letters around the vowel and add
    // "ay".
    else if (firstVowelIndex > 0) {
      newString = (char*)malloc(sizeof(str) + 2);
      // Copy the substring in the original string starting with the
      // firstVowel to newString.
      strcpy(newString, &str[firstVowelIndex]);
      // Copy the the substring in the original string that starts at
      // the beginning and goes up to the first vowel.
      strncat(newString, str, firstVowelIndex);
      // Add the null terminator because strncat does not ensure that
      // the string is null terminated.
      newString[len] = '\0';
      // Add the "ay" suffix.
      strcat(newString, "ay");
    }
    // No vowels are found, so just return the original string.
    else {
      newString = (char*)malloc(sizeof(str));
      strcpy(newString, str);
    }
    // Use the uppercasep boolean array to restore the original
    // capitalizations by capitalizing the characters that are in the
    // positions that were capitalized in the original string.
    for (int i = 0; i < len; i++) {
      if (uppercasep[i]) {
	newString[i] = toupper(newString[i]);
      }
    }
  }
  else {
    newString = "";
  }
  return newString;
}



	  
      


