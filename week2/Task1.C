#include<stdio.h>
int main()
{
    int Integer=10;
    int *p=&Integer;
    printf("The Value of variable is :%d\n",Integer);
    printf("The Address of variable is :%d\n",&Integer);
    printf("The Value of pointer is :%d\n",*p);
    printf("The Address of pointer is :%d\n",p);
    return 0;
}