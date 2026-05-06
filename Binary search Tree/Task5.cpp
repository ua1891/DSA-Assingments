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
int CountMax(BST* root){
    if(root == NULL){
        return 0;
    }
    return max(root->data, max(CountMax(root->left), CountMax(root->right)));
}
int main(){
    BST* root = NULL;

    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    int max = CountMax(root);
    cout<<"Maximum Value: "<<max<<endl;
    return 0;
}