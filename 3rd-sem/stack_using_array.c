#include <stdio.h>

void push(int data);
void pop();
void tos();
int rear = -1;
int Array[10];

int main()
{
    push(10);
    push(96);
    push(63);
    tos();
    pop();
    tos();
    push(15);
    pop();
    push(26);
    tos();
    return 0;
}

void push(int data)
{
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
        printf("\nElement popped:%d", Array[rear]);
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