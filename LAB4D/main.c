#include <stdio.h>
#include <stdlib.h>

// Data structure to represent a queue
typedef struct Queue
{
    float items;
	struct Queue* next;
} Queue;
 
Queue* headNode = NULL;
// Utility function to initialize the queue
Queue* newQueue(int cap)
{
    Queue *newNode = (Queue*)malloc(sizeof(Queue));
	if( newNode != NULL){

		newNode -> items = cap;
		newNode->next = NULL;
	}
    return newNode;
}
 
// Utility function to return the size of the queue
int size() {
    Queue *newNode = headNode;
	int i = 0;
	while(newNode != NULL){
		i++;
		newNode = newNode-> next;
	}
	return i;
}
 
// Utility function to check if the queue is empty or not
int isEmpty() {
	Queue* temp = headNode;
	free(temp);
    return headNode == NULL;
}
 
// Utility function to check if the queue is full or not
int isFull() {
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	free(temp);
    return (malloc(sizeof(Queue)) == NULL);
}
 
// Utility function to add an element `x` to the queue
int insert(float x)
{
    // check if the queue is already full
    if (isFull())
    {
        printf("Queue Full!\n");
        return -1;
    }
	
	Queue* newNode = newQueue(x);
	
    printf("Inserting %f\n", x);
	if(headNode == NULL){
		headNode = newNode;
		return 0;
	}
	Queue* currentNode = headNode;
	while(currentNode -> next != NULL){
		currentNode = currentNode -> next;
	}
    // add an element and increment the top's index
    currentNode->next = newNode;
	newNode-> next = NULL;
    return 0;
}
 
// Utility function to remove an element from the queue
int delete()
{
    // check for queue underflow
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // remove element decrement queue size by 1
    printf("Removing %f\n", headNode->items);
	Queue* temp = headNode;
	headNode = headNode->next;
	free(temp);
	
    return 0;
}
 
// Utility function to peek at first element from the queue
int peek(float* x)
{
    // check for queue underflow
    if (isEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // return top of queue value
    *x = headNode->items;
    return 0;
}
 
int main()
{
    float value;
 
    insert(1.0);
    insert(2.0);
    insert(3.0);
 
    printf("The queue size is %d\n", size());

    peek(&value);
    printf("Top val on queue is %f\n", value);

    delete();
    delete();
    delete();
 
    if (isEmpty()) {
        printf("The queue is empty");
    }
    else {
        printf("The queue is not empty");
    }
 
    return 0;
}