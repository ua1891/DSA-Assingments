#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int heap[100];
    int size;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex])
            {
                cout << "Swapping " << heap[index] << " and " << heap[parentIndex] << endl;
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void heapifyDown(int index)
    {
        while (true)
        {
            int largest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            if (leftChild < size && heap[leftChild] > heap[largest])
            {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest])
            {
                largest = rightChild;
            }
            if (largest != index)
            {

                cout << "Swapping " << heap[index] << " and " << heap[largest] << endl;
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    void heapsort()
    {
        int originalSize = size;

        for (int i = size - 1; i > 0; i--)
        {
            cout << "Swapping "
                 << heap[0]
                 << " and "
                 << heap[i]
                 << endl;
            swap(heap[0], heap[i]);
            size--;
            heapifyDown(0);
        }
        size = originalSize;
    }

    MaxHeap()
    {
        size = 0;
    }

    void insert(int value)
    {
        heap[size] = value;
        size++;

        heapifyUp(size - 1);

        cout << "After inserting " << value << ": ";
        display();
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap h;

    h.insert(10);
    h.insert(50);
    h.insert(30);
    h.insert(80);
    h.insert(60);
    h.insert(20);
    h.heapsort();
    h.display();
    return 0;
}