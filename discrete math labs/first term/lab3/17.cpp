#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 50;

string ans;
int n, k;
int dp[N + 5][N + 5];

void get() {
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (dp[2 * n - i - 1][cnt + 1] < k) {
            k -= dp[2 * n - i - 1][cnt + 1];
            ans += ')'; cnt--;
        } else {
            ans += '('; cnt++;
        }
    }
    return;
}

signed main() {
    freopen("num2brackets.in", "r", stdin);
    freopen("num2brackets.out", "w", stdout);
    cin >> n >> k; k++;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i - 1][j + 1];
            if (j != 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    get();
    cout << ans << "\n";
    return 0;
}
