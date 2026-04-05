#include<stdio.h>
int array[100]={1,2,3,4,5,6};

void instert(int n,int pos)
{
    int i;
    for(i=7;i>pos;i--)
    {
        array[i]=array[i-1];
    }
    array[pos]=n;
    printf("Element inserted successfully\n");
}
int main()
{
        //1. Insert 5 at index 0
        instert(5,0);//its Time complexity is O(n) because we have to shift all the elements to the right to make space for the new element at index 0.
        //2. Insert 25 at index 2
        instert(25,2);//its Time complexity is O(n) because we have to shift all the elements from index 2 to the right to make space for the new element at index 2.
        //3. Insert 100 at End of the array
        instert(100,6);//its Time complexity is O(1) because we can directly insert the new element at the end of the array without shifting any elements.
    return 0;
}