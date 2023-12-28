// To implement queue using array.
#include <stdio.h>

void enqueue();
void dequeue();
void front();
void rear();
int f, r = -1;
int Array[10];

int main()
{
    int ch;
    do
    {
        printf("Enter choice 1-Enqueue,2-Dequeue,3-front,4-Rear,5-Exit:");
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
            front();
            break;
        case 4:
            rear();
            break;
        case 5:
            printf("Endind the program");
            return 1;
        default:
            printf("Enter valid Choice");
        }
    } while (ch != 4);

    return 0;
}

void isEmpty()
{
}
void isFull()
{
}
void enqueue()
{
    int data;
    printf("Enter the data:");
    scanf("%d", &data);
    if (r == sizeof(Array) && r == f + 1)
    {
        printf("\nOverflow\n");
    }
    else
    {
        int i = 0;
        if (r == sizeof(Array) && f > -1)
        {
            while (Array[i] != 0)
            {
                i++;
            }
            r = Array[i];
            Array[r] = data;
        }
        else
        {
            r++;
            Array[r] = data;
        }
    }
}

void dequeue()
{
}

void front()
{
}

void rear()
{
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