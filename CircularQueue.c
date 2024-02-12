#include<stdio.h>
#include<stdlib.h>
#define N 5
int front=-1;
int rear=-1;
int CircularQ[N];
int element;
void Enqueue(int element)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        CircularQ[rear] = element;
        printf("Element %d enqueued successfully!\n",CircularQ[rear]);
    }
    else if((rear+1)%N==front)
    {
        printf("Circular queue Overflow!\n");
    }
    else
    {
            rear = (rear+1)%N;
            CircularQ[rear] = element;
    }
}
void Dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Circular queue Underflow\n");
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Dequeued element = %d\n",CircularQ[front]);
        front = (front+1)%N;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Circular queue Underflow!\n");
    }
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%d\n",CircularQ[i]);
            i = (i+1)%N;
        }
        printf("%d\n",CircularQ[i]);
    }
}
int main()
{
    int choice;
    printf("Circular Queue!!!\n\n");
    do
    {
        printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
        printf("Please enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to insert:");
                scanf("%d",&element);
                Enqueue(element);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting Circular Queue!!!\nThank You.");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    }while(choice!=4);
    return 0;
}
