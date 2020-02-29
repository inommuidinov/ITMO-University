#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n;
char ans[N];
char s[N / 2];
set<string> verr;

void print() {
    string cur = "";
    for (int i = 1; i <= n; i++) {
        cur += ans[i];
    }
    verr.insert(cur);
    return;
}

void get(int pos, int j, int left) {
    char c;
    if (pos > n) {
        print(); return;
    }
    if (j > 0) {
        c = s[j];
        ans[pos] = c;
        get(pos + 1, j - 1, left);
        s[j] = c;
    }
    if (left > 0) {
        ans[pos] = '(';
        s[j + 1] = ')';
        get(pos + 1, j + 1, left - 1);
    }
}

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    cin >> n;
    n *= 2;
    get(1, 0, n / 2);
    for (auto i: verr) {
        cout << i << "\n";
    }
    return 0;
}
