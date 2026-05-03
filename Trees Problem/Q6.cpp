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
class Traversal
{
    public:
    void Preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
    void Postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
    void Inorder(Node *Root)
    {
        if (Root == NULL)
        {
            return;
        }
        Inorder(Root->left);
        cout << Root->data << " ";
        Inorder(Root->right);
    }
};
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    Traversal T;
    cout << "Result of Post Order:";
    T.Postorder(root);
    cout << endl;
    cout << "Result of Pre Order:";
    T.Preorder(root);
    cout << endl;
    cout << "Result of Inorder";
    T.Inorder(root);
    cout << endl;
    return 0;
}