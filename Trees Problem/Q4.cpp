#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool SearchValue(Node *root, int key){
    if (root==NULL)
    {
        return false;
    }
    if (root->data==key)
    {
        return true;
    }
    else{
        return SearchValue(root->left,key)||SearchValue(root->right,key);
    }
    return false;
    
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (SearchValue(root,6))
    {
        cout<<"Value Found";
    }
    else
    {
        cout<<"Value Not Found";
    }
    
    return 0;
}