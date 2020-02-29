#include<bits/stdc++.h>

using namespace std;

const int N = 110;

string s;
int n;
int pos;
int ans;
int sum;
int last;
int a[N];
int dp[N][N];

int convert(string cur) {
    int num = 0;
    for (auto i: cur) {
        num = num * 10 + (int(i) - 48);
    }
    return num;
}

void get() {
    for (int i = 1; i < pos; i++) {
        for (int j = last; j <= a[i] - 1; j++) {
           /// cout << n - sum - j << "\n";
            ans += dp[n - sum - j][j];
            cout << n - sum - j << " " << dp[n - sum - j][j] << "\n";
        }
        sum += a[i]; last = a[i];
    }
    return;
}

int main() {
   /// freopen("part2num.in", "r", stdin);
   /// freopen("part2num.out", "w", stdout);
    cin >> s; s += '+'; pos++;
    for (int i = 0; i < s.size(); i++) {
        string cur = "";
        while (s[i] != '+') {
            cur += s[i]; i++;
        }
        a[pos] = convert(cur);
        n += a[pos]; pos++;
    }
    cout << n << "\n";
    // cout << n << "\n";
    for (int i = 1; i < N; i++) {
        dp[i][i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            dp[i][j] = dp[i - j][j] + dp[i][j + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            /// cout << "dp[" << i << "][" << j << "] " << dp[i][j] << " ";
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    get();
    cout << ans << "\n";
    return 0;
}
