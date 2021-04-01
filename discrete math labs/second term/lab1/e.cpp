#include<bits/stdc++.h>

using namespace std;

const int N = 101;
const int MOD = 1e9 + 7;

int num;
int dp[N][N * 10];
bool term[N];
bool new_term[N];
int n, m, k, l;
queue<set<int>> Q;
map<set<int>, int> us;
vector< vector< vector<int> > > ans(N, vector< vector<int>>(26));
vector< vector< vector<int> > > verr(N, vector< vector<int>>(26));

int main() {
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        term[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr[x][int(c - 'a')].push_back(y);
    }
    set<int> q; q.insert(1);
    Q.push(q);
    us[q] = ++num;
    while (!Q.empty()) {
        q = Q.front(); Q.pop();
        bool ter = false;
        for (auto i: q) {
            if (term[i]) {
                ter = true;
                break;
            }
        }
        new_term[us[q]] = ter;
        for (int c = 0; c < 26; c++) {
            set<int> cur;
            for (auto i: q) {
                for (auto to: verr[i][c]) {
                    cur.insert(to);
                }
            }
            if (us[cur] != 0) {
                ans[us[q]][c].push_back(us[cur]);
            } else {
                if (cur.empty()) continue;
                Q.push(cur);
                us[cur] = ++num;
                ans[us[q]][c].push_back(num);
            }
        }
    }
    dp[1][0] = 1;
    for (int len = 0; len < l; len++) {
        for (int con = 1; con <= 100; con++) {
            for (int c = 0; c < 26; c++) {
                for (auto to: ans[con][c]) {
                    dp[to][len + 1] += dp[con][len];
                    if (dp[to][len + 1] >= MOD) {
                        dp[to][len + 1] -= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if (new_term[i]) {
            ans += dp[i][l];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
