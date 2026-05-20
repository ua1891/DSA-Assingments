#include <iostream>
using namespace std;
struct BST{
    int data;
    BST* left;
    BST* right;
    int height;

    BST(int value){
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
 BST* insertAVL(BST* root, int value){
    if(root == NULL){
        return new BST(value);
    }
    if(value < root->data){
        root->left = insertAVL(root->left, value);
    }
    else if(value > root->data){
        root->right = insertAVL(root->right, value);
    }
    root->height = 1 + max(Calheight(root->left), Calheight(root->right));
    int balanceFactor = CalculateBalanceFactor(root);
    if(balanceFactor > 1 && value < root->left->data){
        return RightRotation(root);
    }
    if(balanceFactor < -1 && value > root->right->data){
        return LeftRotation(root);
    }
    if(balanceFactor > 1 && value > root->left->data){
        return LeftRightRotation(root);
    }
    if(balanceFactor < -1 && value < root->right->data){
        return RightLeftRotation(root);
    }
    return root;
}

int Calheight(BST* node){
    if(node == NULL){
        return 0;
    }
    int leftHeight = Calheight(node->left);
    int rightHeight = Calheight(node->right);
    return max(leftHeight, rightHeight) + 1;
}
int CalculateBalanceFactor(BST* node){
    if(node == NULL){
        return 0;
    }
    int leftHeight = Calheight(node->left);
    int rightHeight = Calheight(node->right);
    return leftHeight - rightHeight;
}
BST* LeftRotation(BST* root){
    BST* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}
BST* RightRotation(BST* root){
    BST* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}
BST* LeftRightRotation(BST* root){
    root->left = LeftRotation(root->left);
    return RightRotation(root);
}
BST* RightLeftRotation(BST* root){
    root->right = RightRotation(root->right);
    return LeftRotation(root);
}
BST* inorderTraversal(BST* root){
    if (root==NULL)
    {
        return NULL;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    
}
int main(){
    BST* root = NULL;

    root = insertAVL(root, 5);
    root = insertAVL(root, 1);
    root = insertAVL(root, 3);
    root = insertAVL(root, 4);
    root = insertAVL(root, 2);
    root = insertAVL(root, 7);
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;
    cout<<"Balance Factor of Root: "<<CalculateBalanceFactor(root)<<endl;

    return 0;
}