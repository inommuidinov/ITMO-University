#include<bits/stdc++.h>

using namespace std;

bool t0(string s) {
    return s[0] != '0';
}

bool t1(string s) {
    return s[s.size() - 1] != '1';
}

bool sd(string s) {
    /// check it !!!
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[s.size() - 1 - i]) {
            return true;
        }
    }
    return false;
}

bool dom(int x, int y, vector<vector<int> > verr) {
    for (int i = 0; i < verr[x].size(); i++) {
        if (verr[x][i] > verr[y][i]) {
            return false;
        }
    }
    return true;
}

bool mon(string s, int sz) {
    int n = (1 << sz);
    vector<vector<int> > verr;
    for (int i = 0; i < n; i++) {
        int tmp = i;
        vector<int> vec;
        while (tmp != 0) {
            vec.push_back(tmp % 2);
            tmp /= 2;
        }
        while (vec.size() < sz) {
            vec.push_back(0);
        }
        reverse(vec.begin(), vec.end());
        verr.push_back(vec);
        vec.clear();
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dom(i, j, verr) && s[i] > s[j]) {
                return true;
            }
        }
    }
    return false;
}

/**
bool dom(int x, int y) {
    while (x != 0) {
        if ((x & 1) > (y & 1)) {
            return false;
        }
        x /= 2; y /= 2;
    }
    return true;
}

bool mon(string s, int sz) {
    for (int i = 0; i < (1 << sz); i++) {
        for (int j = i + 1; j < (1 << sz); j++) {
            if (dom(i, j) && s[i] > s[j]) {
                return true;
            }
        }
    }
    return false;
}
*/

bool lin(string s, int x) {
    vector<int> cur;
    for (auto i: s) {
        cur.push_back(i - '0');
    }
    int sz = cur.size();
    for (int i = 1; i < (1 << x); i++) {
        for (int j = 0; j < sz - 1; j++) {
            cur[j] = (cur[j] ^ cur[j + 1]);
        }
        sz--;
        int tmp = i, cnt = 0;
        while (tmp != 0) {
            cnt += (tmp % 2); tmp /= 2;
        }
        if (cur[0] == 1 && cnt != 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int n; cin >> n;
    int ans[6];
    for (int i = 0; i < 6; i++) {
        ans[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        string s; cin >> s;
        if (!ans[1]) {
            ans[1] = t0(s);
        }
        if (!ans[2]) {
            ans[2] = t1(s);
        }
        if (!ans[3]) {
            ans[3] = sd(s);
        }
        if (!ans[4]) {
            ans[4] = mon(s, x);
        }
        if (!ans[5]) {
            ans[5] = lin(s, x);
        }
    }
    for (int i = 1; i <= 5; i++) {
        if (!ans[i]) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
    return 0;
}
