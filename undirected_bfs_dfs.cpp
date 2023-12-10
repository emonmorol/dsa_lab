#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adjLists;
    bool *visited;

   public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        visited = new bool[vertices];
    }
    void addEdge(int src, int dest) {
        adjLists[src].push_front(dest);
        adjLists[dest].push_front(src);
    }
    void DFS(int vertex) {
        visited[vertex] = true;
        list<int> adjList = adjLists[vertex];

        cout << vertex << " ";

        list<int>::iterator i;
        for (i = adjList.begin(); i != adjList.end(); ++i)
            if (!visited[*i])
                DFS(*i);
    }
    void BFS(int startVertex) {
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        list<int>::iterator i;

        while (!q.empty()) {
            int currVertex = q.front();
            cout << "Visited " << currVertex << endl;
            q.pop();

            for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.DFS(2);
    cout << endl;

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 2);
    g2.addEdge(2, 4);

    g2.BFS(2);

    return 0;
}