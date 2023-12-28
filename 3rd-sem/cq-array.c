#include <stdio.h>
#define MAX_SIZE 4

int arr[MAX_SIZE];

int front = -1;
int rear = -1;
int d, ch;

int isfull()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (front == 0 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue()
{
    if (isfull() == 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("Enter data: ");
        scanf("%d", &d);
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = d;
    }
}
void dequeue()
{
    if (isempty() == 1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted: %d\n", arr[front]);
        arr[front] = 0;
        front++;
    }
}
void print()
{
    printf("Circular Queue: \n");
    if (isempty() == 1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = 0; i <= (MAX_SIZE - 1); i++)
        {
            printf("|%d|\n", arr[i]);
        }
    }
}

int main()
{
    printf("Enter\n1 for insert.\t2 for delete.\n3 for print.\t4 for exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice!!\nPlease enter a valid choice\n");
        }
    } while (ch != 4);

    printf("Thanks for executing my code :-)\n");
    return 0;
}
