// Author: ekramul11;

#include <bits/stdc++.h>
#define yes cout << "YES"
#define no cout << "NO"

using namespace std;
typedef long long int lli;
const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x = 16;
    while (x <= 53) {
        if (x % 2 != 0) cout << x << ",";
        x++;
    }
    return 0;
}