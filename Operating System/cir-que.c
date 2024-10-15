#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

int front = -1, rear = -1;
int Queue[CAPACITY];

// Function to check if the queue is full
int isFull()
{
    return (front == (rear + 1) % CAPACITY);
}

// Function to check if the queue is empty
int isEmpty()
{
    return (front == -1);
}

// Function to add element to the queue (enqueue)
void Enqueue()
{
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        int num;
        printf("Please Enter a number to Enqueue: ");
        scanf("%d", &num);
        if (isEmpty()) // First element insertion
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % CAPACITY;
        }
        Queue[rear] = num;
    }
}

// Function to display the elements in the queue
void Display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements of Queue are: ");
        int i = front;
        while (1)
        {
            printf("%d ", Queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % CAPACITY;
        }
        printf("\n");
    }
}

// Function to remove element from the queue (dequeue)
void Dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Element to be dequeued: %d\n", Queue[front]);
        if (front == rear) // Queue has only one element
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % CAPACITY;
        }
    }
}

int main()
{
    int choice;
    printf("\nCircular Queue operations:\n");
    printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            printf("Bye Bye\n");
            exit(0);
        default:
            printf("Enter a valid input\n");
        }
    } while (choice != 4);
    return 0;
}

// Circular Queue operations:
// 1) Enqueue
// 2) Dequeue
// 3) Display
// 4) Exit
// Enter your choice: 1
// Please Enter a number to Enqueue: 56
// Enter your choice: 1
// Please Enter a number to Enqueue: 23
// Enter your choice: 1
// Please Enter a number to Enqueue: 55
// Enter your choice: 1
// Please Enter a number to Enqueue: 66
// Enter your choice: 1
// Please Enter a number to Enqueue: 54
// Enter your choice: 1
// Please Enter a number to Enqueue: 54
// Enter your choice: 1
// Queue is full
// Enter your choice: 2
// Element to be dequeued: 56
// Enter your choice: 3
// Elements of Queue are: 23 55 66 54
// Enter your choice: 4
// Bye Bye