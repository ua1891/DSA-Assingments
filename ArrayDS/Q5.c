#include <stdio.h>

void ReverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int temp;

    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = 5;

    printf("Original Array:\n");

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    ReverseArray(arr,size);

    printf("\n\nReversed Array:\n");

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}