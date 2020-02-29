#include<bits/stdc++.h>

using namespace std;

const int N = 110;

int n, k, m;
int dp[N][N];
vector<int> ans;

void get() {
    /*while () {
        cout << k << " " << n - sum << " " << cur << " " << dp[n - sum][cur] << "\n";
        if (k >= dp[n - sum][cur]) {
            k -= dp[n - sum][cur];
            cur--;
        } else {
            ans.push_back(cur);
            sum += cur;
        }
    }*/
    int cur = 1, sum = 0;
    while (sum < n) {
        //cout << k << " " << n - sum - cur << " " << cur << " " << dp[n - sum - cur][cur] << "\n";
        if (k >= abs(dp[n - sum][cur] - dp[n - sum][cur + 1])) {
            k -= abs(dp[n - sum][cur] - dp[n - sum][cur + 1]);
            cur++;
        } else {
            ans.push_back(cur);
            sum += cur;
        }
    }
    // cout << "-----------------\n";
    /*while (sum < n) {
        ans.push_back(cur); sum += cur;
    }*/
    return;
}

int main() {
    freopen("num2part.in", "r", stdin);
    freopen("num2part.out", "w", stdout);
    for (int i = 1; i < N; i++) {
        dp[i][i] = 1;
        dp[i][0] = dp[i][0];
        for (int j = i - 1; j >= 0; j--) {
            dp[i][j] = dp[i - j][j] + dp[i][j + 1];
        }
    }
    /*for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cin >> n >> k;
    m = n;
    get();
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << "+";
    }
    cout << ans.back();
    return 0;
}
