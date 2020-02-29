#include <bits/stdc++.h>

using namespace std;

const int N = 13;

int n, m;
int a[N][N];
int dp[N][1 << N];

bool can(int p, int mask1, int mask2) {
    vector<int> verr(n);
    for (int i = 0; i < n; i++) {
        int bit1 = (mask1 >> i) & 1;
        int bit2 = (mask2 >> i) & 1;
        if ((bit1 == 1 && bit2 == 1) || (bit1 == 1 && a[p - 1][i] == 1) || (bit2 == 1 && (a[p - 1][i] == 1 || a[p][i] == 1))) {
            return false;
        }
        verr[i] = (a[p - 1][i] || bit2 || bit1);
    }
    int odd1 = 0;
    for (int i = 0; i < n; i++) {
        if (!verr[i]) {
            odd1 ^= 1;
        }
        else if (odd1 == 1) {
            return false;
        }
    }
    if (odd1) {
        return false;
    }
    return true;
}

int can(int mask) {
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int bit = (mask >> i) & 1;
        int ai = bit || a[m - 1][i];
        if (!ai) {
            odd ^= 1;
        }
        else if (odd == 1) {
            return false;
        }
    }
    return (odd == 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[j][i] = (s[j] == 'X');
        }
    }
    /// if (n > m) swap(n, m);
    int pw2 = (1 << n);
    dp[0][0] = 1;
    for (int i = 1; i < m; i++) {
        for (int mask2 = 0; mask2 < (1 << n); mask2++) {
            for (int mask1 = 0; mask1 < (1 << n); mask1++) {
                dp[i][mask2] += dp[i - 1][mask1] * can(i, mask1, mask2);
            }
        }
    }
    int res = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        res += dp[m - 1][mask] * can(mask);
    }
    cout << res;
    return 0;
}
