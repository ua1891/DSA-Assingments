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
    void Adja_matrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            { 
                bool found = false;
                for (int N : Arr[i])
                { 
                    if (N == j)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    cout<<" 1 ";
                    
                }
                else{
                    cout<<" 0 ";
                }
            }
            cout<<"\n";
        }
    }
};

int main()
{
    int Vertex, Edge;
    cout << "Enter the  Number of vertices ";
    cin >> Vertex;
    cout << "Enter the Total Number of Edges ";
    cin >> Edge;
    Graph object(Vertex,Edge);
object.AddEdge();
object.Adja_matrix();
    return 0;
}