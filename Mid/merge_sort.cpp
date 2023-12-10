// Author: ekramul11;
#include <bits/stdc++.h>
using namespace std;
int *merge_sort(int a[], int n) {
    if (n < 1) return a;
    if (n == 1) return a;
    int md = n / 2;
    int x[md], y[n - md];
    int p = 0, q = 0;
    for (int i = 0; i < n; i++) {
        if (i <= md) {
            x[p] = a[i];
            p++;
        } else {
            y[q] = a[i];
            q++;
        }
    }
    int *s_x, *s_y;
    s_x = merge_sort(x, md);
    s_y = merge_sort(y, n - md);
    for (int i = 0; i < md; i++) {
        cout << s_x[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n - md; i++) {
        cout << s_y[i] << " ";
    }
    cout << endl;
    int i = 0, j = 0;
    for (int k = 0; k < n; k++) {
        if (i == md) {
            a[k] = s_y[j];
            j++;
        } else if (j == (n - md)) {
            a[k] = s_y[i];
            i++;
        }
        if (s_x[i] < s_y[j]) {
            a[k] = s_x[i];
            i++;
        } else if (s_x[i] > s_y[j]) {
            a[k] = s_y[j];
            j++;
        }
    }
    return a;
}

int main() {
    int a[] = {10, 18, 16, 25, 972, 2023, 34, 0, 45};
    int n = 9;
    int *x = merge_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    return 0;
}