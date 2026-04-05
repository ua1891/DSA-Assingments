#include<stdio.h>
#include<stdlib.h>
struct node
{
    int Value;
    struct node *next;
};
void Print_list(struct node *start){
            struct node *temp=start;
            while(temp!=NULL){
                printf("%d\n",temp->Value);
                temp=temp->next;
            }
            
}
void Free_list(struct node *start){
    struct node *temp=start;
    while(temp!=NULL){
            free(temp);
            temp=temp->next;
    }
}
// void check(struct node *check){
//             struct node*temp=check;
//             while(temp!=NULL){
//                     printf("%d\n",temp->Value);
//                     temp=temp->next;
//                     free(temp);
//                     temp=NULL;
//                     temp=temp->next;

//             }
// }
int main(){
        struct node *N1=(struct node*)malloc(sizeof(struct node));
        struct node *N2=(struct node*)malloc(sizeof(struct node));
        struct node *N3=(struct node*)malloc(sizeof(struct node));
        N1->Value=10;
        N2->Value=20;
        N3->Value=30;
        N1->next=N2;
        N2->next=N3;
        N3->next=NULL;

        //struct node *head=N1;
        Print_list(N1);
        Free_list(N1);
        return 0;
}