#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;
    list<int> *Adjlist = nullptr;
    vector<vector<int>> AdjacencyMatrix;

public:
    Graph(int v)
    {
        this->V = v;
        Adjlist = new list<int>[V];
        AdjacencyMatrix.resize(V, vector<int>(V, 0));
    }

    // Convert Matrix to List
    void inputlist()
    {
        for (int i = 0; i < V; i++)
        {
            int numOfEdges;

            cout << "Enter number of edges for vertex " << i << ": ";
            cin >> numOfEdges;

            cout << "Enter the adjacent vertices for vertex " << i << ": ";

            for (int j = 0; j < numOfEdges; j++)
            {
                int adjacentVertex;
                cin >> adjacentVertex;
                Adjlist[i].push_back(adjacentVertex);
            }
        }
    }
    void listToMatrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int adjacent : Adjlist[i])
            {
                AdjacencyMatrix[i][adjacent] = 1;
            }
        }
    }
    // Print Adjacency List
    void Display()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << AdjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int Vertex, Edge;

    cout << "Enter Total Vertices: ";
    cin >> Vertex;

    Graph object(Vertex);

    object.inputlist();

    object.listToMatrix();

    cout << "\nAdjacency Matrix:\n";

    object.Display();

    return 0;
}