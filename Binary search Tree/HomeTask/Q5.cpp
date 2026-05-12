#include<iostream>
#include<climits>
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
bool isValidBST(BST* root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
       
        return false;
    }
   return isValidBST(root->left, min, root->data - 1)&&isValidBST(root->right, root->data + 1, max);
}
//Another way to check valid BST
bool isvalidBST(BST* root, long min, long max){

    if(root == NULL)
        return true;

    if(root->data <= min || root->data >= max)
        return false;

    return isvalidBST(root->left, min, root->data) &&
           isvalidBST(root->right, root->data, max);
}
int main(){
    BST* root = NULL;
    root = insert(root, 5);
    root->left=new BST(3);
    root->right=new BST(7);
    root->left->left=new BST(9);
    root->left->right=new BST(1);


    if (isValidBST(root,INT_MIN,INT_MAX))
    {
        cout<<"The Binary Tree is a Valid Binary Search Tree."<<endl;
    }
    else{
        cout<<"The Binary Tree is not a Valid Binary Search Tree."<<endl;
    }

    return 0;
}