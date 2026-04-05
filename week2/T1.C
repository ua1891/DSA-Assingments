#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n;
    int *arr;
    
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("invalid number of elements to  Allocate the memory");
    }
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Failed to  Allocate the memory");
        return 1;
    }
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<=n;i++)
    {
        printf("%d",arr[i]);
    }
int *Temp=(int*)realloc(arr,2*n*sizeof(int));
    if (Temp==NULL)
    {
        printf("Failed to  Allocate the memory");
        return 1; 
    }
    arr=Temp;
    free(arr);
    arr=NULL;
    return 0;
    
}