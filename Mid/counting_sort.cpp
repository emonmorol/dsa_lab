// Author: ekramul11;
#include <bits/stdc++.h>
using namespace std;

// COUNTING SORT
int main() {
    int a[] = {5, 3, 3, 2, 1, 5};
    int n = 6;
    int freq[6] = {};
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= freq[i]; j++) {
            a[k] = i;
            k++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}