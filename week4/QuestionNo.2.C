#include <stdio.h>

int Arr[6] = {1, 2, 3, 4, 5, 6};
int ArraySize = 6;
void Traverse()
{
    if (ArraySize == NULL)
    {
        printf("No element in array");
    }
    else
    {
        for (int i = 0; i < ArraySize; i++)
        {
            printf("%d\n", Arr[i]);
        }
    }
}
void InsertAtEnd(int value)
{
    if (ArraySize == NULL)
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
    if (ArraySize == NULL)
    {
        Arr[0] = value;
        ArraySize++;
    }
    else
    {
        for (int i = ArraySize; i >= 0; i--)
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
                    printf("Value found");
            }
           return;
        }
        printf("Value not found");
        }
}
void main()
{
}