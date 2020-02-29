#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

bool ok;
int n, k;
int x[N];
int d[N];

void print() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
    return;
}

void next() {
    int i = n;
    while (i > 1 && ((d[i] == 1 && x[i] == k - 1) || (d[i] == -1 && x[i] == 0))) {
        i--;
    }
    if ((d[i] == 1 && x[i] == k - 1) ||(d[i] == -1 && x[i] == 0)) {
        ok = false;
    } else {
        ok = true;
        x[i] = x[i] + d[i];
        for (int j = i + 1; j <= n; j++) {
            d[j] = -d[j];
        }
    }
    return;
}

int main() {
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        x[i] = 0; d[i] = 1;
    }
    print();
    ok = true;
    while (ok) {
        next();
        if (!ok) {
            return 0;
        }
        print();
    }
    return 0;
}
