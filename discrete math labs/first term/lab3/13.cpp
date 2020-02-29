#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 20;

int n, k;
int us[N];
int ans[N];

int fact(int x) {
    int s = 1;
    for (int i = 2; i <= x; i++) {
        s *= i;
    }
    return s;
}

void get() {
    for (int i = 1; i <= n; i++) {
        int prev = fact(n - i);
        int was = k / prev;
        k %= prev;
        cout << k << " " << prev << " " << was << "\n";
        int free = 0;
        for (int j = 1; j <= n; j++) {
            if (!us[j]) {
                free++;
                if (free == was + 1) {
                    ans[i] = j;
                    us[j] = 1;
                }
            }
        }
    }
    return;
}

signed main() {
    ///freopen("num2perm.in", "r", stdin);
    ///freopen("num2perm.out", "w", stdout);
    cin >> n >> k; get();
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
