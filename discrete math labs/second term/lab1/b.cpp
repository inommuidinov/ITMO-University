#include<bits/stdc++.h>

using namespace std;

const int N = 110;

string s;
int n, m, k;
bool term[N];
bool ok = false;
vector<pair<int, int>> verr[N];
/**
void dfs(int x, int pos = 0) {
    if (pos == s.size() && term[x]) {
        cout << "Accepts"; exit(false);
    } else if (pos == s.size()) {
        return;
    }
    bool go = false;
    for (auto i: verr[x]) {
        if (i.second == s[pos]) {
            go = true; break;
        }
    }
    if (go == false) return;
    for (auto i: verr[x]) {
        if (i.second == s[pos]) {
            dfs(i.first, pos + 1);
        }
    }
}
**/
int main() {
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> s;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        term[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr[x].push_back({int(c - 'a'), y});
    }
    set<int> q;
    q.insert(1);
    for (int i = 0; i < s.size(); i++) {
        int sz = q.size();
        set<int> new_q;
        for (auto j: q) {
            int symbol = s[i] - 'a';
            for (auto too: verr[j]) {
                if (too.first == symbol)
                    new_q.insert(too.second);
            }
        }
        q = new_q;
    }
    for (auto i: q) {
        if (term[i]) {
            cout << "Accepts"; return 0;
        }
    }
    cout << "Rejects";
    return 0;
}
