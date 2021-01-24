// Nuriel & Esme
// This program adds up a sequence of positive integers, however many digits it has 
//reads in a long number and saves it in a linked list

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//a linked list representing all the data from adding up the numbers
struct BigInt {
    int digit;
    struct BigInt* next;
};

//function to create new linked list
struct BigInt* newNode(int digit){
  struct BigInt* new_node = (struct BigInt*)malloc(sizeof(struct BigInt));
  if (new_node == NULL) {
	  printf("The program could not allocate memory.");
	  exit(3);
  } else {
	  new_node->digit = digit;
	  new_node->next = NULL;
	  return new_node;
  }
}

//function to add digits to linked list
void push(struct BigInt** head_ref, int new_digit){
  struct BigInt* new_node = newNode(new_digit);
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

//function to add two linked lists
struct BigInt* addTwoLL(struct BigInt* Total, struct BigInt* big_num){
  struct BigInt* result = NULL;
  struct BigInt *temp, *prev = NULL;
  int carry = 0, sum;

  while (Total != NULL || big_num != NULL){
    sum = carry + (Total ? Total->digit : 0) + (big_num ? big_num->digit : 0);
    carry = (sum >= 10) ? 1: 0;
    sum = sum % 10;
    temp = newNode(sum);
    if (result == NULL){
      result = temp;
    }
    else{
      prev->next = temp;
    }
    prev = temp;
    if (Total) {
      Total = Total->next;
    }
    if (big_num) {
      big_num = big_num->next;
    }
  }
    if (carry > 0){
    temp->next = newNode(carry);
    }
  return result;
}

//prints the list in reverse because push was added with most significant digit first
void printReverse(struct BigInt* head){
  //base case for recursion
  if (head == NULL){
    return;
  }
  printReverse(head->next);
  printf("%d", head->digit);
}

struct BigInt *read_num() {
  char ch;
  struct BigInt* big_num = NULL;
  while(true){
    ch = getchar();
    if(isdigit(ch) || (ch == '\n') || (ch == EOF)) {
      break;
    }
  }
  if (isdigit(ch) && ch != '0'){
    push(&big_num, (ch-'0'));
    while (true) {
      ch = getchar();
      if (isdigit(ch)) {
	push(&big_num, (ch - '0'));
      }
      else{
	break;
      }
    }
  }
  //skip to eol or eof
  while ((ch != '\n') && (ch != EOF)){
    ch = getchar();
  }
  //if no digits found and at the end of line, return 0
  if ((big_num == NULL) && (ch == '\n')) {
    push(&big_num, 0);
  }
  return big_num;
}

//frees each node in the linked list 
void freeList(struct BigInt* list) {
	struct BigInt* tmp;
	while (list != NULL) {
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int main() { 
  int c;
  struct BigInt* Total = NULL;
  struct BigInt* big_num = NULL;
  while ((big_num = read_num()) !=NULL){
    Total = addTwoLL(Total, big_num);
    printf("Total: ");
    printReverse(Total);
    printf("\n");
  }
    freeList(Total);
    freeList(big_num);
  return 0;
}

    




