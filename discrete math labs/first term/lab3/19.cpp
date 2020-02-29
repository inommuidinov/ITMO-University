#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 100;

int n, k;
int cnt, sz;
char c[N];
string ans;
int dp[N][N];

void get() {
    for (int i = n * 2 - 1; i >= 0; i--) {
        int cur = 0;
        if (cnt + 1 <= n) {
            cur = dp[i][cnt + 1] * (1 << ((i - cnt - 1) / 2));
        }
        if (cur >= k) {
            ans += '(';
            c[sz++] = '('; cnt++;
        }
        else {
            k -= cur; cur = 0;
            if (sz > 0 && c[sz - 1] == '(' && cnt - 1 >= 0) {
                cur = dp[i][cnt - 1] * (1 << ((i - cnt + 1) / 2));
            }
            if (cur >= k) {
                ans += ')';
                sz--; cnt--;
            }
            else {
                k -= cur; cur = 0;
                if (cnt + 1 <= n) {
                    cur = dp[i][cnt + 1] * (1 << ((i - cnt - 1) / 2));
                }
                if (cur >= k) {
                    ans += '[';
                    c[sz++] = '['; cnt++;
                }
                else {
                    k -= cur;
                    ans += ']'; sz--; cnt--;
                }
            }
        }
    }
    return;
}

signed main() {
    //freopen("num2brackets2.in", "r", stdin);
    //freopen("num2brackets2.out", "w", stdout);
    cin >> n >> k;
    k++;
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = dp[i - 1][j + 1];
            // dp[i][j] = (j == 0 ? 0 : dp[i - 1][j - 1]) + dp[i - 1][j + 1];
            if (j != 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    get();
    cout << ans << "\n";
    return 0;
}
