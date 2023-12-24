#include <stdio.h>

void push();
void pop();
void tos();
int rear = -1;
int Array[10];

int main()
{
    int ch;
    do
    {
        printf("Enter choice 1-push,2-pop,3-tos,4-Exit :");
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
            tos();
            break;
        case 4:
            printf("Endind the program");
            return 1;
        default:
            printf("Enter valid Choice\n");
        }
    } while (ch != 4);

    return 0;
}

void push()
{
    int data;
    printf("Enter the data :");
    scanf("%d",&data);
    if (rear == sizeof(Array))
    {
        printf("\nOverflow");
    }
    else
    {
        rear++;
        Array[rear] = data;
    }
}

void pop()
{
    if (rear == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nElement popped:%d\n", Array[rear]);
        Array[rear] = 0;
        rear--;
    }
}

void tos()
{
    if (rear == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nTop of the Stack is :%d", Array[rear]);
    }
}

// To print the stack
// void print_stack()
// {
//     for (int i = 10; i >= 0; i--)
//     {
//         if (Array[i] != 0)
//         {
//             printf("\n%d", Array[i]);
//         }
//     }
// }