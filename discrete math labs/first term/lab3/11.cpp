#include<bits/stdc++.h>

using namespace std;

const int N = 15;

int n;
int a[N];
vector<vector<string> > ans;

string convert(int x) {
    string res = "";
    if (x == 10) x = 99;
    while (x != 0) {
        res = char(x % 10 + 48) + res;
        x /= 10;
    }
    return res;
}

int main() {
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    for (int i = 0; i < (1 << n); i++) {
        vector<string> cur;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1 == 1) {
                cur.push_back(convert(a[j]));
            }
        }
        ans.push_back(cur);
    }
    sort(ans.begin(), ans.end());
    for (auto i: ans) {
        for (auto j: i) {
            if (j == "99") j = "10";
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
