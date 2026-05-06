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
int Height(BST* Root){
    if (Root==NULL)
    {
        return -1;
    }
    int Lhieght=Height(Root->left);
    int Rhieght=Height(Root->right);
    return max(Lhieght,Rhieght)+1;
    
}
int main(){
    BST* root = NULL;

    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    int height = Height(root);
    cout<<"Height of the Binary Search Tree is "<<height<<endl;
        return 0;
}