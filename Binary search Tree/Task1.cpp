#include<iostream>
using namespace std;

struct BST{
    int data;
    BST* left;
    BST* right;

    BST(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
BST* insert(BST* root, int value){
    if(root == NULL){
        return new BST(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}
void inorderTraversal(BST* root){
    if (root==NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    
}
void preorderTraversal(BST* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}
void postorderTraversal(BST* root){
    if (root==NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
    
}
int main(){
    BST* root = NULL;

    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);

    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;

    cout<<"Preorder Traversal: ";
    preorderTraversal(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postorderTraversal(root);
    cout<<endl; 

    return 0;
}