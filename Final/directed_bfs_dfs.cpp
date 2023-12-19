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

    // BFS Helper
    void bfs_helper(int node){
        visited[node] = true;

        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cout << x << " ";
            for (int nd : adj_lists[x]) {
                if (!visited[nd]) {
                    q.push(nd);
                    visited[nd] = true;
                }
            }
        }
    }

    void bfs(int node) {
        bfs_helper(node);
        for(int i = 0; i<v;i++){
            if(!visited[i]){
                bfs_helper(i);
            }
        }
    }

    // Depth First Search
    void dfs_helper(int node){
        visited[node] = true;
        cout << node << " ";
        for(int adjNode: adj_lists[node]){
            if(!visited[adjNode]){
                dfs_helper(adjNode);
            }
        }
    }

    void dfs(int node){
        dfs_helper(node);

        for(int i = 0; i<v;i++){
            if(!visited[i]){
                dfs_helper(i);
            }
        }
    }
    ~Graph(){
        delete[] adj_lists;
        delete[] visited;
    }
};


int main(){
    int n,e;
    cin >> n >> e;
    Graph g(n);
    for(int i = 0; i<e;i++){
        int x,y;
        cin >>x >> y;
        g.edge(x,y);
    }
    int s;
    cin >> s;
    g.dfs(s);

    return 0;
}