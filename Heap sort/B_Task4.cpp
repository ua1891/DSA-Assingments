#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int heap[100];
    int size;

    void heapifyUp(int index)
    {
       while(index>0){
        int parentIndex = (index-1)/2;
        if(heap[index]>heap[parentIndex]){
            swap(heap[index],heap[parentIndex]);
            index=parentIndex;
        }
        else{
            break;
        }
       }
    }

public:
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

    return 0;
}