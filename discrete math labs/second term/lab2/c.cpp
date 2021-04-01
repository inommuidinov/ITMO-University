#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200;

int n;
int start;
string s;
bool need[N], born[N];
bool nonterm[N], can[N], us[N];
vector<pair<int, vector<int>>> verr, new_verr;

void dfs(int v) {
    us[v] = true;
    for (auto i: new_verr) {
        if (us[i.fi]) {
            for (auto j: i.se) {
                if (j >= 0 && j <= 25 && !us[j]) {
                    dfs(j);
                }
            }
        }
    }
}

int main() {
    /// freopen("useless.in", "r", stdin);
    /// freopen("useless.out", "w", stdout);
    char c;
    cin >> n >> c;
    getline(cin, s);
    start = int(c) - 65;
    nonterm[start] = true;
    while (n--) {
        getline(cin, s);
        nonterm[int(s[0]) - 65] = true;
        if (s.size() <= 4) {
            born[int(s[0]) - 65] = true;
        } else {
            vector<int> cur;
            bool allTerm = true;
            for (int i = 5; i < s.size(); i++) {
                if (int(s[i]) - 65 >= 0 && int(s[i]) - 65 <= 25) {
                    allTerm = false;
                    nonterm[int(s[i]) - 65] = true;
                }
                cur.push_back(int(s[i]) - 65);
            }
            if (allTerm) {
                born[int(s[0]) - 65] = true;
            }
            verr.push_back({int(s[0]) - 65, cur});
        }
    }

    ///==================================================================================
    bool ok = false;
    do {
        ok = false;
        for (auto i: verr) {
            if (!born[i.fi]) {
                int all = 0;
                for (auto j: i.se) {
                    if (j >= 0 && j <= 25 && born[j] || (j >= 32 && j <= 57)) {
                        all++;
                    }
                }
                if (all == i.se.size()) {
                    ok = true;
                    born[i.fi] = true;
                }
            }
        }
    } while (ok == true);
    ///==================================================================================
    ok = false;
    /**do {
        ok = false;
        for (auto i: verr) {
            if (born[i.fi]) {
                bool has = true;
                for (auto j: i.se) {
                    if (j >= 0 && j <= 25 && !born[j]) {
                        has = false;
                    }
                }
                if (has) {
                    new_verr.push_back(i);
                    ok = true;
                }
            }
        }
    } while (ok == true);**/
    for (auto i: verr) {
        bool take = true;
        if (born[i.fi]) {
            for (auto j: i.se) {
                if (j >= 0 && j <= 25 && !born[j]) {
                    take = false;
                }
            }
            if (take) {
                new_verr.push_back(i);
            }
        }
    }
    ///==================================================================================
    dfs(start);

    ///==================================================================================
    verr.clear();
    for (auto i: new_verr) {
        bool take = true;
        if (us[i.fi]) {
            for (auto j: i.se) {
                if (j >= 0 && j <= 25 && !us[j]) {
                    take = false;
                }
            }
            if (take) {
                verr.push_back(i);
            }
        }
    }
    for (auto i: verr) {
        need[i.fi] = true;
        for (auto j: i.se) {
            if (j >= 0 && j <= 25) {
                need[j] = true;
            }
        }
    }
    set<char> ans;
    for (int i = 0; i < 26; i++) {
        if (nonterm[i] && need[i]) {
            continue;
        } else {
            if (nonterm[i]) {
                ans.insert(char(i + 65));
            }
        }
    }
    for (auto i: ans) {
        cout << i << " ";
    }
    return 0;
}
