/*Objective:- Implementation of Queue using array.
  Discription:-This program consist of a Queue having front and rear value a 0 and consist
 of 4 function name Inqueue(), Dequeue(), Display() in which Inqueue function add the value in
 queue and Dequeue function delete the value in circular queue and Display function dispaly the element and tell the size of circular queue
 */
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

int front = 0, rear = 0;
int Queue[CAPACITY];

// Function to add element to the queue (enqueue)
void Enqueue()
{
    if ((rear + 1) % CAPACITY == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        int num;
        printf("Please Enter a number to Enqueue: ");
        scanf("%d", &num);
        Queue[rear] = num;
        rear = (rear + 1) % CAPACITY;
    }
}

// Function to display the elements in the queue
void Display()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements of Queue are: ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", Queue[i]);
            i = (i + 1) % CAPACITY;
        }
        printf("\n");
    }
}

// Function to remove element from the queue (dequeue)
void Dequeue()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Element to be dequeued: %d\n", Queue[front]);
        front = (front + 1) % CAPACITY;
    }
}

int main()
{
    int choice;
    printf("\nQueue operations:\n");
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
