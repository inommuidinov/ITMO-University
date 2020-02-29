#include <bits/stdc++.h>

#define int long long
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

const long long N = 500;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const long double PI = acos(-1.0);

int TN = 1;

int n;
int a[N][N];
int dp[20 * N][N], pre[20 * N][N];
int sum = INT_MAX;
vector<int> ans;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int mask = 1; mask <= (1 << n) - 1; mask++) {
        for (int u = 0; u < n; u++) {
            dp[mask][u] = INF;
            int cur = 0;
            for (int v = 0; v < n; v++) {
                if ((mask & (1 << v)) != 0 && dp[mask & ~(1 << v)][v] + a[v][u] < dp[mask][u]) {
                        dp[mask][u] = dp[mask & ~(1 << v)][v] + a[v][u];
                        pre[mask][u] = v;
                }
            }
        }
    }
    int mask = (1 << n) - 1, pred = 0;
    for (int i = 0; i < n; i++) {
        if (dp[(1 << n) - 1][i] < sum) {
            sum = dp[(1 << n) - 1][i]; pred = i;
        }
    }
    cout << sum << "\n";
    for (int k = 0; k < n; k++) {
        ans.pb(pre[mask][pred] + 1);
        pred = pre[mask][pred];
        mask -= (mask & (1 << pred));
    }
    reverse(all(ans));
    for (auto i: ans) {
        cout << i << " ";
    }
    return;
}

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    /// ------------------------------------------------
    /// fin("birthday.in"); fout("birthday.out");
    /// cin >> TN;
    /// ------------------------------------------------
    while (TN--) solve();
    return 0;
}
