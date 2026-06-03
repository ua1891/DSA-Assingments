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
        if(heap[index]<heap[parentIndex]){//change > to < for min heap
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
        //45, 20, 35, 10, 25, 15
    h.insert(45);
    h.insert(20);
    h.insert(35);
    h.insert(10);
    h.insert(25);
    h.insert(15);

    return 0;
}