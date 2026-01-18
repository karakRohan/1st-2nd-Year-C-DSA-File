/*Double Linked List*/
#include <stdio.h>
#include <stdlib.h>
void insert_last();
void insert_beg();
void insert_any();
void delete_any();
void display();
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *temp, *r;
void main()
{
    int op;
    while (1)
    {
        printf("Enter '1' to insert at beginning.\nEnter '2' to insert at last.\nEnter '3' to insert at any position.\nEnter '4' to delete at any position.\nEnter '5' to display.\nEnter '6' to exit.\n");
        printf("Enter your choice:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_any();
            break;
        case 4:
            delete_any();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Enter proper choice");
        }
    }
}
void insert_last()
{
    int n;
    temp = head;
    if (head == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert:");
        scanf("%d", &n);
        temp->data = n;
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        r = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert:");
        scanf("%d", &n);
        r->data = n;
        r->next = NULL;
        temp->next = r;
        r->prev = temp;
    }
}
void insert_beg()
{
    int n;
    temp = head;
    if (head == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert:");
        scanf("%d", &n);
        temp->data = n;
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp = head;

        r = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert:");
        scanf("%d", &n);
        r->data = n;
        r->prev = NULL;
        r->next = temp;

        temp->prev = r;
        head = r;
    }
}
void insert_any()
{
    int pos, i = 2, n;
    temp = head;
    printf("Enter position:");
    scanf("%d", &pos);
    if (pos == 1)
        insert_beg();
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        r = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert:");
        scanf("%d", &n);
        r->data = n;
        r->next = temp->next;
        temp->next->prev = r;
        r->prev = temp;
        temp->next = r;
    }
}
void delete_any()
{
    int pos, i = 2;
    temp = head;
    printf("Enter position:");
    scanf("%d", &pos);
    if (head == NULL)
        printf("Empty List");
    if (pos == 1)
    {
        head = temp->next;
        temp->next->prev = NULL;
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        r = temp->next;
        temp->next = r->next;
        r->next->prev = temp;
    }
}
void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}