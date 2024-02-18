#include<stdio.h>
#include<stdlib.h>
//Structure declaration
struct tree
{
    int data;
    struct tree *lchild;
    struct tree *rchild;
}*t, *temp;
//Global declarations
int element;
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
struct tree *create(struct tree *, int);
struct tree *insert(struct tree *, int);
struct tree *search(struct tree *, int);
struct tree *del(struct tree *, int);
struct tree *findmin(struct tree *);

//Function initialization

void inorder(struct tree *t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        inorder(t->lchild);
        printf("\t%d", t->data);
        inorder(t->rchild);
    }
}
void preorder(struct tree *t)
{
    if(t == NULL)
    {
        return;
    }
    else
     {
         printf("\t%d", t->data);
         preorder(t->lchild);
         preorder(t->rchild);
     }
}
void postorder(struct tree *t)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("\t%d", t->data);
    }
}
struct tree *findmin(struct tree *t)
{
    if(t == NULL)
    {
        return NULL;
    }
    else if(t -> lchild == NULL)
    {
        return t;
    }
    else
    {
        return findmin(t -> lchild);
    }
}
struct tree *create(struct tree *t, int element)
{
    t = (struct tree *)malloc(sizeof(struct tree));
    t -> data = element;
    t -> lchild = NULL;
    t -> rchild = NULL;
    return t;
}
struct tree *insert(struct tree *t, int element)
{
    if(t == NULL)
    {
        t = (struct tree *)malloc(sizeof(struct tree));
        t -> data = element ;
        t -> lchild = NULL;
        t -> rchild = NULL;
        return t;
    }
    else
    {
        if(t -> data > element)
        {
            t -> lchild = insert(t->lchild, element);
        }
        else if(t -> data < element)
        {
            t -> rchild = insert(t->rchild, element);
        }
        else if(t -> data == element)
        {
            printf("Element already exists!\n");
        }
        return t;
    }
}
struct tree *del(struct tree *t, int element)
{
    if(t == NULL)
    {
            printf("Tree is empty!\n");
    }
    else if(t -> data > element)
    {
        t -> lchild = del(t->lchild, element);
    }
    else if(t -> data < element)
    {
        t -> rchild = del(t->rchild, element);
    }
    else if(t -> lchild && t -> rchild)
    {
        temp = findmin(t->rchild);
        t -> data = temp -> data;
        t -> rchild = del(t->rchild, t->data);
    }
    else
    {
        temp = t;
        if(t -> lchild == NULL)
        {
            t = t -> rchild;
        }
        else if(t -> rchild == NULL)
        {
            t = t -> lchild;
        }
        free(temp);
    }
    return t;
}
struct tree *search(struct tree *t, int element)
{
    if(t == NULL)
    {
        return NULL;
    }
    else if(element < t -> data)
    {
        return search(t->lchild,element);
    }
    else if(element > t-> data)
    {
        return search(t->rchild, element);
    }
    else
    {
        return t;
    }
}

//Driver's code

int main()
{
    int choice;
    do
    {
        printf("\nBinary Search Tree!!!\n\n");
        printf("1.Create\n2.Insert\n3.Delete\n4.Search\n5.Inorder\n6.Preorder\n7.Postorder\n8.Exit\n");
        printf("Please enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data : ");
                scanf("%d",&element);
                t = create(t, element);
                inorder(t);    //Default traversal for the tree
                break;
            case 2:
                printf("Enter the data : ");
                scanf("%d",&element);
                t = insert(t, element);
                inorder(t);
                break;
            case 3:
                printf("Enter the data : ");
                scanf("%d",&element);
                t = del(t, element);
                inorder(t);
                break;
            case 4:
                printf("Enter the data : ");
                scanf("%d",&element);
                temp = search(t, element);
                if(temp->data == element)
                {
                    printf("Element is found!");
                }
                else
                {
                    printf("Element not found!");
                }
                break;
            case 5:
                inorder(t);
                break;
            case 6:
                preorder(t);
                break;
            case 7:
                postorder(t);
                break;
            case 8:
                printf("Exiting...\nThank You!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid one.\n");
        }
    }while(choice!=8);
    return EXIT_SUCCESS;
}
