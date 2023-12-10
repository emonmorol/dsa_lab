// Author: ekramul11;
#include <bits/stdc++.h>
using namespace std;
// INSERTION SORT
int main() {
    int a[] = {5, 4, 3, 2, 1};
    int n = 5;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        while (a[j] > x && j >= 0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}