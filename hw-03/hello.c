// Esme Rubinstein and Nuriel Leve
// 
// Hello World program that is complied and executed to print 'Hello World!' 
// If you don't give any argument's, it will just print hello world; if the
// user gives it one or more arguments, it will print 'hello [arg]' with args
// being the name the user entered 


#include <stdio.h>

int main(int argc, char **argv) {

  int num1 = 5; 
  int num2 = 2;
  float num3 = 5.5;
  if (argc == 1) {
    printf("Hello %d worlds!\n", num1);
    printf("Hello %3d worlds!\n", num2);
    printf("Hello %f worlds!\n", num3);
    printf("Hello %4.7f worlds!\n", num3);
    printf("Hello %.7f worlds!\n", num3);
  } else {
    for (int idx = 0; idx < argc; ++idx)
      printf("Hello %s!\n", argv[idx]);
  }
  return 0;

}


