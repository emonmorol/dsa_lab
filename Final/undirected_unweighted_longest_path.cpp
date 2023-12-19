// author: ekramul11

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {
    int v;
    list<int> *adjLists;
    bool *visited;
    int *parent;
    int *path_length;

   public:
    Graph(int n) {
        v = n;
        adjLists = new list<int>[n];
        visited = new bool[n];
        parent = new int[n];
        path_length = new int[n];
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_front(dest);
        adjLists[dest].push_front(src);
    }

    void DFS(int vertex, int depth) {
        visited[vertex] = true;
        path_length[vertex] = depth;

        for (int adjNode : adjLists[vertex]) {
            if (!visited[adjNode]) {
                parent[adjNode] = vertex;
            } else {
                if (path_length[adjNode] < path_length[vertex] + 1) {
                    parent[adjNode] = vertex;
                }
            }
            DFS(adjNode, depth + 1);
        }
    }

    list<int> longest_path(int start, int end) {
        parent[start] = -1;

        DFS(start, 0);

        list<int> path;
        int last = end;

        while (1) {
            path.push_front(last);
            last = parent[last];
            if (last == -1) break;
        }
        return path;
    }

    ~Graph() {
        delete[] adjLists;
        delete[] visited;
        delete[] parent;
        delete[] path_length;
    }
};

int main() {
    Graph g2(6);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 2);
    g2.addEdge(2, 4);
    g2.addEdge(1, 5);

    list<int> path = g2.longest_path(1, 3);

    cout << path.size() - 1 << endl;
    for (int a : path) {
        cout << a << " ";
    }

    return 0;
}