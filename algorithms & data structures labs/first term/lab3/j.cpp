#include <iostream>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define rank rank1
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;

const int N = 100;

int TN = 1;

int n, m;
int ans;
int a[N][N];
bool dp[40][40];

void solve() {
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            bool ok = true;
            for (int k = 0; k < n - 1; k++) {
                if (bool(i & (1 << k)) == bool(i & (1 << (k + 1))) && bool(j & (1 << k)) == bool(j & (1 << (k + 1))) && bool(i & (1 << k)) == bool(j & (1 << k))) {
                    ok = false;
                }
            }
            dp[i][j] = ok ? 1 : 0;
        }
    }
    for (int i = 0; i < 1 << n; i++) {
        a[0][i]++;
    }
    for (int k = 1; k < m; k++) {
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < 1 << n; j++) {
                a[k][i] = a[k][i] + a[k - 1][j] * dp[j][i];
            }
        }
    }
    for (int i = 0; i < 1 << n; i++) {
        ans += a[m - 1][i];
    }
    cout << ans << "\n";
    return;
}

int main() {
    /// iostream::sync_with_stdio(0);
    /// cin.tie(NULL); cout.tie(NULL);
    /// ------------------------------------------------
    /// fin("nice.in"); fout("nice.out");
    /// cin >> TN;
    /// ------------------------------------------------
    while (TN--) solve();
    return 0;
}
