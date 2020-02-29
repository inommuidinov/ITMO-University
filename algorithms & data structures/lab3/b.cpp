/// FUCK YOU, PIECE OF SHIT!!!
#include<bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m;
int a[N][N];
int dp[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + a[i][1];
    }
    for (int i = 1; i <= m; i++) {
        dp[1][i] = dp[1][i - 1] + a[1][i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    cout << dp[n][m] << "\n";
    int x = n, y = m;
    string ans = "";
    while (x != 1 || y != 1) {
        // cout << x << " " << y << "\n";
        if (x - 1 >= 1 && dp[x][y] == dp[x - 1][y] + a[x][y]) {
            x--; ans = "D" + ans;
        } else if (y - 1 >= 1 && dp[x][y] == dp[x][y - 1] + a[x][y]) {
            y--; ans = "R" + ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
