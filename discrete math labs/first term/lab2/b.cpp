#include<bits/stdc++.h>

using namespace std;

string s;
multiset<string> st;

int main() {
    //freopen("bwt.in", "r", stdin);
    //freopen("bwt.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        string cur = "";
        for (int j = 0; j < s.size() - 1; j++) {
            cur += s[j];
        }
        cur = s[s.size() - 1] + cur;
        st.insert(cur);
        s = cur;
    }
    for (auto i: st) {
        cout << i << "\n";
    }
    cout << "\n";
    for (auto i: st) {
        cout << i[i.size() - 1];
    }
    return 0;
}
