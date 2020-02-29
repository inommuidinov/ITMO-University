#include<bits/stdc++.h>

using namespace std;

const int N = 10010;

int n, k;
int a[N];

void next() {
    int pos = k - 1;
    while (pos >= 0 && a[pos + 1] < a[pos] + 2) {
        pos--;
    }
    if (pos < 0) {
        cout << -1 << "\n";
        return;
    }
    a[pos]++;
    for (int i = pos + 1; i < k; i++) {
        a[i] = a[i - 1] + 1;
    }
    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }
    return;
}

int main() {
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    a[k] = n + 1;
    next();
    return 0;
}
