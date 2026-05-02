#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void Postorder(Node* root);
void Preorder(Node* root);
void Inorder(Node* root);   
void MixTraversal(Node* root);


void Preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}
void Postorder(Node* root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";

}
void Inorder(Node* Root){
    if(Root==NULL){
        return;
    }
    Inorder(Root->left);
    cout<<Root->data<<" ";
    Inorder(Root->right);
}
void MixTraversal(Node* root){
    if(root==NULL){
        return;
    }
    Preorder(root->left);
    cout<<root->data<<"  ";
    Postorder(root->right);
    
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
cout<<"Result of Post Order:";
Postorder(root);
cout<<endl;
cout<<"Result of Pre Order:";
Preorder(root);
cout<<endl;
cout<<"Result of Inorder";
Inorder(root);
cout<<endl;
cout<<"Result of Mix Traversal";
MixTraversal(root);
cout<<endl;

return 0;
}