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
BST* getSuccessor(BST* root){
    BST* current=root;
    while(current!=NULL && current->left!=NULL){
        current=current->left;
    }
    return current;
}
BST *delNode(BST *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > key)
    {
        root->left = delNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        if (root->right == NULL)
        {
            return root->left;
        }
        BST* Succ=getSuccessor(root->right);
        root->data=Succ->data;
         root->right=delNode(root->right,Succ->data);

    }
    return root;
}


int main()
{
    BST *root = NULL;

    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    cout<<"Inorder Traversal before Deletion: \n";
    Inorder(root);
    cout<<"Enter the Node which you want to delete: \n";
    int DelNode=0;
    cin>>DelNode;
    root=delNode(root,DelNode);
    cout<<"Inorder Traversal after Deletion: \n";
    Inorder(root);
    return 0;
}