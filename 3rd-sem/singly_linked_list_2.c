#include <stdio.h>
#include <stdlib.h>

void insert();
// void delete();
void print();
void insertionbeg();
void deletebeg();
void insertatend();
void deleteatend();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;

int main()
{
    int ch;
    do
    {
        printf("Enter choice 1-Insert,2-Delete,3-Print,4-Exit :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            deletebeg();
            break;
        case 3:
            print();
            break;
        case 4:
            printf("Endind the program");
            return 1;
        default:
            printf("Enter valid Choice");
        }
    } while (ch != 4);

    return 0;
}

void insert()
{
    int d;
    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory not created");
    }
    else
    {
        printf("Enter data :");
        scanf("%d", &d);
        if (head == NULL)
        {
            ptr->data = d;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            head->next = ptr;
            ptr->data = d;
            ptr->next = NULL;
        }
    }
}

void insertionbeg()
{
    int d;
    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Not Created");
    }
    else
    {
        scanf("%d", &d);
        ptr->data = d;
        ptr->next = NULL;
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

void deletebeg()
{
    if (head == NULL)
    {
        printf("Not Exit");
    }
    else
    {
        temp = head;
        head = head;
        free(temp);
    }
}

void print()
{
    if (head == NULL)
    {
        printf("Not Exit");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}

void insertatend()
{
    int d;
    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Doesn't exist");
    }
    else
    {
        scanf("%d", &d);
        ptr->data = d;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
}

void deleteatend()
{
    if (head == NULL)
    {
        printf("Doesn't exist");
    }
    else
    {
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
