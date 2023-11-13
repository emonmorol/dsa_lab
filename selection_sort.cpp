// Author: ekramul11;
#include <bits/stdc++.h>
using namespace std;

// SELECTION SORT
int main() {
    int a[] = {5, 4, 3, 2, 1};
    int n = 5;
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}