#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> us;
vector<vector<int>> verr;

vector<int> convert(string cur) {
    cur += " ";
    int tmp = 0;
    vector<int> res;
    for (int i = 0; i < cur.size(); i++) {
        if (cur[i] == ' ') {
            res.push_back(tmp);
            tmp = 0;
        } else {
            tmp *= 10; tmp += (cur[i] - 48);
        }
    }
    return res;
}

void get() {
    us.clear();
    for (int i = verr.size() - 1; i >= 0; i--) {
        sort(us.begin(), us.end());
        for (int j = 0; j < us.size(); j++) {
            if (us[j] > verr[i].back()) {
                verr[i].push_back(us[j]);
                for (auto k: us) {
                    if (k != us[j]) {
                        verr.push_back(vector<int>(1, k));
                    }
                }
                return;
            }
        }
        if (verr[i].size() == 1) {
            us.push_back(verr[i].back());
            verr.pop_back();
            continue;
        }
        us.push_back(verr[i].back());
        verr[i].pop_back();
        for (int j = verr[i].size() - 1; j >= 0; j--) {
            if (!j) {
                break;
            }
            int cur = verr[i][j];
            sort(us.begin(), us.end());
            for (int t = 0; t < us.size(); t++) {
                if (us[t] > cur) {
                    verr[i][j] = us[t];
                    for (auto k: us) {
                        if (k == us[t]) {
                            k = cur;
                        }
                        verr.push_back(vector<int>(1, k));
                    }
                    return;
                }
            }
            us.push_back(cur);
            verr[i].pop_back();
        }
        us.push_back(verr[i][0]);
        verr.pop_back();
    }
    sort(us.begin(), us.end());
    for (auto j: us) {
        verr.push_back(vector<int>(1, j));
    }
    return;
}

void solve() {
    verr.resize(k);
    string s; getline(cin, s);
    for (int i = 0; i < k; i++) {
        getline(cin, s);
        verr[i] = convert(s);
    }
    get();
    cout << n << " " << verr.size() << "\n";
    for (auto i: verr) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    freopen("nextsetpartition.in", "r", stdin);
    freopen("nextsetpartition.out", "w", stdout);
    while (cin >> n >> k) {
        if (!n && !k) {
            return 0;
        }
        solve();
    }
    return 0;
}
