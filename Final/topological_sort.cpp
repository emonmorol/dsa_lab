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
    }

    void dfs(int node, stack<int> &q) {
        visited[node] = true;
        for (int adjNode : adj_lists[node]) {
            if (!visited[adjNode]) {
                dfs(adjNode, q);
            }
        }
        q.push(node);
    }

    void topological_sort(int node) {
        stack<int> q;
        dfs(node, q);
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, q);
            }
        }
        while (!q.empty()) {
            cout << q.top() << " ";
            q.pop();
        }
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
    int s;
    cin >> s;
    g.topological_sort(s);

    return 0;
}