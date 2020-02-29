#include<bits/stdc++.h>

using namespace std;

const int N = 110;
const int MOD = 1e9;

int n;
int dp[10][N];

int main() {
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        dp[0][i] = (dp[6][i - 1] + dp[4][i - 1]) % MOD;
        dp[1][i] = (dp[6][i - 1] + dp[8][i - 1]) % MOD;
        dp[2][i] = (dp[7][i - 1] + dp[9][i - 1]) % MOD;
        dp[3][i] = (dp[8][i - 1] + dp[4][i - 1]) % MOD;
        dp[4][i] = ((dp[3][i - 1] + dp[9][i - 1]) % MOD + dp[0][i - 1]) % MOD;
        dp[6][i] = ((dp[1][i - 1] + dp[7][i - 1]) % MOD + dp[0][i - 1]) % MOD;
        dp[7][i] = (dp[2][i - 1] + dp[6][i - 1]) % MOD;
        dp[8][i] = (dp[1][i - 1] + dp[3][i - 1]) % MOD;
        dp[9][i] = (dp[2][i - 1] + dp[4][i - 1]) % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= 7; i++) {
        ans += dp[i][n];
        ans %= MOD;
    }
    ans += dp[9][n];
    ans %= MOD;
    cout << ans << "\n";
    return 0;
}
