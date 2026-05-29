#include <iostream>
using namespace std;
enum Color
{
    Red,
    Black
};
struct Node
{
    int Data;
    Color color;
    Node *left, *right, *parent;
    Node(int data)
    {
        Data = data;
        color = Red;
        left = right = parent = nullptr;
    }
};
class R_B_Tree
{
public:    
    Node *root;

public:
    R_B_Tree()
    {
        root = nullptr;
    }
   void rotateLeft(Node*& currentNode)
{
    Node* rightChild = currentNode->right;
    currentNode->right = rightChild->left;

    if (rightChild->left != nullptr)
    {
        rightChild->left->parent = currentNode;
    }

    rightChild->parent = currentNode->parent;

    if (currentNode->parent == nullptr)
    {
        root = rightChild;
    }

    else if (currentNode == currentNode->parent->left)
    {
        currentNode->parent->left = rightChild;
    }

    else
    {
        currentNode->parent->right = rightChild;
    }

    rightChild->left = currentNode;

    
    currentNode->parent = rightChild;
}
void rotateRight(Node*& currentNode)
{
    Node* leftChild = currentNode->left;
    currentNode->left = leftChild->right;
    if (leftChild->right != nullptr)
    {
        leftChild->right->parent = currentNode;
    }
    leftChild->parent = currentNode->parent;
    if (currentNode->parent == nullptr)
    {
        root = leftChild;
    }
    else if (currentNode == currentNode->parent->right)
    {
        currentNode->parent->right = leftChild;
    }
    else
    {
        currentNode->parent->left = leftChild;
    }
    leftChild->right = currentNode;
    currentNode->parent = leftChild;

}
void fixViolation(Node*& currentNode)
{
    Node* parent = nullptr;
    Node* grandparent = nullptr;

    while ((currentNode != root) && (currentNode->color == Red) && (currentNode->parent->color == Red))
    {
        parent = currentNode->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left)
        {
            Node* uncle = grandparent->right;

            if (uncle != nullptr && uncle->color == Red)
            {
                grandparent->color = Red;
                parent->color = Black;
                uncle->color = Black;
                currentNode = grandparent;
            }
            else
            {
                if (currentNode == parent->right)
                {
                    rotateLeft(parent);
                    currentNode = parent;
                    parent = currentNode->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                currentNode = parent;
            }
        }
        else
        {
            Node* uncle = grandparent->left;

            if ((uncle != nullptr) && (uncle->color == Red))
            {
                grandparent->color = Red;
                parent->color = Black;
                uncle->color = Black;
                currentNode = grandparent;
            }
            else
            {
                if (currentNode == parent->left)
                {
                    rotateRight(parent);
                    currentNode = parent;
                    parent = currentNode->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                currentNode = parent;
            }
        }
    }

    root->color = Black;
};
void insert(const int& data)
{
    Node* newNode = new Node(data);
    root = BSTInsert(root, newNode);
    fixViolation(newNode);
}
Node* BSTInsert(Node*& root, Node* newNode)
{
    if (root == nullptr)
    {
        return newNode;
    }
    if (newNode->Data < root->Data)
    {
        root->left = BSTInsert(root->left, newNode);
        root->left->parent = root;
    }
    else if (newNode->Data > root->Data)
    {
        root->right = BSTInsert(root->right, newNode);
        root->right->parent = root;
    }
    return root;
}
void inorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->Data << " "<<(root->color == Red ? "Red" : "Black") << endl;
    inorder(root->right);
}
};

int main()
{
    R_B_Tree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    cout << "Inorder Traversal of the Red-Black Tree: ";
    tree.inorder(tree.root);
    cout << endl;
    return 0;
}