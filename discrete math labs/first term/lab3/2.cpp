#include<bits/stdc++.h>

using namespace std;

int n;

void get(int x) {
    for (int i = 0; i < n; i++) {
        cout << (x >> (n - i - 1) & 1);
    }
    cout << endl;
    return;
}

int main() {
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int cur = i ^ (i / 2); get(cur);
    }
    return 0;
}
