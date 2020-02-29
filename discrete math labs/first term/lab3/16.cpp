#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 35;

int ans;
int n, k;
int a[N];
int c[N][N];


int fact(int x) {
    int s = 1;
    for (int i = 2; i <= x; i++) {
        s *= i;
    }
    return s;
}

void get() {
    for (int i = 1; i <= k; i++) {
        for (int j = a[i - 1] + 1; j <= a[i] - 1; j++) {
            ans += c[n - j][k - i];
        }
    }
    return;
}

signed main() {
   /// freopen("choose2num.in", "r", stdin);
   /// freopen("choose2num.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    get();
    cout << ans << "\n";
    return 0;
}

