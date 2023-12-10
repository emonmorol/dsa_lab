// Author: ekramul11;

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcdefghijkl";
    int n = s.size();
    char c = 'b';
    int l = 0, r = n - 1, m = -1;
    bool isFound = false;
    while (l <= r) {
        m = (l + r) / 2;
        if (s[m] > c) {
            l = m + 1;
        } else if (s[m] < c) {
            r = m - 1;
        } else {
            isFound = true;
            break;
        }
    }
    return 0;
}