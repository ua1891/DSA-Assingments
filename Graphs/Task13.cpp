#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V, E;
    list<int>* Arr = nullptr;

public:

    Graph(int v, int e)
    {
        this->V = v;
        this->E = e;

        Arr = new list<int>[V];
    }

    // Convert Matrix to List
    void MatrixToList()
    {
        int value;

        cout << "Enter Adjacency Matrix:\n";

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cin >> value;

                if (value == 1)
                {
                    Arr[i].push_back(j);
                }
            }
        }
    }

    // Print Adjacency List
    void Display()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            for (int N : Arr[i])
            {
                cout << N << " ";
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

    Graph object(Vertex, 0);

    object.MatrixToList();

    cout << "\nAdjacency List:\n";

    object.Display();

    return 0;
}