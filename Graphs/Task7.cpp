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
    /*Previous Details is same Now  I am going to Write code for
        Find Degree of My Directed graph Vertex
    */
    void Outdegree(int Vertex)
    {
        cout << "The Vertex Out Degree  is /n" << Arr[Vertex].size();
    }
    void Indegree(int Vertex)
    {
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (i == Vertex)
            {
                continue;
            }
            else
            {
                for (auto N : Arr[i])
                {
                    if (N == Vertex)
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        cout << "The Vertex In Degree  is " << count;
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
    cout << "Enter the  Number of vertex which degree you wanna to find";
    int Required;
    cin >> Required;
    object.Outdegree(Required);
    object.Indegree(Required);
    return 0;
}