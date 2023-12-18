#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void peek();
void print();

typedef struct node
{
    int data;
    struct node *next;
} S;

int item, ch;
S *head = NULL;
S *temp = NULL;

int main()
{
    do
    {
        printf("\nEnter your choice \n 1.insert \n 2.pop \n 3.peek \n 4.print \n 5.exit \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            print();
            break;
        case 5:
            printf("Ending Program ");
            exit(0);
        default:
            printf("Enter valid option");
        }
    } while (ch != 5);
    printf("Thanks for executing my code((*_*))\n");
    return 0;
}

void push()
{
    printf("Enter element:");
    scanf("%d", &item);
    S *ptr = NULL;
    ptr = (S *)malloc(sizeof(S));
    if (ptr == NULL)
    {
        printf("Memory not exist");
        exit;
    }
    else
    {
        ptr->data = item;
        ptr->next = NULL;
        temp = head;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }
}

void pop()
{
    temp = head;
    if (head == NULL)
    {
        printf("Stackunderflow");
    }
    else
    {
        head = temp->next;
        printf("\nElement poped out:%d", temp->data);
        temp = NULL;
        free(temp);
    }
}

void peek()
{
    printf("\nTop :%d", head->data);
}

void print()
{
    temp = head;
    printf("\nElements in stack :");
    while (temp != NULL)
    {
        printf("%d,", temp->data);
        temp = temp->next;
    }
    printf("\n");
}