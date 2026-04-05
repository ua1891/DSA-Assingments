#include<stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40};
    //Task1
    printf("The value of arr2 usinf Pointer arithmetic is :%d\n",*(arr+2));
    //Task2
    int *ptr = arr;
    for (int i = 0; i <=3; i++)
    {
            printf("%d\n",*(ptr+i));      
    }
    //Task3
    printf("The adress of arr[0] is :%d\n",&arr[0]);
    printf("The adress of arr[1] is :%d\n",&arr[1]);
    return 0;
    }