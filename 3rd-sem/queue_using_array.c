//To implement queue using array.
#include <stdio.h>

void enqueue(int data);
void dequeue();
void front();
void rear();
int f, r = -1;
int Array[10];

int main()
{
    enqueue(10);
    enqueue(96);
    enqueue(63);
    dequeue();
    enqueue(15);
    dequeue();
    enqueue(26);
    return 0;
}

void enqueue(int data)
{
    if (r == sizeof(Array))
    {
        printf("\nOverflow");
    }
    else
    {
        r++;
        Array[r] = data;
    }
}

void dequeue()
{
    if (r == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nElement dequeued:%d", Array[f]);
        Array[f] = 0;
        f++;
    }
}

void front()
{
    if (r == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nTop of the Stack is :%d", Array[r]);
    }
}

void rear(){
    if (r == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nTop of the Stack is :%d", Array[r]);
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