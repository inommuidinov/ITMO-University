#include<bits/stdc++.h>

using namespace std;

const int N = 110;
const int MOD = 1e9 + 7;

int ans;
bool term[N];
int n, m, k, l;
int dp[N][N * 10];
vector<int> verr[N];
/*
void dfs(int x, int len = 0) {
    if (len == l && term[x]) {
        ans++; ans %= MOD;
        return;
    }
    else if (len == l) {
        return;
    }
    for (auto i: verr[x]) {
        dfs(i, len + 1);
    }
}
*/
int main() {
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        term[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr[x].push_back(y);
    }
    dp[1][0] = 1;
    for (int len = 0; len < l; len++) {
        for (int con = 1; con <= n; con++) {
            for (auto to: verr[con]) {
                dp[to][len + 1] += dp[con][len];
                if (dp[to][len + 1] >= MOD) {
                    dp[to][len + 1] -= MOD;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (term[i]) {
            ans += dp[i][l];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
