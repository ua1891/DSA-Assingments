#include <iostream>
using namespace std;
struct BinaryTree
{
    int Data;
    BinaryTree *left;
    BinaryTree *Right;

    BinaryTree(int Value)
    {
        Data = Value;
        left = NULL;
        Right = NULL;
    }
};
bool ProperBinarTree(BinaryTree *Root)
{
    if (Root == nullptr)
        return false;
    if (Root->left == nullptr && Root->Right == nullptr)
    {
        return true;
    }
    else if (Root->left != nullptr && Root->Right != nullptr)
    {
        return ProperBinarTree(Root->left) && ProperBinarTree(Root->Right);
    }
    
        return false;
    }
int main()
{
    BinaryTree *Root = new BinaryTree(15);

    Root->left = new BinaryTree(12);
    Root->Right = new BinaryTree(10);

    Root->left->left = new BinaryTree(9);
    Root->left->Right = new BinaryTree(8);

    Root->Right->left = new BinaryTree(9);
    Root->Right->Right = new BinaryTree(8);

    if (ProperBinarTree(Root))
    {
        cout << "It is Proper Binary Tree";
    }
    else
    {
        cout << "It is not Proper Binary Tree";
    }
}