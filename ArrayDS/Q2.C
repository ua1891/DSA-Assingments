#include <stdio.h>
#include <stdlib.h>
int Arr[20] = {1, 2, 3, 4, 5, 6};
int ArraySize = 6;
void Traverse()
{
    if (ArraySize == 0)
    {
        printf("No element in array");
    }
    else
    {
        for (int i = 0; i < ArraySize; i++)
        {
            printf("%d", Arr[i]);
        }
    }
}
void InsertAtEnd(int value)
{
    if (ArraySize == 0)
    {
        Arr[0] = value;
        ArraySize++;
    }
    else
    {
        Arr[ArraySize] = value;
        ArraySize++;
    }
}
void InsertAtFirst(int value)
{
    if (ArraySize == 0)
    {
        Arr[0] = value;
        ArraySize++;
    }
    else
    {
        for (int i = ArraySize; i > 0; i--)
        {
            Arr[i] = Arr[i - 1];
        }
        Arr[0] = value;
        ArraySize++;
    }
}
void InsertAtAnyPosition(int value, int position)
{
    if (ArraySize == 0)
    {
        Arr[0] = value;
        ArraySize++;
    }
    else
    {
        for (int i = ArraySize; i >= position; i--)
        {
            Arr[i] = Arr[i - 1];
        }
        Arr[position - 1] = value;
        ArraySize++;
    }
}
void DeleteAtEnd()
{
    if (ArraySize == 0)
    {
        printf("No element in array");
    }
    else
    {
        ArraySize--;
    }
}
void DeleteAtFirst()
{
    if (ArraySize == 0)
    {
        printf("No element in array");
    }
    else
    {
        for (int i = 0; i < ArraySize - 1; i++)
        {
            Arr[i] = Arr[i + 1];
        }
        ArraySize--;
    }
}
void DeleteAtAnyPosition(int position)
{
        if (ArraySize == 0)
    {
        printf("No element in array");
    }
    else
    {
        for (int i = position; i < ArraySize - 1; i++)
        {
            Arr[i] = Arr[i + 1];
        }
        ArraySize--;
        }
}
void Search(int value)
{

    if (ArraySize == 0)
    {
        printf("No element in array");
    }

    else
    {
        for (int i = 0; i < ArraySize; i++)
        {
            if (Arr[i]==value)
            {
                    printf("Value found\n");
                    return;
            }
        }
        printf("Value not found\n");
        }
}
int  main()
{
    printf("Initial Array:");
    Traverse();
    printf("\n--- Inserting 7 at End ---");
    InsertAtEnd(7);
    Traverse();
    printf("\n--- Inserting 0 at First ---");
    InsertAtFirst(0);
    Traverse();
    printf("\n--- Inserting 99 at Position 3 ---");
    InsertAtAnyPosition(99, 3);
    Traverse();
    printf("\n--- Searching for 99 ---");
    Search(99);

    printf("\n--- Searching for 500 ---");
    Search(500);

    printf("\n--- Deleting at First ---");
    DeleteAtFirst();
    Traverse();

    printf("\n--- Deleting at End ---");
    DeleteAtEnd();
    Traverse();

    printf("\n--- Deleting at Index 2 ---");
    DeleteAtAnyPosition(2);
    Traverse();
        return 0;
}