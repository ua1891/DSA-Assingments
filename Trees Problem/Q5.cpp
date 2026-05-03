#include <iostream>
using namespace std;
class CompleteBinaryTree
{
    int Arr[10];
public:
    int Size;
    CompleteBinaryTree(int S)
    {
        Size = S;
    }
    void Takeinput()
    {
        for (int i = 0; i < Size; i++)
        {
            if (Size <= sizeof(Arr))
                cin >> Arr[i];
        }
    }
    void DisplayCompleteBinary(int n)
    {
        cout << "Node " << Arr[0];
        for (int i = 0; i < n; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n)
            {
                cout << "\nLeft Child " << Arr[left];
            }
            if (right < n)
            {
                cout << "\nRight Child " << Arr[right];
            }
        }
    }
};
int main()
{
    cout << "Enter the Size of Array";
    int Size;
    cin >> Size;
    CompleteBinaryTree CBT(Size);
    CBT.Takeinput();
     CBT.DisplayCompleteBinary(Size);
    cout << endl;
    return 0;
}