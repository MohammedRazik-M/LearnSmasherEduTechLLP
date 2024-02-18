#include<stdio.h>
#include<stdlib.h>
#define max 20

//Global declarations

int array[max];
int i;
int j;
int n;
int choice;
int element;
int d_element;
int key;
int pos;
int len;

//Function initialization

void display()
{
    printf("Array elements:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}
void create()
{
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Array created successfully!\n");
}
int insert()
{
    printf("Enter the element to insert:");
    scanf("%d",&element);
    printf("Enter the position to  insert:");
    scanf("%d",&pos);
    if(n == max)
    {
        printf("Array is full!\n");
        return n;
    }
    else if(n == 0)
    {
        printf("Array is empty!\n");
        return 0;
    }
    else if(pos-1 == n )
    {
        array[pos-1] = element;
        n = n+1;
        return n;
    }
    else if(pos > n)
    {
        printf("Out of range!\n");
        return n;
    }
    else
    {
        for(i=n ;i>=pos-1;i--)
        {
            array[i+1] = array[i];
        }
        array[pos-1] = element;
        n = n+1;
        return n;
    }
}
int del()
{
    printf("Enter the position to delete:");
    scanf("%d",&d_element);
    for(i=d_element-1;i<n;i++)
    {
        array[i] = array[i+1];
    }
    n = n-1;
    return n;
}
void search()
{
    int flag = 0;
    printf("Enter the element to search : ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(array[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if(flag!=0)
    {
        printf("Element %d found at position : %d\n",key,(i+1));
    }
    else
    {
        printf("Element %d not found!\n");
    }
}
void sort()
{
    for(i=1;i<n;i++)
    {
        key = array[i];
        j = i-1;
        while(j>=0 && array[j] > key)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
    printf("Array sorted successfully!\n");
}

//Driver's code

int main()
{
    do
    {
        printf("------Array Operations------\n\n");
        printf("Note : Maximum array capacity is %d!\n\n",max);
        printf("1.Creation\n2.Insertion\n3.Deletion\n4.Searching\n5.Sorting\n6.Exit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the number of array elements:");
                scanf("%d",&n);
                create();
                display();
                break;
            case 2:
                n = insert();
                display();
                break;
            case 3:
                n = del();
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                sort();
                display();
                break;
            case 6:
                printf("Exiting...\nThank You!");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid one.\n");
        }
    }while(choice!=6);
    return 0;
}
