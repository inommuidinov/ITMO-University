#include<bits/stdc++.h>

#define fi first
#define se second
#define th third

using namespace std;

const int N = 110;

int n;
int a[N];
int dp[N][N];
int pr[N][N];

int main() {
    cin >> n;
    /**if (n == 0) {
        cout << 0 << "\n" << 0 << " " << 0 << "\n";
        return 0;
    }**/
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n + 5; i++) {
        for (int j = 0; j <= n + 5; j++)
            dp[i][j] = 231312;
    }
/**
    5
    110
    40
    120
    110
    60
**/
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            //if (dp[i][j] == -1) continue;
            if (a[i] <= 100) {
            /// cout << a[i] << "\n";
            /// dp[i][j] = min(dp[i - 1][j] + a[i], dp[i - 1][j + 1]);

                if (dp[i - 1][j] + a[i] < dp[i - 1][j + 1]) {
                    dp[i][j] = dp[i - 1][j] + a[i];
                    pr[i][j] = j;
                } else {
                    dp[i][j] = dp[i - 1][j + 1];
                    pr[i][j] = j + 1;
                   /// cout << i << " " << j << " " << dp[i][j] << "\n";
                }
               /// cout << "i = " << i << " j = " << j << " dp[i][j] = " << dp[i][j] << "\n";
            }
            else {
             ///    cout << a[i] << "\n";
                if (j > 0) {
                   /// dp[i][j] = min(dp[i - 1][j - 1] + a[i], dp[i - 1][j + 1]);

                    if (dp[i - 1][j - 1] + a[i] < dp[i - 1][j + 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + a[i];
                        pr[i][j] = j - 1;
                    } else {
                        dp[i][j] = dp[i - 1][j + 1];
                        pr[i][j] = j + 1;
                    }
                } else {
                    dp[i][j] = dp[i - 1][j + 1];
                    pr[i][j] = j + 1;
                }
                /// cout << "i = " << i << " j = " << j << " dp[i][j] = " << dp[i][j] << "\n";
            }
        }
    }
    /**
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    **/
    int ans = INT_MAX, pos = 0;
    for (int i = 0; i <= n; i++) {
        if (ans >= dp[n][i]) {
            ans = dp[n][i]; pos = i;
        }
    }
    /**for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "i = " << i << " j = " << j << " pr[i][j] = " << pr[i][j].fi.fi << " " << pr[i][j].fi.se << " " << pr[i][j].se << "\n";
        }
    }**/
    cout << ans << "\n";
    int x = pos, y = 0;
    int j = pos;
    vector<int> verr;
    for (int i = n; i >= 1; i--) {
        if (j == pr[i][j] - 1) {
            verr.push_back(i);
        }
        j = pr[i][j];
    }
    cout << x << " " << verr.size() << "\n";
    reverse(verr.begin(), verr.end());
    for (auto i: verr) {
        cout << i << "\n";
    }
    return 0;
}
