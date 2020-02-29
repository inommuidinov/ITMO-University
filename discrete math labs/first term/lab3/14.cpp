#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 20;

int n;
int ans;
int a[N];
int us[N];

int fact(int x) {
    int s = 1;
    for (int i = 2; i <= x; i++) {
        s *= i;
    }
    return s;
}

void get() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i] - 1; j++) {
            if (!us[j]) {
                ans += fact(n - i);
            }
        }
        us[a[i]] = 1;
    }
    return;
}

signed main() {
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    get();
    cout << ans << "\n";
    return 0;
}
