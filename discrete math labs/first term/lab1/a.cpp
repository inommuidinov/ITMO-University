#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, m;
set<pair<int, int> > verr;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        verr.insert({x, y});
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        bool ok = true;
        for (auto i: verr) {
            bool a = (mask >> abs(i.first) - 1) & 1;
            bool b = (mask >> abs(i.second) - 1) & 1;
            if (i.first < 0) {
                a = !a;
            }
            if (i.second < 0) {
                b = !b;
            }
            ok = ok && (a || b);
        }
        if (ok) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
    return 0;
}
