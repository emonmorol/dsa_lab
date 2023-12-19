// Author: ekramul11

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int v;
    list<int> *adjLists;
    bool *visited;
    int *parent;

public:
    Graph(int n) {
        v = n;
        adjLists = new list<int>[n];
        visited = new bool[n];
        parent = new int[n];
    }

    void edge(int src, int dest) {
        adjLists[src].push_front(dest);
        adjLists[dest].push_front(src);
    }

    void BFS(int startVertex) {
        for (int i = 0; i < v; i++)
            visited[i] = false;

        queue<int> q;

        visited[startVertex] = true;
        parent[startVertex] = -1;

        q.push(startVertex);

        while (!q.empty()) {
            int currVertex = q.front();
            q.pop();

            for (int adjVertex : adjLists[currVertex]) {
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    parent[adjVertex] = currVertex;
                    q.push(adjVertex);
                }
            }
        }
        cout << endl;
    }

    list<int> shortest_path(int start, int end) {
        BFS(start);
        list<int> path;
        int last = end;

        while (1) {
            path.push_front(last);
            last = parent[last];
            if (last == -1) break;
        }
        return path;
    }
};

int main() {
    
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        g.edge(x, y);
    }

    list<int> path = g.shortest_path(4, 5);

    cout << path.size() - 1 << endl;
    for (int a : path) {
        cout << a << " ";
    }

    return 0;
}