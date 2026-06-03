#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* parent;
    Node* left;
    Node* right;
};
bool isMaxHeap(int Arr[],int n)
{
    for(int i=0;i<n;i++){
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        if(leftChild<10 && Arr[i]<Arr[leftChild]){
            return false;
        }
        if(rightChild<10 && Arr[i]<Arr[rightChild]){
            return false;
        }
    }
    return true;
}
int main()
{
    int Arr[10]={100, 80, 90, 30, 40, 50, 60};
    if(isMaxHeap(Arr,10)){
        cout<<"The array represents a max heap."<<endl;
    }
    else{
        cout<<"The array does not represent a max heap."<<endl;
    }
    return 0;
}
    