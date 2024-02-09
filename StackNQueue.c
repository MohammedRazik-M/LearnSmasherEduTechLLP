#include<stdio.h>
#include<stdlib.h>
#define max 20
//Global declarations...
int rear = -1;
int front = 0;
int top = -1;
int stack[max];
int queue[max];
void enqueue(int q[],int element)
{
    if(rear>=max-1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        rear+=1;
        q[rear] = element;
        printf("Element %d added successfully\n",element);
    }
}
void dequeue(int q[])
{
    if(rear<0 || front>rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Element removed from the queue: %d\n",q[front]);
        front+=1;
    }
}
void qdisplay(int q[])
{
    int i;
    printf("Elements in the queue are:\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d\t",q[i]);
    }
    printf("\n");
}
void push(int s[],int element)
{
    if(top>=max-1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top=top+1;
        s[top] = element;
        printf("Element %d pushed successfully!\n",s[top]);
    }
}
void pop(int s[])
{
    if(top<0)
    {
        printf("Stack Underflow!");
    }
    else
    {
        printf("Popped element: %d\n",s[top]);
        top=top-1;
    }
}
void sdisplay(int s[])
{
    int i;
    printf("Elements in the stack are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
}
//Stack Implementation
int main()
{
    int choice,element1,element2,ch1,ch2;
    do
    {
        //goto statement
        outsideSwitch:
            printf("Welcome to Stack --- Queue Simulator!!!\n\n");
            printf("1.Stack\t2.Queue\t3.Exit\n");
            printf("Please enter your choice:");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("\nStack Operations:\n\n");
                    do
                    {
                        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
                        printf("Enter your choice:");
                        scanf("%d",&ch1);
                        switch(ch1)
                        {
                            case 1:
                                printf("Enter the element to push:");
                                scanf("%d",&element1);
                                push(stack,element1);
                                break;
                            case 2:
                                pop(stack);
                                break;
                            case 3:
                                sdisplay(stack);
                                break;
                            case 4:
                                goto outsideSwitch;
                            default:
                                printf("Invalid choice! Please enter the correct choice.\n");
                        }
                    }while(choice<=4);
                case 2:
                    printf("\nQueue Operations:\n\n");
                    do
                    {
                        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
                        printf("Enter your choice:");
                        scanf("%d",&ch2);
                        switch(ch2)
                        {
                            case 1:
                                printf("Enter the element to insert:");
                                scanf("%d",&element2);
                                enqueue(queue,element2);
                                break;
                            case 2:
                                dequeue(queue);
                                break;
                            case 3:
                                qdisplay(queue);
                                break;
                            case 4:
                                goto outsideSwitch;
                            default:
                                printf("Invalid choice! Please enter the correct choice.\n");
                        }
                    }while(choice<=4);
                case 3:
                    printf("Thank you for using our simulator! Have a wonderful day.\n");
                    exit(0);
                default:
                    printf("Invalid choice! Please enter the correct choice.\n");
            }
        }while(choice!=3);
    return EXIT_SUCCESS;
}
