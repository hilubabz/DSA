#include<stdio.h>
#define MAX 5
int A[MAX];
int rear = 0, front=0;
void enqueue() {
    
    if (rear == MAX) {
        printf("Queue is full");
    }
    else {
        printf("Enter new element to be enqueud :");
            scanf("%d", &A[rear++]);
    }
}
void dequeue() {
    int i;
    if ((front) == rear) {
        printf("Queue is empty");
    }
    else {
        printf("%d\n", A[front]);
        front++;
     
        for (i = front ;i < rear;i++) {
            A[i - 1] = A[i];
        }
        rear--;
        front--;
    }
}
void display() {
    int i;
    if ((front) == rear) {
        printf("Empty queue");
    }
    else {
        for (i = front;i < rear;i++) {
            printf("%d\n", A[i]);
        }
    }
}
int main() {
    int n = 0,choice;
    printf("What do you want to do\n1. for enqueue\n2. for dequeue\n3. for display\n 4. for exit\n");
    while(choice!=4) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid value");
            break;
        }
    }
    return 0;
}
