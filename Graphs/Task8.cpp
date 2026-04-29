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
    }
    void FindEdgeBetweenTwoVertex(int Source,int Destination){
        bool found = false;
        for (int N : Arr[Source])
        {
            if (N == Destination)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout<<"The Edge exsists Between Vertices"<<Source<<"and"<<Destination;

        }
        else{
            cout<<"The Edge doesn't exsists Between Vertices"<<Source<<"and"<<Destination;
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
    Graph object(Vertex,Edge);
object.AddEdge();
object.FindEdgeBetweenTwoVertex(1,2);
    return 0;
}