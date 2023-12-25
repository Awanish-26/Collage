// implementation of queue using linked list
#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void front();
void rear();

typedef struct node{
    int data;
    struct node *next;
} S;

S *head=NULL;
S *temp=NULL;

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
            printf("Enter valid Choice\n");
        }
    } while (ch != 5);

    return 0;
}

// insertion in queue
void enqueue(){
    int data;
    printf("Enter tha t data to insert:");
    scanf("%d",&data);
    S *ptr=NULL;
    ptr=(S *)malloc(sizeof(S));
    if (ptr==NULL){
        printf("Memory don't exists");
    }
    else{
        if (head==NULL){
            ptr->data=data;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            ptr->data=data;
            ptr->next=head;
            head=ptr;
        }
    }
}

// deletion in queue
void dequeue(){
    if (head==NULL){
        printf("\n No element in the queue\n");
    }
    else{
        temp = head;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        S * temp2=temp->next;
        temp->next=NULL;
        printf("\n Dequeued:%d \n",temp2->data);
        temp2=NULL;
        free(temp2);
    }
}

// front element
void front(){
    if (head==NULL){
        printf("\nNo element in queue\n");
    }
    else{
        printf("\nFront elemnt is:%d\n",head->data);
    }
}

// rear element
void rear(){
    if (head==NULL){
        printf("\nNo element in queue\n");
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("\nRear elemnt is:%d\n",temp->data);
    }
}