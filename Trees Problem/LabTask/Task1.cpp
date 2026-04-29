#include <iostream>
#include <vector>
using namespace std;
struct Tree
{
    int Data;
    vector<Tree *> children;
    Tree(int value)
    {
        Data = value;
    }
};
void PrintAllNode(Tree* tree){
    if (tree==NULL)
    {
        return;
    }
    cout<<tree->Data<<" ";
    for ( Tree* child : tree->children )
    {
        PrintAllNode(child);
    }
    
    
    

}
int main()
{
    Tree *Root = new Tree(10);
    Tree *child1 = new Tree(20);
    Tree *child2 = new Tree(30);
    Tree *child3 = new Tree(40);
    Root->children.push_back(child1);
    Root->children.push_back(child2);
    Root->children.push_back(child3);

    Tree *grandchild1 = new Tree(50);
    Tree *grandchild2 = new Tree(60);

    child1->children.push_back(grandchild1);
    child1->children.push_back(grandchild2);
    cout<<"Printing All Nodes";
    PrintAllNode(Root);
    cout<<endl;
    return 0;
}