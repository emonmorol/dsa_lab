#include <iostream>
using namespace std;

int firstOccurrence(string& s, char target) {
    int l = 0, r = s.size() - 1, m = -1;
    int first = -1;
    while (l <= r) {
        m = (l + r) / 2;
        if (s[m] > target) {
            l = m + 1;
        } else if (s[m] < target) {
            r = m - 1;
        } else {
            first = m;
            r = m - 1;
        }
    }

    return first;
}

int lastOccurrence(string& s, char target) {
    int l = 0, r = s.size() - 1, m = -1;
    int last = -1;
    while (l <= r) {
        m = (l + r) / 2;
        if (s[m] > target) {
            l = m + 1;
        } else if (s[m] < target) {
            r = m - 1;
        } else {
            last = m;
            l = m + 1;
        }
    }

    return last;
}

int countOccurrence(string& str, char target) {
    int first = firstOccurrence(str, target);
    if (first == -1) {
        return 0;
    }

    int last = lastOccurrence(str, target);
    cout << first << " " << last << endl;

    return last - first + 1;
}

int main() {
    string sortedString = "ssbbbbb";
    char target = 'b';

    int occurrence = countOccurrence(sortedString, target);

    cout << "The occurrence of '" << target << "' is: " << occurrence << endl;

    return 0;
}
