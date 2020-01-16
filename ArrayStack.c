#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
	int bottom, top, size;
	unsigned capacity;
	int* array;
};



struct Stack* createStack (unsigned capacity) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->size = stack->bottom = 0;
	stack->top = capacity - 1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull (struct Stack* stack) {
	return (stack->size == stack->capacity);
}

int isEmpty (struct Stack* stack) {
	return (stack->size == 0);
}

void put (struct Stack* stack, int item) {
       if (isFull(stack)) {
		return; 
       }
	stack->top = (stack->top + 1) % stack->capacity;
 	stack->array[stack->top] = item;
	stack->size = stack->size + 1;
	printf("%d put on top of stack\n", item);
}	

int pop (struct Stack* stack) {
	if (isEmpty(stack)) {
		return INT_MIN;
	}
	int item = stack->array[stack->top];
	stack->top = (stack->top - 1) % stack->capacity;
	stack->size = stack->size -1;
	return item;
}

int main () {
	struct Stack* stack = createStack(5);
	put(stack, 5);
	put(stack, 10);
	put(stack, 15);
	put(stack, 20);

	printf("\n");
	printf("%d popped off of stack.\n", pop(stack));
	printf("%d popped off of stack.\n", pop(stack));
}
