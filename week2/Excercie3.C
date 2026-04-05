#include<stdio.h>

void swap(int *a,int *b){
   int temp=*a;
  *a=*b;
  *b=temp;
}
int main()
{
            int a=10,b=20;
            printf("The Value of A and b before swap is :%d %d\n",a,b);
            swap(&a,&b);
            printf("The Value of A and b after swap is :%d %d\n",a,b);
            return 0;   

}