#include<iostream>
using namespace std;
struct BinaryTree
{
    int Data;
    BinaryTree* left;
    BinaryTree* Right;

    BinaryTree(int Value){
        Data=Value;
        left=NULL;
        Right=NULL;
    }
};
int CountInternalNodes(BinaryTree* Root){
    if (Root == nullptr)
        return 0;

        if (Root->left==nullptr&&Root->Right==nullptr)
        {
            return -1;
        }
        else
            return CountInternalNodes(Root->left)+CountInternalNodes(Root->Right)+1;
        
        
}
int main(){
    BinaryTree* Root=new BinaryTree(15);
    Root->left=new BinaryTree(12);
    Root->Right=new BinaryTree(10);

    Root->left->left=new BinaryTree(9);
    Root->left->Right=new BinaryTree(8);
    Root->Right->left=new BinaryTree(9);
    Root->Right->Right=new BinaryTree(8);

    return 0;
}
