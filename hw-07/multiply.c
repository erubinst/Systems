// Nuriel & Esme
// This program multiplies a sequence of positive integers, however many digits it has 


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//a linked list representing all the data from adding up the numbers
struct BigInt {
  int digit;
  struct BigInt *next;
};

//function to create new linked list
struct BigInt* newNode(int digit){
  struct BigInt* new_node = (struct BigInt*)malloc(sizeof(struct BigInt ));
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

// Function to reverse the linked list and return 
// its length 
int reverse(struct BigInt** head_ref) 
{ 
    struct BigInt* prev = NULL; 
    struct BigInt* current = *head_ref; 
    struct BigInt* next; 
    int len = 0; 
    while (current != NULL) { 
        len++; 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
    return len; 
}

// Function to make an empty linked list of 
// given size 
struct BigInt* make_empty_list(int size) 
{ 
    struct BigInt* head = NULL; 
    while (size--) 
        push(&head, 0); 
    return head; 
} 
  
int findLength(struct BigInt* head_ref) {
	int len = 0;
	struct BigInt* curr = head_ref;
	while (curr != NULL) {
		len++;
		curr = curr->next;
	}
	return len;
}

// Multiply contents of two linked lists => store in another list and return its head 
struct BigInt* multiplyTwoLists(struct BigInt* first, 
                           struct BigInt* second) 
{ 
    int m = reverse(&first), n = findLength(second); 
  
    struct BigInt* result = make_empty_list(m + n + 1); 
  
    struct BigInt *second_ptr = second, *result_ptr1 = result, *result_ptr2, *first_ptr; 
    // multiply each Node of second list with first 
    while (second_ptr) { 
        int carry = 0;
	result_ptr2 = result_ptr1; 
        first_ptr = first;  
        while (first_ptr) {
	  int mul = first_ptr->digit * second_ptr->digit + carry; 
            result_ptr2->digit += mul % 10; 
            carry = mul / 10 + result_ptr2->digit / 10; 
            result_ptr2->digit = result_ptr2->digit % 10; 
            first_ptr = first_ptr->next; 
            result_ptr2 = result_ptr2->next; 
        }   
        if (carry > 0) { 
            result_ptr2->digit += carry; 
        } 
        result_ptr1 = result_ptr1->next; 
        second_ptr = second_ptr->next; 
    } 
   reverse(&result);
    while (result->digit == 0){ 
        struct BigInt* temp = result; 
        result = result->next; 
        free(temp);  
    } 
    // Return head of multiplication list 
    return result; 
} 

//function to print out total multiplied linked list
void printList(struct BigInt* Total) {
  while (Total != NULL) {

    printf("%d", Total->digit);
    Total = Total->next;
  }
}

void printReverse(struct BigInt* head) { 
  // Base case   
  if (head == NULL) 
    return; 
  
  // print the list after head node 
  printReverse(head->next); 
  
  // After everything else is printed, print head 
  printf("%d", head->digit); 
}

struct BigInt *read_num() {
  char ch;
  struct BigInt* big_num = NULL;

  // Skip until digit.
  while (true) {
    ch = getchar();
    if (isdigit(ch) || (ch == '\n') || (ch == EOF)) {
      break;
    }
  }
  // If digit found, read in number.
  if (isdigit(ch) && ch != '0') {
    push(&big_num,(ch - '0'));
    while (true) {
      ch = getchar();
      if (isdigit(ch)) {
	push(&big_num,(ch - '0'));
	int c = ch - '0';
      }
      else {
	break;
      }
    }
  }
  // Skip to either EOL or EOF.
  while ((ch != '\n') && (ch != EOF)) {
    ch = getchar();
  }
  //if no digits found and at EOL, return 0. 
  if ((big_num == NULL) && (ch == '\n')) {
    push(&big_num,0);
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
  push(&Total, 1);
  struct BigInt* temp = NULL;
  struct BigInt* big_num = NULL;
  while ((big_num = read_num()) != NULL) {
	  temp = multiplyTwoLists(Total, big_num);
	  freeList(Total);
	  Total = temp;
	  printf("Total: ");
	  printList(Total);
	  printf("\n");
	  freeList(big_num);
  }
  freeList(Total);
  return 0;
}
