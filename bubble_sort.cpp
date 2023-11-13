// Author: ekramul11;
#include <bits/stdc++.h>
using namespace std;

// BUBBLE SORT
int main() {
    int a[] = {5, 4, 3, 2, 1};
    int n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}