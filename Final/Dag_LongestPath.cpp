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

    stack<int> topological_order(int node) {
        stack<int> q;
        dfs(node, q);
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, q);
            }
        }
        return q;
    }


    int longest_path(int s, int d) {
        stack<int> order = topological_order(s);

        int dist[v];

        for (int i = 0; i < v; i++) dist[i] = INT_MIN;
        dist[s] = 0;

        while (!order.empty()) {
            int x = order.top();
            order.pop();
            if (dist[x] != INT_MIN) {
                for (auto node : adj_lists[x]) {
                    int p = dist[node];
                    int q = dist[x];
                    if (q + 1 > p) dist[node] = q + 1;
                }
            }
        }
        
        return dist[d];
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
    int s, d;
    cin >> s >> d;
    int dst = g.longest_path(s, d);
    cout << dst << endl;

    return 0;
}