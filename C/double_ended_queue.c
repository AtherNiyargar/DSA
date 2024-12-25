#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int isFull(int **front, int **rear) {
	if((**rear + 1) % SIZE == **front) {
		return 1;
	}
	return 0;
}

void enqueue_front(int *front, int *rear, int *arr) {
	if(isFull(&front, &rear)) {
		printf("The queue if full! Can't Enqueue.\n");
		return;
	}
	else if(*front == -1) {
		*front = *rear = 0;
	}
	else if(*front == 0) {
		*front = SIZE - 1;
	}
	else {
		(*front)--;
	}
	int new_data;
	printf("Enter the value to enqueue : ");
	scanf("%d", &new_data);
	arr[*front] = new_data;
}

void enqueue_rear(int *front, int *rear, int *arr) {
	if(isFull(&front, &rear)) {
		printf("The queue if full! Can't Enqueue.\n");
		return;
	}
	else if(*rear == -1) {
		*front = *rear = 0;
	}
	else {
		*rear = (*rear + 1) % SIZE;
	}
	int new_data;
	printf("Enter the value to enqueue : ");
	scanf("%d", &new_data);
	arr[*rear] = new_data;
}

void display(const int front, const int rear, const int *arr) {
	if(front == -1) {
		printf("The queue is empty!\n");
		return;
	}

	int i;
	for(i = front; i != rear; i = (i + 1) % SIZE) {
		printf("|%d|-", arr[i]);
	}
	printf("|%d|\n", arr[i]);
}

void dequeue_front(int *front, int *rear, int *arr) {
	if(*front == -1) {
		printf("The queue is empty!\n");
		return;
	}
	else if((*front + 1) % SIZE == *rear) {
		*front = *rear = -1;
	}
	else
		*front = (*front + 1) % SIZE;
}

void dequeue_rear(int *front, int *rear, int *arr) {
	if(*front == -1) {
		printf("The queue is empty!\n");
		return;
	}
	else if((*front + 1) % SIZE == *rear) {
		*front = *rear = -1;
	}
	else {
		if(*rear == 0) {
			*rear = SIZE - 1;
		}
		else {
			(*rear)--;
		}
	}
}

void peek(const int front, const int rear, const int *arr) {
	printf("Front -> %d | Rear -> %d\n", arr[front], arr[rear]);
}

int size(const int front, const int rear) {
	if(front == -1)
		return 0;
	int size = 0;
	for(int i = front; i != rear; i = (i + 1) % SIZE)
		size++;
	return size+1;
}

int main() {

	int front = -1,
		  rear = -1;

	int *arr = (int *)malloc(sizeof(int) * SIZE);

	int choice;
	while(1) {
		printf("\
	1. Enqueue Front\n\
	2. Enqueue Rear\n\
	3. Dequeu Front\n\
	4. Dequeue Rear\n\
	5. Display\n\
	6. Peek\n\
	7. Size : \n\
	8. Exit\n");
		scanf("%d", &choice);
	switch(choice) {
		case 1: enqueue_front(&front, &rear, arr);
			break;
		case 2: enqueue_rear(&front, &rear, arr);
			break;
		case 3: dequeue_front(&front, &rear, arr);
			break;
		case 4: dequeue_rear(&front, &rear, arr);
			break;
		case 5: display(front, rear, arr);
			break;
		case 6: peek(front, rear, arr);
			break;
		case 7: printf("The size of the array is %d\n", size(front, rear));
			break;
		case 8: free(arr);
			break;
		default: printf("Invalid choice!\n");
			break;
		}
	}
	return 0;
}
