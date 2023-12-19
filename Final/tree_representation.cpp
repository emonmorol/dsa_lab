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

    void addChild(int parent, int left, int right) {
        if (left != -1) {
            adj_lists[parent].push_back(left);
            adj_lists[left].push_back(parent);
        }

        if (right != -1) {
            adj_lists[parent].push_back(right);
            adj_lists[right].push_back(parent);
        }
    }

    void levelOrderTraversal(int startVertex) {
        for (int i = 0; i < v; i++)
            visited[i] = false;

        list<int> queue;

        visited[startVertex] = true;
        queue.push_back(startVertex);

        list<int>::iterator i;

        while (!queue.empty()) {
            int currVertex = queue.front();
            cout << currVertex << " ";
            queue.pop_front();

            for (i = adj_lists[currVertex].begin(); i != adj_lists[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
    }

    ~Graph() {
        delete[] adj_lists;
        delete[] visited;
    }
};

int main() {
    Graph tree(11);

    tree.addChild(1, 2, 3);
    tree.addChild(2, 4, 5);
    tree.addChild(3, 6, 7);
    tree.addChild(4, 8, 9);
    tree.addChild(5, -1, 10);
    tree.addChild(6, 11, -1);

    tree.levelOrderTraversal(1);

    return 0;
}
