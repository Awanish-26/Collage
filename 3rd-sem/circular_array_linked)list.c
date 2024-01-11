#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *next;
} S;

void enqueue();
void dequeue();
void print();

S *front = NULL;
S *rear = NULL;
S *ptr = NULL;
S *temp = NULL;

int ch;
int main()
{
    printf("Enter:\n1 for insert.\t2 for delete.\t3 for print.\n4 for exit\n");
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

void enqueue()
{
    int d;
    ptr = (S *)malloc(sizeof(S));
    if (ptr == NULL)
    {
        printf("Memory not created\n");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &d);
        ptr->data = d;
        if (front == NULL)
        {
            front = rear = ptr;
            rear->next = front;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            ptr->next = front;
        }
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        if (front == rear)
        {
            printf("Deleted: %d\n", front->data);
            free(rear);
            front = rear = NULL;
        }
        else
        {
            temp = front;
            printf("Deleted: %d\n", temp->data);
            front = front->next;
            free(temp);
        }
    }
}

void print()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        do
        {
            printf("|%d|\n", temp->data);
            temp = temp->next;
        } while (temp != rear->next);
    }
}