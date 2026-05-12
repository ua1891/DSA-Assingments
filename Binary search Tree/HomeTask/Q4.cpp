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
void CountNodesGreaterThanX(BST* root, int x, int &count){
    if(root == NULL){
        return;
    }
    if(root->data > x){
        count++;
    }
    CountNodesGreaterThanX(root->left, x, count);
    CountNodesGreaterThanX(root->right, x, count);
}
int main(){
    BST* root = NULL;
    root = insert(root, 5);
    root = insert(root, 1); 
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7); 
    int x = 3;
    int count = 0;
    CountNodesGreaterThanX(root, x, count);
    cout<<"Number of nodes greater than "<<x<<" are "<<count<<endl;
    return 0;
}