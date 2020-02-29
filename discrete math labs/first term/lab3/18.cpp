#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 50;

int n;
int ans;
string s;
int dp[N + 5][N + 5];

void get() {
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            ans += dp[2 * n - 1 - i][cnt + 1];
            cnt--;
        }
    }
    return;
}

signed main() {
    //freopen("brackets2num.in", "r", stdin);
    //freopen("brackets2num.out", "w", stdout);
    getline(cin, s);
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i - 1][j + 1];
            // dp[i][j] = (j == 0 ? 0 : dp[i - 1][j - 1]) + dp[i - 1][j + 1];
            if (j != 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    for (auto i: s) {
        n += i == '(';
    }
    get();
    cout << ans << "\n";
    return 0;
}
