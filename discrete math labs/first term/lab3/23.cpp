#include<bits/stdc++.h>

using namespace std;

string s;

string prev(string cur) {
    int pos = cur.size() - 1;
    while (pos >= 0 && cur[pos] == '0') {
        cur[pos--] = '1';
    }
    cur[pos] = '0';
    return cur;
}

string next(string cur) {
    int pos = cur.size() - 1;
    while (pos >= 0 && cur[pos] == '1') {
        cur[pos--] = '0';
    }
    cur[pos] = '1';
    return cur;
}

int main() {
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    cin >> s;
    bool exp = false, exn = false;
    for (auto i: s) {
        if (i == '1') {
            exp = true;
        }
        if (i == '0') {
            exn = true;
        }
    }
    if (!exp) {
        cout << "-\n";
    }
    else {
        cout << prev(s) << "\n";
    }
    if (!exn) {
        cout << "-";
    }
    else {
        cout << next(s);
    }
    return 0;
}
