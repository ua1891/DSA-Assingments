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
bool serach(BST* root, int value){
    if(root == NULL){
        return false;
    }
    if(value == root->data){
        return true;
    }
    else if(value < root->data){
        serach(root->left, value);
    }
    else{
        serach(root->right, value);
    }
}
int main(){
    BST* root = NULL;

    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
//searching Value
if (    serach(root, 11))
{
    cout<<"Found"<<endl;
}
else{
    cout<<"Not Found"<<endl;
}
    return 0;
}