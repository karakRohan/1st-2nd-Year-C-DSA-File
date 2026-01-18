// DOUBLE LINKED LIST IMPLEMENTATION


#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
struct node *temp,*r,*ptr;

void addfirst(int e)
{
    if (head==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=e;
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=e;
        r->next=head;
        head=r;
        r->prev=NULL;
    }
}


void addlast(int e)
{
    if (head==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=e;
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    
    else
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=e;
        r->next=NULL;
        ptr=head;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        r->prev=ptr;
        ptr->next=r;
    }
}


void add(int e,int p)
{
    r=(struct node*)malloc(sizeof(struct node));
    r->data=e;
    int c=1;
    ptr=head;
    while (c<=p-2)
    {
        ptr=ptr->next;
        c=c+1;
    }
    r->next=ptr->next;
    ptr->next=r;
    r->prev=ptr;
    ptr=ptr->next->next;
    ptr->prev=r;
}


void deletefirst()
{
    head=head->next;
    head->prev=NULL;
}


void deletelast()
{
    ptr=head;
    while (ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
}



void deleteindex(int p)
{
    int c=1;
    ptr=head;
    while (c!=(p-1))
    {
        ptr=ptr->next;
        c=c+1;
    }
    ptr->next=ptr->next->next;
    ptr->next->prev=ptr;
}


void display() 
{
    ptr=head;
    while (ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}

int main() {
    int n,p;
    int ch;
    while (1) {
        printf("1.ADD FIRST\n");
        printf("2.ADD LAST\n");
        printf("3.ADD AT INDEX\n");
        printf("4.DELETE FIRST\n");
        printf("5.DELETE LAST\n");
        printf("6.DELETE INDEX\n");
        printf("7.DISPLAY\n");
        printf("8.TERMINATE\n");
        printf("Enter your choice:- ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &n);
                addfirst(n);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &n);
                addlast(n);
                break;
            case 3:
                printf("Enter element to insert: ");
                scanf("%d", &n);
                printf("Enter position of insertion:-");
                scanf("%d",&p);
                add(n,p);
                break;
                
            case 4:
                printf("Element deleted...\n");
                deletefirst();
                break;
            case 5:
                printf("Element deleted...\n");
                deletelast();
                break;
    
            case 6:
                printf("Enter position:-");
                scanf("%d",&p);
                printf("Element deleted...\n");
                deleteindex(p);
                break;
                
            case 7:
                printf("The linked list elements are:\n");
                display();
                printf("\n");
                break;
            case 8:
                printf("Program Terminated...\n");
                exit(0);
        }
    }
}
