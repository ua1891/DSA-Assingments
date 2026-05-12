#include <iostream>
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
void SumOfNodes(BST* root, int &sum){
    if(root == NULL){
        return;
    }
    sum += root->data;
    SumOfNodes(root->left, sum);
    SumOfNodes(root->right, sum);
}
int main(){
    BST* root = NULL;   
    root = insert(root, 5);
    root = insert(root, 1); 
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);     
    int sum = 0;
    SumOfNodes(root, sum);
    cout<<"Sum of all nodes in the Binary Search Tree is "<<sum<<endl;
    return 0;
}