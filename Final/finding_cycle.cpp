// author: ekramul11

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    list<int> *adj_lists;
    bool *visited;
    bool isLoopExit;

public:
    Graph(int n) {
        v = n;
        adj_lists = new list<int>[v];
        visited = new bool[v];
        isLoopExit = false;
    }

    void edge(int x, int y) {
        adj_lists[x].push_back(y);
        adj_lists[y].push_back(x);
    }


    // Depth First Search
    bool dfs(int node, int parent) {
        visited[node] = true;
        for (int adjNode : adj_lists[node]) {
            if (visited[adjNode] && (adjNode == parent)) continue;
            if (visited[adjNode]) return true;

            isLoopExit |= dfs(adjNode, node);
        }
        return isLoopExit;
    }


    

    bool detectCycle() {
        for (int i = 0; i < 8; ++i) {
            visited[i] = false;
        }
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfs(i, -1)) {
                    return true;
                    break;
                }
            }
        }
        return false;
    }
    ~Graph() {
        delete[] adj_lists;
        delete[] visited;
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
    cout << g.detectCycle() << endl;
    return 0;
}


