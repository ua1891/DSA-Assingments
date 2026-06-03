#include<iostream>
using namespace std;
int Array[10]={90, 70, 80, 40, 60, 50, 30};
int Parent(int i){
    return (i-1)/2;
}
int LeftChild(int i){
    return 2*i+1;
}
int RightChild(int i){
    return 2*i+2;
}
int main()
{
 
        cout << "Parent of element of 5 index is " <<Array[5]  << " is: " << Array[Parent(5)] << endl;
        cout << "Left child of element of 2 index is" <<Array[2]  << " is: " << Array[LeftChild(2)] << endl;
        cout << "Right child of element of 2 index is " << Array[2] << " is: " << Array[RightChild(2)] << endl;
    
    return 0;
}