#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node *Head=NULL;
struct Node *Tail=NULL;

void insert(int data)
{
   struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=data;
    NewNode->next=NULL;
    if(Head==NULL)
    {
        Head=NewNode;
        Tail=NewNode;

    }
    else{
        Tail->next=NewNode;
        Tail=NewNode;
    }

}
void insert_at_beginning(int Data){
    struct Node* NewNode=(struct Node*)(malloc(sizeof(struct Node)));
    NewNode->data=Data;
    NewNode->next=Head;
    Head=NewNode;
}
void delete_from_end(){
    if(Head==NULL){
        printf("List is empty\n");
        return;
    }
    if(Head==Tail){
        free(Head);
        Head=NULL;
        Tail=NULL;
        return;
    }
   struct Node* Temp=Head;
    while(Temp->next->next==NULL){
     Temp=Temp->next;
    }
    free(Temp->next);
    Temp->next=NULL;
    Tail=Temp;            
}
void delete_from_beginning(){
    if(Head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* Temp=Head;
    Head=Head->next;
    free(Temp);
}
void display(){
    struct Node* Temp=Head;
    while(Temp!=NULL){
        printf("%d ",Temp->data);
        Temp=Temp->next;
    }
    printf("\n");
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    insert_at_beginning(5);
    display();
    delete_from_end();
    display();
    delete_from_beginning();
    display();
    return 0;
}