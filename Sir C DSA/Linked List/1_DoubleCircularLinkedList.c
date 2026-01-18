// DOUBLE CIRCULAR LINKES LIST
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *temp, *r, *ptr, *last;
struct node *head = NULL;

void addfirst(int n)
{
    if (head == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        head = temp;
        temp->next = head;
        temp->prev = NULL;
    }
    else
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->data = n;
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        r->next = head;
        head = r;
        r->prev = ptr;
        ptr->next = head;
    }
}

void addlast(int n)
{
    if (head == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = n;
        head = temp;
        temp->next = head;
        temp->prev = NULL;
    }
    else
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->data = n;
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = r;
        r->next = head;
        r->prev = ptr;
    }
}

void add(int n, int p)
{
    r = (struct node *)malloc(sizeof(struct node));
    r->data = n;
    int c = 1;
    ptr = head;
    while (c <= p - 2)
    {
        ptr = ptr->next;
        c = c + 1;
    }
    r->next = ptr->next;
    ptr->next = r;
    r->prev = ptr;
    ptr = ptr->next->next;
    ptr->prev = r;
}

void deletefirst()
{
    last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    head = head->next;
    head->prev = NULL;
    last->next = head;
}

void deletelast()
{
    last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    ptr = last->prev;
    ptr->next = head;
}

void delete_index(int p)
{
    int c = 1;
    ptr = head;
    while (c != (p - 1))
    {
        ptr = ptr->next;
        c = c + 1;
    }
    ptr->next = ptr->next->next;
    ptr->next->prev = ptr;
}

void display()
{
    ptr = head;
    while (ptr->next != head)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

int main()
{
    int ch, n, p;
    while (1)
    {
        printf("1.ADD FIRST\n");
        printf("2.ADD LAST\n");
        printf("3.ADD ANY INDEX\n");
        printf("4.DELETE FIRST\n");
        printf("5.DELETE LAST\n");
        printf("6.DELETE ANY INDEX\n");
        printf("7.DISPLAY\n");
        printf("8.TERMINATE PROGRAM\n");
        printf("Enter your choice:-");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert:-");
            scanf("%d", &n);
            addfirst(n);
            break;
        case 2:
            printf("Enter element to insert:-");
            scanf("%d", &n);
            addlast(n);
            break;
        case 3:
            printf("Enter element to insert:-");
            scanf("%d", &n);
            printf("Enter position of insertion:-");
            scanf("%d", &p);
            add(n, p);
            break;
        case 4:
            printf("Element Deleted\n");
            deletefirst();
            break;
        case 5:
            printf("Element Deleted\n");
            deletelast();
            break;
        case 6:
            printf("Enter index to delete:-");
            scanf("%d", &p);
            delete_index(p);
            break;
        case 7:
            printf("The linked list elements are:-");
            display();
            printf("\n");
            break;
        case 8:
            printf("Program Terminated....");
            exit(0);
        }
    }
}