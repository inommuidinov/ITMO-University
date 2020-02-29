#include<bits/stdc++.h>

using namespace std;

const int N = 2020;

int n;
int a[N];
int dp[N];
int pr[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = 1;
    int ans = 1, pos = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1; pr[i] = i;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pr[i] = j;
                }
                if (ans < dp[i]) {
                    ans = dp[i]; pos = i;
                }
            }
        }
    }
    /*cout << ans << "\n" << pos << "\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " " << pr[i] << "\n";
    }*/
    vector<int> res;
    while (pr[pos] != pos) {
        /// cout << pos << "\n";
        res.push_back(a[pos]);
        pos = pr[pos];
    }
    /// cout << pos << "\n";
    res.push_back(a[pos]);
    cout << res.size() << "\n";
    reverse(res.begin(), res.end());
    for (auto i: res) {
        cout << i << " ";
    }
    return 0;
}
