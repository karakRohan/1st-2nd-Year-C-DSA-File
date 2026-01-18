#include<stdio.h>
#include<stdlib.h>
#define max 5

int queue[max],front=-1,rear=-1;
void insert();
void delete();
void display();

int main()
{
    int n;
    while(1)
    {
        printf("\n Enter -> \n1 to insert \n2 to delete \n3 to display \n4 to exit \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT");
                exit(0);
            default:
                printf("\n\t Please Enter a valid chioce(1/2/3/4)");
        }
    }
    return 0;
}

void insert()
{
    int x;
    if(rear==max-1)
    {
        printf("Queue is overflow \n");
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        printf("Enter a value to be insert :");
        scanf("%d",&x);
        queue[rear]=x;
    }
    else
    {
        rear++;
        printf("Enter a value to be insert :");
        scanf("%d",&x);
        queue[rear]=x;
    }
}

void delete()
{
    int p;
    if(rear==-1)
    {
        printf("Queue is underflow ");
    }
    else if(front==rear) // only 1 element
    {
        p=queue[front];
        front=-1;
        rear=-1;
        printf("The delete element is %d",p);
    }
    else
    {
        p=queue[front];
        front++;
        printf("The delete element is %d",p);
    }
}

void display()
{
    int i;
    for(i=front;i<=rear;i++)
    printf("%d ",queue[i]);
}

