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
int Kthsmallest(BST* root,int &cnt,int K){
    if(root==NULL){
        return-1;
    }
  int left=Kthsmallest(root->left,cnt,K);
    cnt++;
    if(left != -1){
        return left;
    }
    if(cnt==K){
       
        return root->data;
    }
   return Kthsmallest(root->right,cnt,K);
}
int main(){
    BST* root = new BST(50);
root->left = new BST(30);
root->right = new BST(70);  
root->left->left = new BST(20);
root->left->right = new BST(40);
root->right->left = new BST(60);
root->right->right = new BST(80);
int K=3;
int cnt=0;
int Ressult=Kthsmallest(root,cnt,K);
cout<<"The kth Node is :"<<Ressult;
return 0;
}