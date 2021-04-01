#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

string s;
int n, m, k;
bool term[N];
bool ok = false;
vector<pair<int, char>> verr[N];

void dfs(int x, int pos = 0) {
    if (pos == s.size() && term[x]) {
        cout << "Accepts"; exit(false);
    } else if (pos == s.size()) {
        return;
    }
    for (auto i: verr[x]) {
        if (i.second == s[pos]) {
            dfs(i.first, pos + 1);
        }
    }
}

int main() {
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
    cin >> s;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        term[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr[x].push_back({y, c});
    }
    dfs(1);
    cout << "Rejects";
    return 0;
}
