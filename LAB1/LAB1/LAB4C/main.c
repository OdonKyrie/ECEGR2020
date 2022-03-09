#include <stdio.h>
#include <stdlib.h>
// Data structure to represent a stack
typedef struct Stack
{
    float items;
	struct Stack* next;
} Stack;
 Stack* CurrentStack = NULL;
// Utility function to initialize the stack
Stack* newStack(float capacity)
{
	Stack *newStack = (Stack*)malloc(sizeof(Stack));
	if (newStack != NULL)
	{
    newStack->items = (capacity);
	newStack->next = NULL;
	}
    return newStack;
}
 
// Utility function to return the size of the stack
int size() {
	Stack *newStack = CurrentStack;
	int num = 0;
	while (newStack != NULL){
		num++;
		newStack = newStack ->next;
	}
	return num;
}
 
// Utility function to check if the stack is empty or not
int isEmpty() {
    return CurrentStack == NULL;
}
 
// Utility function to check if the stack is full or not
int isFull() {
    return malloc(sizeof(Stack)== NULL);
}
 
// Utility function to add an element `x` to the stack
int push(float x)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull())
    {
        printf("Stack Full!\n");
        return -1;
    }
	Stack* newNode = newStack(x);
    printf("Inserting %f\n", x);
	if(CurrentStack == NULL){
		CurrentStack == newNode;
		return 0;
	
	}
	newNode->next = CurrentStack;
	CurrentStack = newNode;
	return 0;
}
 
// Utility function to pop a top element from the stack
int pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // remove element decrement stack size by 1
    printf("Removing %f\n", CurrentStack-> items);
    Stack* temp = CurrentStack;
    CurrentStack = CurrentStack->next;
    free(temp);
    return 0;
}
// Utility function to peek at top element from the stack
int peek(float* x)
{
    // check for stack underflow
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // return top of stack value
    *x = CurrentStack->items;
    return 0;
}
 
int main()
{
    // create a stack of capacity 5
    float  value;
 
    push( 1.0);
    push( 2.0);
    push( 3.0);
 
    printf("The stack size is %d\n", size());
    peek( &value);
    printf("Top val on stack is %f\n", value);
    pop();
    pop();
    pop();
 
    if (isEmpty()) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}
