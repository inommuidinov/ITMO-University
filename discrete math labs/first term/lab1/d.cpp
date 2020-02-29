#include<bits/stdc++.h>

#define int long long
#define pb push_back

using namespace std;

const int N = 7;
const int LOG = 35;

int n;
int res;
int a[N];

int inv(int x) {
    int ans = 0, p = 1;
    while (x) {
        ans += !(x % 2) * p;
        x >>= 1; p <<= 1;
    }
    return ans;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> res;
    vector<string> ans;
    vector<vector<int> > check;
    for (int i = 0; i < LOG; i++) {
        bool bit = (res >> i) & 1;
        if (bit) {
            vector<int> verr;
            string curb = "(";
            for (int j = 1; j <= n; j++) {
                bool cur = (a[j] >> i) & 1;
                if (cur) {
                    verr.pb(j);
                    curb += (j + 48);
                } else {
                    verr.pb(-j);
                    curb = curb + "~" + char(j + 48);
                }
                if (j != n) {
                    curb += '&';
                }
            }
            curb += ')';
            ans.pb(curb);
            ans.pb("|");
            check.pb(verr);
        }
    }
    int total = 0;
    for (int i = 0; i < check.size(); i++) {
        int cur = check[i][0] > 0 ? a[check[i][0]] : inv(a[-check[i][0]]);
        for (int j = 1; j < check[i].size(); j++) {
            cur = (cur & (check[i][j] > 0 ? a[check[i][j]] : inv(a[-check[i][j]])));
        }
        if (i == 0)  {
            total = cur;
        }
        else {
            total = total | cur;
        }
    }
    for (int i = 0; i < LOG; i++) {
        for (int j = 0; j < LOG; j++) {
            bool ok = true;
            int x, y;
            for (int it = 1; it <= n; it++) {
                x = (a[it] >> i) & 1;
                y = (a[it] >> j) & 1;
                if (x != y) {
                    ok = false;
                }
            }

            if (ok && ((res >> i) & 1) != ((res >> j) & 1)) {
                /// cout << i << " " << j << "\n";
                /// cout << x << " " << y << "\n" << ((res >> i) & 1) << " " << ((res >> j) & 1) << "\n";
                cout << "Impossible\n"; return 0;
            }
        }
    }
    if (res == 0) {
        cout << "1&~1"; return 0;
    }
    /*ans.pop_back();
    for (auto i: ans) {
        cout << i;
    }*/
    for (int i = 0; i < check.size(); i++) {
        cout << '(';
        for (int j = 0; j < check[i].size(); j++) {
            if (check[i][j] < 0) {
                cout << '~';
            }
            cout << abs(check[i][j]);
            if (j < check[i].size() - 1) {
                cout << '&';
            }
        }
        cout << ')';
        if (i < check.size() - 1) {
            cout << '|';
        }
    }
    return 0;
}
