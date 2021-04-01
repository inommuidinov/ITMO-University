#include<bits/stdc++.h>

#define fi first
#define se second
#define int long long

using namespace std;

const int N = 200;
const int MOD = 1000000007LL;

int n;
int start;
string s;
int dp[N][N][N];
vector<pair<char, vector<char>>> verr;

signed main() {
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);
    char c;
    cin >> n >> c;
    start = c;
    while (n--) {
        string from, to, direction;
        cin >> from >> direction >> to;
        vector<char> cur;
        for (int i = 0; i < to.size(); i++) {
            cur.push_back(to[i]);
        }
        verr.push_back({from[0], cur});
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (auto j: verr) {
            dp[i][i][j.fi] += (j.se.size() == 1 && s[i] == j.se[0]);
            /**if (dp[i][i][j.fi] >= MOD) {
                dp[i][i][j.fi] -= MOD;
            }**/
            /// cout << dp[i][i][int(s[i]) - 65] << "\n";
        }
        /// cout << endl;
    }
    /// cout << endl;
    /**
    for (auto i: verr) {
        cout << char(i.fi + 65) << " ";
        for (auto j: i.se) {
            cout << char(j + 65) << " ";
        }
        cout << endl;
    }
    cout << endl;
    **/
    for (int len = 1; len < s.size(); len++) {
        for (int from = 0; from + len < s.size(); from++) {
            for (auto it: verr) {
                if (it.se.size() != 2) continue;
                else {
                    for (int k = from; k < from + len; k++) {
                        dp[from][from + len][it.fi] += (dp[from][k][it.se[0]] * dp[k + 1][from + len][it.se[1]]);
                        dp[from][from + len][it.fi] %= MOD;
                        /**if (dp[from][from + len][it.fi] >= MOD) {
                            dp[from][from + len][it.fi] -= MOD;
                        }**/
                        /// cout << from << " " << from + len << " " << char(it.fi + 65) << " " << dp[from][from + len][it.fi] << "\n";
                    }
                }
            }
        }
    }
    cout << dp[0][s.size() - 1][start];
    return 0;
}
