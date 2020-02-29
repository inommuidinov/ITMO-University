#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

int n;
int pos;
int a[N];
string s;

int convert(string cur) {
    int num = 0;
    for (auto i: cur) {
        num = num * 10 + (int(i) - 48);
    }
    return num;
}

void get() {
    a[pos]--; a[pos - 1]++;
    if (a[pos - 1] > a[pos]) {
        a[pos - 1] += a[pos];
        pos--; return;
    }
    while (a[pos - 1] * 2 <= a[pos]) {
        a[pos + 1] = a[pos] - a[pos - 1]; pos++;
        a[pos - 1] = a[pos - 2];
    }
    return;
}

int main() {
    ///freopen("nextpartition.in", "r", stdin);
    /// freopen("nextpartition.out", "w", stdout);
    cin >> s;
    s += '+';
    int i = 0;
    string cur = "";
    while (s[i] != '=') {
        cur += s[i]; i++;
    }
    n = convert(cur);
    i++;
    for (; i < s.size(); i++) {
        cur = "";
        while (s[i] != '+') {
            cur += s[i]; i++;
        }
        a[++pos] = convert(cur);
    }
    if (pos == 1) {
        cout << "No solution"; return 0;
    }
    get();
    cout << n << "=";
    for (int i = 1; i <= pos; i++) {
        cout << a[i];
        if (i != pos) {
            cout << "+";
        }
    }
    return 0;
}
