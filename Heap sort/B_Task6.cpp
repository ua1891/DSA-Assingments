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
    //Writing code for heapify down
    void heapifyDown(int index)
    {
        while(true){
        int largest = index;
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;

        if(leftChild < size && heap[leftChild] > heap[largest]){
            largest = leftChild;
        }
        if(rightChild < size && heap[rightChild] > heap[largest]){
            largest = rightChild;
        }
        if(largest != index){
            cout<<"Swapping "<<heap[index]<<" and "<<heap[largest]<<endl;
            swap(heap[index],heap[largest]);
            index = largest;
         
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
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    void deleteMax(){
        if(size == 0){
            cout << "Heap is empty" << endl;
            return;
        }
        heap[0] = heap[size-1];
        size--;
        heapifyDown(0);
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
    cout<<"Before deleting max:";
    h.display();
    cout<<endl;
    h.deleteMax();
    cout<<"After deleting max:";
    h.display();
    return 0;
}