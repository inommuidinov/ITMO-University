#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

int n1, m1, k1;
int n2, m2, k2;
map<pair<int, char>, int> verr1, verr2;
bool term1[N], term2[N], us[N][N];

int main() {
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
    cin >> n1 >> m1 >> k1;
    for (int i = 1; i <= k1; i++) {
        int x; cin >> x;
        term1[x] = true;
    }
    for (int i = 1; i <= m1; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr1[{x, c}] = y;
    }

    cin >> n2 >> m2 >> k2;
    for (int i = 1; i <= k2; i++) {
        int x; cin >> x;
        term2[x] = true;
    }
    for (int i = 1; i <= m2; i++) {
        int x, y; char c;
        cin >> x >> y >> c;
        verr2[{x, c}] = y;
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        us[cur.first][cur.second] = true;
        if (term1[cur.first] != term2[cur.second]) {
            cout << "NO"; return 0;
        }
        for (char i = 'a'; i <= 'z'; i++) {
            int to1 = verr1[{cur.first, i}], to2 = verr2[{cur.second, i}];
            if (!us[to1][to2]) {
                q.push({to1, to2});
            }
        }

    }
    cout << "YES";
    return 0;
}

