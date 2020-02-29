#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 100;

int n, k;
string s;
int dp[N][N];

string get() {
    int cnt = 0, sz = 0;
    string ans = "";
    char c[N];
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
    return ans;
}

signed main() {
    freopen("brackets2num2.in", "r", stdin);
    freopen("brackets2num2.out", "w", stdout);
    //cin >> n >> k;
    //k++;
    cin >> s;
    for (auto i: s) {
        n += i == '(' || i == '[';
    }
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
    int x = 0;
    int l = 0, r = dp[80][0] + 1;
    while (l + 1 <= r) {
        int mid = (l + r) >> 1;
        k = mid;
        string cur = get();
        if (cur < s) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << --l;
    return 0;
}
