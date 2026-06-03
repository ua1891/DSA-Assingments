#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
void insert(Node** root, int value)
{
    if (*root == NULL)
    {
        *root = new Node;
        (*root)->data = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (value < (*root)->data)
    {
        insert(&(*root)->left, value);
    }
    else
    {
        insert(&(*root)->right, value);
    }
}
vector<int> LevelOrderTraversal(Node* root){
    vector<int> Array;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        Array.push_back(current->data);
        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
        
    }
    return Array;
}
int main()
{
    Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    vector<int> result = LevelOrderTraversal(root);
    cout << "Array representation of the binary tree (Level Order Traversal): ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}