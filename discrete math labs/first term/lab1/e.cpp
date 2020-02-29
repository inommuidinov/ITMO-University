#include<bits/stdc++.h>

#define pb push_back

using namespace std;

const int N = 30;

int n, m, l;
vector<int> ans[N], verr[N];

void dfs(int x = n - 1, int cnt = 0) {
    l = max(l, cnt);
    for (auto it: verr[x]) {
        dfs(it, cnt + 1);
    }
}

int main() {
    cin >> n;
    int func = 0;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        if (m != 0) {
            func++;
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                verr[i].pb(x - 1);
            }
            for (int j = 0; j < (1 << m); j++) {
                int x; cin >> x; ans[i].pb(x);
            }
        }
    }
    int per = n - func;
    string res = "";
    for (int i = 0; i < (1 << per); i++) {
        vector<int> jans(n);
        func = 0;
        for (int j = 0; j < n; j++) {
            if (verr[j].size()) {
                func++;
                int val = 0;
                for (int it: verr[j]) {
                    val = (val << 1) + jans[it];
                }
                jans[j] = ans[j][val]; continue;
            }
            jans[j] = ((i >> (per - j + func - 1)) & 1);
        }
        res += (jans[n - 1] == 0 ? '0' : '1');
    }
    dfs();
    cout << l << "\n" << res << "\n";
    return 0;
}

