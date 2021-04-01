#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

int n1, m1, k1;
int n2, m2, k2;
bool term1[N], term2[N], us[N];
vector<pair<char, int>> verr1[N], verr2[N];

void dfs(int u, int v) {
    us[u] = true;
    if (term1[u] != term2[v] || verr1[u].size() != verr2[v].size()) {
        cout << "NO"; exit(false);
    }
    sort(verr1[u].begin(), verr1[u].end());
    sort(verr2[v].begin(), verr2[v].end());
    for (int i = 0; i < verr1[u].size(); i++) {
        pair<int, int> a = verr1[u][i];
        pair<int, int> b = verr2[v][i];
        if (a.first != b.first) {
            cout << "NO"; exit(false);
        }
        if (!us[a.second]) {
            dfs(a.second, b.second);
        }
    }
}

int main() {
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
    cin >> n1 >> m1 >> k1;
    for (int i = 1; i <= k1; i++) {
        int x; cin >> x;
        term1[x] = true;
    }
    for (int i = 1; i <= m1; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr1[x].push_back({c, y});
    }

    cin >> n2 >> m2 >> k2;
    for (int i = 1; i <= k2; i++) {
        int x; cin >> x;
        term2[x] = true;
    }
    for (int i = 1; i <= m2; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr2[x].push_back({c, y});
    }
    dfs(1, 1);
    cout << "YES";
    return 0;
}
