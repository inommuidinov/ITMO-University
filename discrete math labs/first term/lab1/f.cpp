#include<bits/stdc++.h>

using namespace std;

int n;
vector<bool> ass;
deque<string> ans;

int main() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        string cur; cin >> cur;
        bool res; cin >> res;
        ans.push_back(cur); ass.push_back(res);
    }
    while (ass.size()) {
        vector<bool> tmp;
        cout << ans.front() << " " << ass[0] << "\n";
        ans.pop_front();
        for (int i = 0; i < ass.size() - 1; i++) {
            tmp.push_back(ass[i] ^ ass[i + 1]);
        }
        ass = tmp;
    }
    return 0;
}
