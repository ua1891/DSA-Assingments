#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int V, E;
    list<int> *Arr = nullptr;

public:
    Graph(int v, int e)
    {
        this->V = v;
        this->E = e;
        Arr = new list<int>[V];
    }
    void AddEdge(){
        for (int i = 0; i < E; i++)
        {
            int Src,Des;
            cin>>Src>>Des;
            AddHelper(Src,Des);
            cout<<"\n";
        }
        
    }
    void AddHelper(int Source, int destination)
    {
        Arr[Source].push_back(destination);
        Arr[destination].push_back(Source);
    }
    void   Degree_of_Vertex(int Required)
    {
        cout<<"It's Degree is "<< Arr[Required].size();

    }
};

int main()
{
    int Vertex, Edge;
    cout << "Enter the Total Number of vertices ";
    cin >> Vertex;
    cout << "Enter the Total Number of Edges ";
    cin >> Edge;
    Graph object(Vertex,Edge);
object.AddEdge();
    cout << "Enter the  Number of vertex which degree you wanna to find";
    int Required;
    cin >> Required;

object.Degree_of_Vertex (Required);
    return 0;
}