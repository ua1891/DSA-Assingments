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
    void AddEdge()
    {
        for (int i = 0; i < E; i++)
        {
            int Src, Des;
            cin >> Src >> Des;
            AddHelper(Src, Des);
            cout << "\n";
        }
    }
    void AddHelper(int Source, int destination)
    {
        Arr[Source].push_back(destination);
    }
    void AlldirectlyConnectedVertices(int Source)
    {
        cout << "The directly connected vertices with " << Source << " are: ";
        for (int N : Arr[Source])
        {
            cout << N << " ";
        }
    }
};
int main()
{
    int Vertex, Edge;
    cout << "Enter the Total Number of vertices ";
    cin >> Vertex;
    cout << "Enter the Total Number of Edges ";
    cin >> Edge;
    Graph object(Vertex, Edge);
    object.AddEdge();
    cout << "Enter the  Number of vertex which directly connected vertices you wanna to find";
    int Required;
    cin >> Required;
    object.AlldirectlyConnectedVertices(Required);
    return 0;
}