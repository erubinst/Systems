1. Esme Rubinstein and Nuriel Leve (10/20/2020)

2. A list of the programs with descriptions

charFrequency.c: takes in a text file through stdin and reports frequency and percentages of chars a-z in the file.  keeps track of minimum and maximum chars and prints it at the end

encode_bits.c: this program reads in one character at a time and calls print_bits() to output the character in binary form (sequence of '0's and '1's)

decode_bits.c: this program reads in one character at a time from a sequence of '0's and '1's and call decode_bits() to output the characters actual value 

bits.c: this program contains 2 functions, print_bits() and decode_bits(), that outputs a value in binary format and outputs that corresponding character value, respectively; both functions are called in the two programs above, encode_bits.c and decode_bits.c

getnum.c: getnum.c takes in an int of any format and converts it to a long 

tobinary.c: this program reads in a sequence of numbers and outputs the signed value, one per line ,in binary format (with leading 0b).  Please note that for when this program is given a number 0, it will just print out 0, not 0b0. 

todecmial.c:this program reads in a sequence of numbers and outputs the signed value, one per line, in base 10 (with no leading 0)

tooctal.c: this program reads in a sequence of numbers and outputs the singed value, one per line, in base 8 (with a single leading 0)

tohex.c: this program reads in a sequence of numbers and outputs them one per line in signed value in base 16 (with a leading 0x). similar to binary case, the 0 input will just give a 0 output, not 0x0.

3. my getnum can take in an int in any of the four formats, where hex starts with 0x, ooctal starts with a leading 0, and binary starts with a 0b.  I assumed that octals were any numbers with a leading zero where the following numbers were less than 7.  One section of the lab said that decimals would not have a leading zero and another section said they would, so I just made it so that if there was a number like 0984, it would take it in as a decimal.  For binary, the code just checks if the digits are 0 or 1, for octal and decimal it just checks if the entry isdigit.  for hex, I used the isxdigit function thats included in <ctype.h>.

4. No compilation problems, warnings, or errors.

5. No valgrind errors to our knowledge

6. It took about 5 hours for Part 1, 4 hours for Part 2, and 4 hours for Part 3. It took another hour or so to test and check that all of our code was running correcty.  

7. I affirm that I have adhered to the Honor Code in this assignment.
