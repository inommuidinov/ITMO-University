#include<bits/stdc++.h>

using namespace std;

string s;
map<string, int> us;

int main() {
    freopen("lzw.in", "r", stdin);
    freopen("lzw.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < 26; i++) {
        string cur = "";
        cur += char(i + 97);
        us[cur] = i + 1;
    }
    int p = 27;
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        string cur = t + s[i];
        if (us[cur]) {
            t = cur;
        } else {
            cout << us[t] - 1 << " ";
            us[cur] = p++;
            t = ""; t += s[i];
        }
    }
    cout << us[t] - 1;
    return 0;
}
