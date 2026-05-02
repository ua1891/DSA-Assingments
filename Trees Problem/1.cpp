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
int FindHight(BinaryTree* Root){
     if (Root == nullptr)
        return -1;
    int Lheight=FindHight(Root->left);
    int Rheight=FindHight(Root->Right);
    return max(Lheight,Rheight)+1;
}
int main(){
    BinaryTree* Root=new BinaryTree(15);
    Root->left=new BinaryTree(12);
    Root->Right=new BinaryTree(10);

    Root->left->left=new BinaryTree(9);
    Root->left->Right=new BinaryTree(8);

cout<<"The Hight of the Binary Tree is "<<FindHight(Root);
cout<<endl;
    return 0;
}
