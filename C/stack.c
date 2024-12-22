#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Stack {
	int data[10];
	int top;
};

typedef struct Stack stack;

int isEmpty(stack *s) {
	if(s->top == -1) {
		return 1;
	}
	return 0;
}

int isFull(stack *s) {
	if(s->top == MAX - 1) {
		return 1;
	}
	return 0;
}

void display_stack(stack *s) {
	if(isEmpty(s)) {
		printf("The stack is empty!\n");
		return;
	}
	for(int i = s->top; i >= 0; i--) {
		printf("-- %d --\n", s->data[i]);
	}
}

void push(stack *s) {

	if(isFull(s)) {
		printf("The stack is full!\n");
	}
	else {
		int new_data;
		printf("Enter the data to enter : ");
		scanf("%d", &new_data);
		s->top++;
		s->data[s->top] = new_data;
		printf("New data added successfully!\n");
	}
}

void pop(stack *s) {
	if(isEmpty(s)) {
		printf("The stack is Empty!\n");
	}
	else {
		s->top--;
		printf("The top data popped out successfully!\n");
	}
}

void create_Empty_Stack(stack **s) {
	*s = (stack *)malloc(sizeof(stack));
	(*s)->top = -1;
}

void reverse_stack(stack **s) {
	stack *temp = (stack *)malloc(sizeof(stack));
	create_Empty_Stack(&temp);
	for(int i = (*s)->top; i >= 0; i--) {
		temp->top++;
		temp->data[temp->top] = (*s)->data[i];
	}
	free(*s);
	*s = temp;
	printf("Stack reversed successfully!\n");
}

int main() {
	stack *s;	

	create_Empty_Stack(&s);

	int choice = 0;
	while(choice != 6) {
		printf("\
	Enter your choice:\n\
	1. Display Stack\n\
	2. Push Data\n\
	3. Pop Data\n\
	4. Reverse Data\n\
	5. Empty Stack\n\
	6. Exit\n");
		scanf("%d", &choice);
		// getchar();
		system("clear");

		switch(choice) {
		case 1: display_stack(s);
			break;
		case 2: push(s);
			break;
		case 3: pop(s);
			break;
		case 4: reverse_stack(&s);
			break;
		case 5: s->top = -1;
			break;
		case 6:
			free(s);
			break;
		default:
			printf("Invalid choice!");
		}
	}
	return 0;
}
