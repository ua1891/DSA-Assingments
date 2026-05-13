#include<iostream>
using namespace std;
struct BST
{
    int data;
    BST *left;
    BST *right;

    BST(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
BST *insert(BST *root, int value)
{
    if (root == NULL)
    {
        return new BST(value);
    }       
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}   
int isBST(BST* Root,int min,int max){
    if(Root==NULL){
        return 0;
    }
    if(Root->data<=min || Root->data>=max){
        return 1;
    }
    return isBST(Root->left,min,Root->data) + isBST(Root->right,Root->data,max);
}
int main(){
    BST* root = new BST(50);
root->left = new BST(30);
root->right = new BST(70);
root->left->left = new BST(20);
root->left->right = new BST(40);
root->right->left = new BST(60);
root->right->right = new BST(10);
int count=isBST(root, INT_MIN, INT_MAX);
if(count==0)
cout << "Valid BST";
else cout << "It is Not a BST"<<endl<<"Number of Violations: "<<count;
return 0;
}