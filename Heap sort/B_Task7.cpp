#include <iostream>
using namespace std;

// WRONG CODE
// Bug: After swapping, 'i' is never updated.continue using old index
int parent(int i)
{
    return (i - 1) / 2;
}

int Main()
{
    int heap[10] = {90, 70, 80, 40, 60, 50, 30};
    int i = 5;

    while(i > 0 && heap[parent(i)] > heap[i])
    {
        swap(heap[parent(i)], heap[i]);
        // Missing: i = parent(i);
    }

while(i > 0 && heap[parent(i)] > heap[i])
{
    swap(heap[parent(i)], heap[i]);

    // Move upward in the heap
    i = parent(i);
}
    return 0;
}


// QUESTIONS & ANSWERS

// 1. What is the bug?
//    Missing: i = parent(i);
//    After swapping, the current index is not updated.

// 2. Why can it create an infinite loop?
//    The loop variable 'i' never changes.
//    Since the condition is checked using the same index repeatedly,
//    the loop may keep executing without making progress.
