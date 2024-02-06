#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *next;
} S; // s will act as declared datatype

// function declartion
void insert();
void insert_at_beg();
void insert_in_btw();
void insert_at_end();
void delete();
void delete_at_beg();
void delete_in_btw();
void delete_at_end();
void print();

// commnly used variables
int d, ch, pos;
static int count;

// commnly used pointers
S *head = NULL;
S *temp = NULL;
S *temp2 = NULL;

// Main function
int main()
{
    do
    {
        printf("\nEnter:\n1 for insert.\n2 for delete.\n3 for print.\n4 for exit.\n");
        printf("Enter your choice :");
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
            printf("Invalid choice!!\n");
        }
    } while (ch != 4);
    printf("Thanks for executing my code((⊙◡⊙))\n");
    return 0;
}

// Insertion operations
void insert()
{
    int C;
    printf("\n\nEnter where you want to insert:\n1 for insertion at beg.\n2 for insertion in between.\n3 for insertion at end.\n4 for exit.\n");
    scanf("%d", &C);
    switch (C)
    {
    case 1:
        insert_at_beg();
        break;
    case 2:
        insert_in_btw();
        break;
    case 3:
        insert_at_end();
        break;
    case 4:
        exit(0);
    default:
        printf("Invalid choice!!\nPlease enter a valid choice\n");
    }
}
// Insertion at begninng
void insert_at_beg()
{
    S *ptr = NULL;
    ptr = (S *)malloc(sizeof(S));
    if (ptr == NULL)
        printf("Memory not created\n");
    else
    {
        printf("Enter a value to insert at the beginning :");
        scanf("%d", &d);
        ptr->data = d;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
            temp = head;  // unused
            temp2 = head; // unused
            count++;
        }
        else
        {
            ptr->next = head;
            head = ptr;
            count++;
        }
    }
}

// Insertion in between
void insert_in_btw()
{
    S *ptr = NULL;
    ptr = (S *)malloc(sizeof(S));
    if (ptr == NULL)
        printf("Memory not created\n");
    else
    {
        int item;
        printf("Enter the data after which you want to insert position of the new node:");
        scanf("%d", &item);
        printf("Enter the data which you want to insert:");
        scanf("%d", &d);
        ptr->data = d;
        ptr->next = NULL;
        temp2 = head;
        while (temp2->data != item)
        {
            temp2 = temp2->next;
        }
        ptr->next = temp2->next;
        temp2->next = ptr;
        count++;
    }
}

// Insertion at end
void insert_at_end()
{
    S *ptr = (S *)malloc(sizeof(S));
    if (ptr == NULL)
        printf("Memory not created\n");
    else
    {
        printf("Enter a value to insert at the end:");
        scanf("%d", &d);
        ptr->data = d;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
            temp2 = head; // unused code
            temp = head;
            count++;
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            count++;
        }
    }
}

// Deletion operations
void delete()
{
    int C;
    printf("\n\nEnter where you want to delete:\n1 for deletion at beg.\n2 for deletion in between.\n3 for deletion at end.\n4 for exit.\n");
    scanf("%d", &C);
    switch (C)
    {
    case 1:
        delete_at_beg();
        break;
    case 2:
        delete_in_btw();
        break;
    case 3:
        delete_at_end();
        break;
    case 4:
        break;
    default:
        printf("Invalid choice!!\nPlease enter a valid choice\n");
    }
}

// Deletion in beginning.
void delete_at_beg()
{
    if (head == NULL)
        printf("Stack Underflow\n");
    else
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        printf("Deleted: %d\n", temp->data);
        free(temp);
        temp = NULL;
    }
}

// Deletion in between.
void delete_in_btw()
{
}

// Deletion at end.
void delete_at_end()
{
    if (head == NULL)
        printf("Stack Underflow\n");
    else
    {
        temp = head;
        if (temp->next == NULL)
        {
            delete_at_beg();
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp2 = temp->next;
            temp->next = NULL;
            printf("Deleted: %d", temp2->data);
            temp2 = NULL;
            free(temp2);
        }
    }
}

void print()
{
    temp = head;
    printf("\nLinked list :");
    while (temp != NULL)
    {
        printf(" %d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}