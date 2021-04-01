#include<bits/stdc++.h>

using namespace std;

string s;
bool us[100];
int n, start;
set<char> ans;
vector<pair<int, vector<int>>> verr;

int main() {
    /// freopen("epsilon.in", "r", stdin);
    /// freopen("epsilon.out", "w", stdout);
    char c;
    cin >> n >> c;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        if (s.size() <= 4) {
            us[int(s[0]) - 65] = true;
            continue;
        }
        vector<int> cur;
        for (int i = 5; i < s.size(); i++) {
            cur.push_back(int(s[i]) - 65);
        }
        verr.push_back({int(s[0]) - 65, cur});
    }
    bool flag = false;
    do {
        flag = false;
        for (auto i: verr) {
            bool ok = true;
            if (us[i.first]) continue;
            for (auto j: i.second) {
                if (!us[j]) {
                    ok = false; break;
                }
            }
            if (ok) {
                us[i.first] = true;
                flag = true;
            }
        }
    } while (flag == true);
    for (int i = 0; i < 26; i++) {
        if (us[i]) {
            cout << char(i + 65) << " ";
        }
    }
    return 0;
}
