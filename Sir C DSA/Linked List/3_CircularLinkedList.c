// CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>
void addfirst(int);
void addlast(int);
void deletefirst();
void deletelast();

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp, *r, *ptr;

void addfirst(int e)
{
    if (head==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=e;
        head=temp;
        temp->next=head;
    }
    else
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=e;
        ptr=head;
        while (ptr->next!=head)
        {
           ptr=ptr->next;
        }
        r->next=head;
        ptr->next=r;
        head=r;

    }
}

void addlast(int e)
{
    if (head==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=e;
        head=temp;
        temp->next=head;
    }
    else
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=e;
        ptr=head;
        while (ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=r;
        r->next=head;
    }
}

void deletefirst()
{
    temp=head;
    r=head;
    while(r->next!=head)
    {
          r=r->next;
    }
    r->next=head->next;
    head=head->next;
}

void deletelast()
{
    ptr=head;
    while (ptr->next->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=head;
}


void display()
{
    ptr=head;
    while (ptr->next!=head)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}


int main()
{
    int n;
    int ch,p;
    while (1)
    {
        printf("1.ADD FIRST\n");
        printf("2.ADD LAST\n");
        printf("3.DELETE FIRST\n");
        printf("4.DELETE LAST\n");
        printf("5.DISPLAY\n");
        printf("6.TERMINATE\n");
        printf("Enter your choice:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to insert:-");
                scanf("%d",&n);
                addfirst(n);
                break;
            case 2:
                printf("Enter element to insert:-");
                scanf("%d",&n);
                addlast(n);
                break;
            case 3:
                printf("Elment deleted...\n");
                deletefirst();
                break;
            case 4:
                printf("Elment deleted...\n");
                deletelast();
                break;
            case 5:
                printf("The linked list elements are:-\n");
                display();
                printf("\n");
                break;
            case 6:
                printf("Program Terminated...");
                exit(0);
        }
    }
}
