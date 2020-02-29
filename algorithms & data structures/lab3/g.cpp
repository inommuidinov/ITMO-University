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

const long long N = 1000;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const long long block = 256;
const long double PI = acos(-1.0);

int TN = 1;

int n;
int opt[N][N];
int dp[N][N];
string s;

void ans(int l, int r) {
    if (dp[l][r] == r - l + 1) {
        return;
    }
    if (dp[l][r] == 0) {
        cout << s.substr(l, r - l + 1);
        return;
    }
    if (opt[l][r] == -1) {
        cout << s[l];
        ans(l + 1, r - 1);
        cout << s[r];
        return;
    }
    ans(l, opt[l][r]);
    ans(opt[l][r] + 1, r);
}

void solve() {
    cin >> s; n = sz(s);
    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            if (l == r) {
                dp[l][r] = 1;
            }
            else {
                int mx = INF, mk = -1;
                if (s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']' || s[l] == '{' && s[r] == '}') {
                    mx = dp[l + 1][r - 1];
                }
                for (int k = l; k < r; k++) {
                    if (dp[l][k] + dp[k + 1][r] < mx) {
                        mx = dp[l][k] + dp[k + 1][r]; mk = k;
                    }
                }
                dp[l][r] = mx; opt[l][r] = mk;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    /// cout << n - dp[0][n - 1];
    ans(0, n - 1);
    return;
}

signed main() {
    iostream::sync_with_stdio(0);
    /// cin.tie(NULL); cout.tie(NULL);
    /// ------------------------------------------------
    /// fin("nice.in"); fout("nice.out");
    /// cin >> TN;
    /// ------------------------------------------------
    while (TN--) solve();
    return 0;
}
