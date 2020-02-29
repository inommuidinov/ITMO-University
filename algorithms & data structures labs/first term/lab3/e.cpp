#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

string s, t;
int dp[N][N];

int main() {
    cin >> s >> t;
    for (int i = 1; i <= s.size(); i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= t.size(); i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1));
        }
    }
    cout << dp[s.size()][t.size()] << "\n";
    return 0;
}
