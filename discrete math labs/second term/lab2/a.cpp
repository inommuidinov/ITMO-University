#include<bits/stdc++.h>

using namespace std;

int n, start;
string ok;
vector<vector<vector<int>>> verr(30, vector<vector<int>>(30));

void dfs(int v, int pos, string word) {
    if (pos == word.size()) {
        if (v == 29) {
            ok = "yes";
        }
        return;
    }
    int symbol = int(word[pos]) - 97;
    for (auto i: verr[v][symbol]) {
        dfs(i, pos + 1, word);
    }
}

int main() {
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    char c;
    cin >> n >> c;
    start = int(c) - 65;
    while (n--) {
        char from;
        string direction, to;
        cin >> from >> direction >> to;
        verr[int(from) - 65][int(to[0]) - 97].push_back((to.size() == 1 ? 29 : int(to[1]) - 65));
    }
    cin >> n;
    while (n--) {
        string cur; cin >> cur;
        ok = "no";
        dfs(start, 0, cur);
        cout << ok << "\n";
    }
    return 0;
}
