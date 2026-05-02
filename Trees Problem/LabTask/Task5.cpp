#include<iostream>
using namespace std;
int Arr[10];
void Takeinput(int n){
    for (int i = 0; i < n; i++)
    {
        if (n<=sizeof(Arr))
        {
            /* code */
            cin>>Arr[i];
        }
        
    }
}
void DisplayCompleteBinary(int n){
    for (int i = 0; i < n; i++)
    {   
        cout<<"Node"<<Arr[i];
        int left=2*i+1;
        int right=2*i+2;
        if (left<n)
        {
            cout<<"Left Child"<<Arr[left];
        }
        if (right<n)
        {
            cout<<"Right Child"<<Arr[right];
            
        }
        
        
    }
}
int main()
{
    cout<<"Enter the Size of Array";
    int Size;
    return 0;
}