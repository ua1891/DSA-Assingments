#include <iostream>
#include <list>
#include <utility>

using namespace std;
class Graph
{
    int V, E;
list<pair<int, int>> *Arr= nullptr; 

public:
    Graph(int v, int e)
    {
        this->V = v;
        this->E = e;
        Arr = new list<pair<int, int>>[V];
    }
    void AddEdge(){
        for (int i = 0; i < E; i++)
        {
            int Src,Des,weight;
            cin>>Src>>Des>>weight;
            AddHelper(Src,Des,weight);
            cout<<"\n";
        }
        
    }
    void AddHelper(int Source, int destination,int weight)
    {
      Arr[Source].push_back(make_pair(destination,weight));
      
    }
    void Adja_matrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            { int Value=-1;
                bool found = false;
                for (auto N : Arr[i])
                { 
                    if (N.first == j)
                    {  Value=N.second;
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    cout<<Value<<" ";

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