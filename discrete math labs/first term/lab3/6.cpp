#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> ans;

int main() {
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int a = i >> 0 & 1;
        bool ok = true;
        for (int j = 1; j < n; j++) {
            int b = i >> j & 1;
            if (a + b == 2) {
                ok = false; break;
            }
            a = b;
        }
        if (ok) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (auto i: ans) {
        for (int j = 0; j < n; j++) {
            cout << (i >> (n - j - 1) & 1);
        }
        cout << endl;
    }
    return 0;
}
