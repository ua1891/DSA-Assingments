#include <stdio.h>
int array[10] = {1, 2, 3, 40, 50, 67};
void FindLargestAndSecondLargest()
{

    int Largest = array[0];
    int secondLargest;
    for (int i = 1; i < 6; i++)
    {
        if (array[i] > Largest)
        {
            secondLargest = Largest;
            Largest = array[i];
        }
        else if (array[i] > secondLargest && array[i] != Largest)
        {
            secondLargest = array[i];
        }
    }
    printf("The largest element is %d and the second largest element is %d", Largest, secondLargest);
}
void FindSmallestAndSecondSmallest()
{
    int smallest = array[0];
    int secondSmallest;
    for (int i = 1; i < 6; i++)
    {
        if (array[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = array[i];
        }
        else if (array[i] < secondSmallest && array[i] != smallest)
        {
            secondSmallest = array[i];
        }
    }
    printf("\nThe smallest element is %d and the second smallest element is %d", smallest, secondSmallest);
}
int main()
{
    FindLargestAndSecondLargest();
    FindSmallestAndSecondSmallest();
    return 0;
}