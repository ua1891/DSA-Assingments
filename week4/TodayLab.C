#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;
void insert(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void AddAtBeginning(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Added %d at the beginning of the list\n", value);
}
void AddAtEnd(int value)
{
    insert(value);
    printf("Added %d at the end of the list\n", value);
}
void AddAtPosition(int value, int position)
{
    if (position == 1)
    {
        AddAtBeginning(value);
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    struct node* temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Added %d at position %d\n", value, position);


}
//Update functions
void UpdateLastNode(int value)
{
    if (tail != NULL)
    {
        tail->data = value;
        printf("Updated last node with value %d\n", value);
    }
}
void UpdateFirstNode(int value){
    if (head != NULL)
    {
        head->data = value;
        printf("Updated first node with value %d\n", value);
    }
}
void UpdateAtSpecificPosition(int value, int position)
{
    struct node* temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    temp->data = value;
    printf("Updated position %d with value %d\n", position, value);
}
//Delete functions
void DeleteFirstNode()
{
    if (head==NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted first node\n");
    
}
void DeleteLastNode()
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
        printf("Deleted last node\n");
        return;
    }
    struct node* temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    free(tail);
    tail = temp;
    tail->next = NULL;
    printf("Deleted last node\n");
}
void DeleteAtSpecificPosition(int position)
{

    if (head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }
    if (position == 1)
    {
        DeleteFirstNode();
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    struct node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete == tail)
    {
        tail = temp;
    }
    free(nodeToDelete);
    printf("Deleted node at position %d\n", position);
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    AddAtBeginning(5);
    AddAtEnd(40);
    AddAtPosition(25, 3);
    UpdateLastNode(50);
    UpdateFirstNode(15);
    UpdateAtSpecificPosition(35, 2);
    DeleteFirstNode();
    DeleteLastNode();
    DeleteAtSpecificPosition(2);    
    return 0;
}

