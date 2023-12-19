// author: ekramul11

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    list<int> *adj_lists;
    bool *visited;

   public:
    Graph(int n) {
        v = n;
        adj_lists = new list<int>[v];
        visited = new bool[v];
    }

    void edge(int x, int y) {
        adj_lists[x].push_back(y);
        adj_lists[y].push_back(x);
    }

    // Depth First Search
    void dfs(int node) {
        visited[node] = true;
        for (int adjNode : adj_lists[node]) {
            if (!visited[adjNode]) {
                dfs(adjNode);
            }
        }
    }

    int findingConnectedGraphs(int node) {
        dfs(node);
        int cnt = 1;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        return cnt;
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
    int connected = g.findingConnectedGraphs(1);
    cout << connected;

    return 0;
}