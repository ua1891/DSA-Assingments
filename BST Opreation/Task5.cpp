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
int CommonNode(BST* root,int n1,int n2){
        if (root==NULL)
        {
            return -1;
        }
        if(root->data==n1 || root->data==n2){
            return root->data;
        }
        else if (n1<root->data && n2<root->data)
        {
            CommonNode(root->left,n1,n2);
        }
        else if (n1>root->data && n2>root->data)
        {
            CommonNode(root->right,n1,n2);
        }
        else if (n1<root->data && n2>root->data)
        {
            return root->data;
        }
        else{
            return -1;
        }        
}
int main(){
    BST* root = new BST(50);
root->left = new BST(30);
root->right = new BST(70);  
root->left->left = new BST(20);
root->left->right = new BST(40);
root->right->left = new BST(60);
root->right->right = new BST(80);
int n1=20,n2=40;
int Result=CommonNode(root,n1,n2);
if(Result!=-1)
cout<<"The Common Node is :"<<Result;
else cout<<"There is No Common Node";
return 0;
}