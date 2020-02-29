#include<bits/stdc++.h>

using namespace std;

string s;
set<char> st;

int main() {
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);
    cin >> s;
    for (auto i: s) {
        st.insert(i);
    }
    string a = "";
    for (auto i: st) {
        a += i;
    }
    for (int i = 0; i < s.size(); i++) {
        int pos = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == s[i]) {
                pos = j; break;
            }
        }
        string tmp = "";
        tmp += s[i];
        for (int j = 0; j < pos; j++) {
            tmp += a[j];
        }
        for (int j = pos + 1; j < a.size(); j++) {
            tmp += a[j];
        }
        a = tmp;
        cout << ++pos << " ";
    }
    return 0;
}
