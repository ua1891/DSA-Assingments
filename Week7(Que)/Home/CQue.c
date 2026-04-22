#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MaxSize 3

int Arr[3];
int Front = 0;
int Rear = -1;
int CurrentSize = 0;

void Enqueue(int data);
void Dequeue();
void FrontElement();
bool Empty();

bool Empty(){
    return CurrentSize == 0;
}
void Enqueue(int Data){
    if (CurrentSize==MaxSize)
    {
        printf("Queue is Full\n");
        return;
    }
    else{
        Rear=(Rear+1)%MaxSize;
        Arr[Rear]=Data;
        CurrentSize++;
    }
    
}

void Dequeue(){
   if(Empty()){
    printf("Queue is Empty\n");
    return;
   }
   Front=(Front+1)%MaxSize;
    CurrentSize--;  
}

void FrontElement(){
    if (Empty())
    {
        printf("Queue is Empty\n");
    }
    else{
        printf("Front Element is : %d\n",Arr[Front]);

    }
    
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    FrontElement();  // Prints 10
    Dequeue();           // Removes 10
    FrontElement();  // Prints 20
    Dequeue();           // Removes 20
    FrontElement();  // Prints 30
    return 0;
}
