#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *Arr = nullptr;

public:
    Graph(int v)
    {
        this->V = v;
        Arr = new list<int>[V];
    }
    void AddEdge(){
          int Src, Des;
    cout << "Enter edges (enter -1 -1 to stop):\n";
    while (true) {
        cin >> Src >> Des;

        if (Src == -1 && Des == -1)
            break;

        AddHelper(Src, Des);
    }
        
    }
    void AddHelper(int Source, int destination)
    {
        Arr[Source].push_back(destination);
    }
    void countTotalNumberofedges()//Counting the Total Number of Edges 
    {
        int count = 0;
        for (int i = 0; i < V; i++)
        {
                count+=Arr[i].size();
        }
    }
    void TotalVertices(){
        cout<<"The total Number of Vertices is "<<V;
    }
};
int main()
{
    int Vertex, Edge;
    cout << "Enter the Total Number of vertices ";
    cin >> Vertex;
    cout << "Enter the Total Number of Edges ";
    cin >> Edge;
    Graph object(Vertex);
object.AddEdge();
object.countTotalNumberofedges();
object.TotalVertices();
    return 0;
}