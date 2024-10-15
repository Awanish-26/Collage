#include <stdio.h>

#define CAPACITY 10 // Define the stack capacity

int top = -1;        // Stack top initialized to -1 (empty stack)
int stack[CAPACITY]; // Stack array

// Function to push an element into the stack
void push()
{
    if (top == CAPACITY - 1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        int value;
        printf("Please Enter a value to be pushed: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

// Function to peek the top element of the stack
void peek()
{
    if (top == -1)
    {
        printf("Please Enter value first\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Function to display the elements of the stack
void display()
{
    if (top == -1)
    {
        printf("Please enter value first\n");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Please enter value first\n");
    }
    else
    {
        printf("Value to be popped is %d\n", stack[top]);
        top--;
    }
}

// Main function to perform stack operations
int main()
{
    int choice;
    do
    {
        printf("1) Push \t2) Pop \t3) Peek \t4) Display \t5) Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
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
            display();
            break;
        case 5:
            return 0; // Exit the program
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
