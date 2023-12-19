#include <bits/stdc++.h>
using namespace std;

bool leafNodesUtil(int arr[], int& index, int N, int min, int max, list<int>& ans) {
    if (index >= N) {
        return false;
    }
    if (arr[index] < min || arr[index] > max) {
        return false;
    }
    int root = arr[index++];
    bool left = leafNodesUtil(arr, index, N, min, root, ans);
    bool right = leafNodesUtil(arr, index, N, root, max, ans);

    if (!left && !right) {
        ans.push_back(root);
    }
    return true;
}

list<int> leafNodes(int arr[], int N) {
    list<int> ans;
    int index = 0;

    leafNodesUtil(arr, index, N, INT_MIN, INT_MAX, ans);

    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    list<int> ans = leafNodes(arr, n);
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << endl;

    return 0;
}
