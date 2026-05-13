#include <iostream>
using namespace std;
#include <iostream>
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
void Inorder(BST* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


int main()
{
    int Arr[]={50,30,70,20,40,60,80};
    BST *root = NULL;
    for(int i=0;i<7;i++){
        root=insert(root,Arr[i]);
    }
    cout<<"Inorder Traversal : \n";
    Inorder(root);
    return 0;
}