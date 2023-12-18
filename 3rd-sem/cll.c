#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *next;
} S;

void insert();
void delete();
void print();

struct n *head = NULL;
S *temp = NULL;
S *temp2 = NULL;
S *P = NULL;
int ch, d;

int main()
{
    printf("Enter:\n1 for insert\t2 for delete\t3 for print\n4 for exit\n");
    do
    {
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            print();
            break;
        case 4:
            break;
        default:
            printf("Invlaid choice!!\n");
        }
    } while (ch != 4);
    printf("Thanks for executing my code('-')\n");
    return 0;
}

void insert()
{
    P = (S *)malloc(sizeof(S));
    if (P == NULL)
    {
        return;
    }
    else
    {
        printf("Enter the value to enter\n");
        scanf("%d", &d);

        P->data = d;
        P->next = NULL;
        if (head == NULL)
        {
            head = P;
            P->next = head;
            temp = head;
        }
        else
        {
            temp->next = P;
            P->next = head;
            temp = P;
        }
    }
}
void delete()
{
    temp2 = temp;
    temp = head;
    while (temp->next != temp2)
    {
        temp = temp->next;
    }
    temp->next = head;
    printf("Deleted: %d\n", temp2->data);
    free(temp2);
    temp2 = NULL;
}
void print()
{
    temp2 = head;
    do
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    } while (temp2 != head);
    temp2 = NULL;
    printf("\n");
}