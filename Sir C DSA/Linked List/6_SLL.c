// Singly linked list implementation.
// Reverse Linked list using three pointer.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertFirst();
void insertLast();
void insertMiddle();
void deleteFirst();
void deleteLast();
void deleteMiddle();
void reverse();
void display();

int main()
{
    int choice;
    printf("Press 1: Insert at first \nPress 2: Insert at Last \nPress 3:Insert At any position \nPress 4: Delete at first \nPress 5: Delete at Last \nPress 6: Delete At any position \nPress 7: Reverse the list \nPress 8: Display \nPress 9: Exit \n");

    while (1)
    {
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertFirst();
            break;
        case 2:
            insertLast();
            break;
        case 3:
            insertMiddle();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            deleteMiddle();
            break;
        case 7:
            reverse();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);

        default:
            printf("\nInvalid Choice!");
        }
    }
    return 0;
}

void insertFirst()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter the value to be inserted :");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void insertLast()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter the value to be inserted :");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertMiddle()
{
    int pos, i;
    printf("Enter the position at which you want to enter : ");
    scanf("%d", &pos);

    struct node *temp = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter the value to be inserted :");
    scanf("%d", &value);
    newNode->data = value;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }

    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst()
{
    if (head == NULL)
        printf("List is Empty.");
    else
        head = head->next;
}

void deleteLast()
{
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

void deleteMiddle()
{
    int pos, i;
    printf("Enter the position at which you want to enter : ");
    scanf("%d", &pos);
    struct node *temp = head;

    if (pos == 1)
    {
        head = head->next;
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}

// reverse the Linked List
void reverse()
{
    struct node *current = head;
    struct node *prev = NULL;
    struct node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;

        prev = current;
        current = nextNode;
    }
    head = prev;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
