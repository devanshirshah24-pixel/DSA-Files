#include <iostream>
#include <queue>
using namespace std;

#define MAX 10

class Graph
{
    int adj[MAX][MAX];
    int vertices;

public:

    Graph(int v)
    {
        vertices = v;

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // DFS using recursion
    void DFS(int start, bool visited[])
    {
        cout << start << " ";
        visited[start] = true;

        for (int i = 0; i < vertices; i++)
        {
            if (adj[start][i] == 1 && !visited[i])
            {
                DFS(i, visited);
            }
        }
    }

    // BFS using queue
    void BFS(int start)
    {
        bool visited[MAX] = {false};

        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (adj[current][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);

    // Adding roads
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    bool visited[MAX] = {false};

    cout << "DFS Traversal: ";
    g.DFS(0, visited);

    cout << endl;

    cout << "BFS Traversal: ";
    g.BFS(0);

    cout << endl;

    return 0;
}