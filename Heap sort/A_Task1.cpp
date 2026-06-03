#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* parent;
    Node* left;
    Node* right;
};

bool isMaxHeap(Node* root)
{
    if (root == NULL)
        return true;

    if (root->left != NULL)
    {
        if (root->data < root->left->data)//use < for max heap
            return false;
    }

    if (root->right != NULL)
    {
        if (root->data < root->right->data)
            return false;
    }

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

bool isMinHeap(Node* root)
{
    if (root == NULL)
        return true;

    if (root->left != NULL)
    {
        if (root->data > root->left->data)//use false that's why we use > sign
            return false;
    }

    if (root->right != NULL)
    {
        if (root->data > root->right->data)
            return false;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    Node* root = createNode(90);

    root->left = createNode(70);
    root->right = createNode(60);

    root->left->parent = root;
    root->right->parent = root;

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    root->right->left = createNode(30);
    root->right->right = createNode(20);

    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->right->left->parent = root->right;
    root->right->right->parent = root->right;

    if (isMaxHeap(root))
        cout << "Max Heap" << endl;
    else if (isMinHeap(root))
        cout << "Min Heap" << endl;
    else
        cout << "Not a Heap" << endl;

    return 0;
}