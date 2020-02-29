#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 100100;

int n, k;
int a[N];
int dp[N];
int pr[N];

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 2; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MIN;
    }
    dp[1] = a[1];
    pr[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= i + k && j <= n; j++) {
            if (dp[j] <= dp[i] + a[j]) {
                dp[j] = dp[i] + a[j];
                pr[j] = i;
            }
            // dp[j] = max(dp[j], dp[i] + a[j]);
        }
    }
    cout << dp[n] << "\n";
    int x = n;
    vector<int> ans;
    while (pr[x] != x) {
        ans.push_back(x);
        x = pr[x];
    }
    cout << ans.size() << "\n";
    cout << 1 << " ";
    reverse(ans.begin(), ans.end());
    for (auto i: ans) {
        cout << i << " ";
    }
    return 0;
}
