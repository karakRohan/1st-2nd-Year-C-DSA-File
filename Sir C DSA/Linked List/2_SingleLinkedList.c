// Single Linked List

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp,*r,*ptr;
void addfirst(int);
void addlast(int);
void add(int,int);
void deletefirst();
void deleteback();
void display();

void addfirst(int e)
{
    if (head==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=e;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=e;
        r->next=head;
        head=r;
    }
    
}
    
    void addlast(int e)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=e;
        temp->next=NULL;
        if (head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while (ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    
    void add(int e,int p)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=e;
        int c=0;
        ptr=head;
        while (c!=p-2)
        {
            ptr=ptr->next;
            c=c+1;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
    void deletefirst()
    {
        head=head->next;
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
    
    
    void display()
    {
        ptr=head;
        while (ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    
    int main()
    {
        int n;
        int ch,p;
        while (1)
        {
            printf("1.ADD FIRST\n");
            printf("2.ADD LAST\n");
            printf("3.ADD AT A SPECIFIC POSITION\n");
            printf("4.DELETE_FIRST\n");
            printf("5.DELETE_LAST\n");
            printf("6.DISPLAY\n");
            printf("7.TERMINATE\n");
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
                    printf("Enter element to insert:-");
                    scanf("%d",&n);
                    printf("Enter postion of insertion:-");
                    scanf("%d",&p);
                    add(n,p);
                    break;
                case 4:
                    printf("ELEMENT DELETED\n");
                    deletefirst();
                    break;
                case 5:
                    printf("ELEMENT DELETED\n");
                    deletelast();
                    break;
                case 6:
                    printf("The linked list elements are:-\n");
                    display();
                    break;
                case 7:
                    printf("Program Terminated...");
                    exit(0);
                
            }
        }
    }
