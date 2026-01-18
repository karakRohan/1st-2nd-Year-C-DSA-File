/*Circular Linked List*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*temp,*temp1,*r;
void insert_last()
{
	int n;
	temp=head;
	if(head==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data to insert:");
		scanf("%d",&n);
		temp->data=n;
		head=temp;
		temp->next=head;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		temp=temp->next;
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter data to insert:");
		scanf("%d",&n);
		r->data=n;
		temp->next=r;
		r->next=head;

	}
}
void insert_beg()
{
		int n;
	temp=head;
	if(head==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data to insert:");
		scanf("%d",&n);
		temp->data=n;
		head=temp;
		temp->next=head;
	}
	else
	{
		temp=head;

		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter data to insert:");
		scanf("%d",&n);
		r->data=n;
		r->next=temp;
	      while(temp->next!=head)
		{
		temp=temp->next;
		}
		head=r;
		temp->next=head;

	}
}
void insert_any()
{
	int pos,i=2,n;
	temp=head;
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos==1)
	insert_beg();
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter data to insert:");
		scanf("%d",&n);
		r->data=n;
		r->next=temp->next;
		temp->next=r;
	}
}
void delete_any()
{
	int pos,i=2,n;
	temp=head;
	printf("Enter position:");
	scanf("%d",&pos);
	if(head==NULL)
	printf("Empty List");
	if(pos==1)
	{
	   temp1=head;
	   while(temp1->next!=head)
	      temp1=temp1->next;

	    head=temp->next;
	    temp1->next=head;
	}
	else
	{
		while(i<pos)
		{
			temp=temp->next;
			i++;
		}
		r=temp->next;
		temp->next=r->next;

	}
 }
	void display()
	{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
void main()
{
	while(1)
	{   int a,b;
		printf("Enter '1' to insert \nEnter '2' to delete at any position.\nEnter '3' to display.\nEnter '4' to exit.\n");
		printf("Enter your choice:");
		scanf("%d",&a);
		switch(a)
		{
			case 1:printf("Enter '1' to insert at beginning.\nEnter '2' to insert at last.\nEnter '3' to insert at any position."); 
			       scanf("%d",&b);
			       switch(b)
			       {
			       	case 1:insert_beg();
			       	       break;
			       	case 2:insert_last();
			       	       break;
					case 3:insert_any();
					       break;
				    default:printf("invalid input");		             
				   }
				   break;
            case 2:delete_any();
                   break;
		    case 3:display();
                   break;
            case 4:exit(0);
		           break;
		    default:printf("invalid input");       
		}
	}
}