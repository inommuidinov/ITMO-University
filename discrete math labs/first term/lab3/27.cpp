#include<bits/stdc++.h>

using namespace std;

string s;

void get() {
    int open = 0, close = 0, pos = -1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') {
            open++;
            if (close > open) {
                pos = i; break;
            }
        }
        else {
            close++;
        }
    }
    if (pos == -1) {
        s = "-"; return;
    }
    // cout << pos << "\n";
    s[pos++] = ')';
    for (int i = 0; i < open; i++) {
        s[pos++] = '(';
    }
    for (int i = 0; i < close; i++) {
        s[pos++] = ')';
    }
    return;
}

int main() {
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    cin >> s; get(); cout << s;
    return 0;
}
