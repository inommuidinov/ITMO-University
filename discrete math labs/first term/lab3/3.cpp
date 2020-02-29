#include<bits/stdc++.h>

using namespace std;

int n;
int pos;
vector<string> ans;

void check() {
    if (ans.size() == pow(3, n - 1)) {
        for (int j = 0; j < ans.size(); j++) {
            string cur = ans[j];
            cout << cur << "\n";
            for (int i = 0; i < cur.size(); i++) {
                cur[i] = char((cur[i] - 48 + 1) % 3 + 48);
            }
            cout << cur << "\n";
            for (int i = 0; i < cur.size(); i++) {
                cur[i] = char((cur[i] - 48 + 1) % 3 + 48);
            }
            cout << cur << "\n";
        }
        exit(false);
    }
}

void rec(string cur) {
    // cout << "here\n";
    check();
    if (cur.size() == n) {
        ans.push_back(cur);
        check();
        return;
    }
    rec(cur + "0");
    rec(cur + "1");
    rec(cur + "2");
}

int main() {
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
    cin >> n;
    rec("");
    return 0;
}
