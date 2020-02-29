#include<bits/stdc++.h>

using namespace std;

int n;

vector<string> ans;
map<string, int> us;

void get(string cur) {
    while (true) {
        string tmp = "";
        for (int i = 1; i < cur.size(); i++) {
            tmp += cur[i];
        }
        if (us.count(tmp + "1") == 0) {
            tmp += "1";
        } else if (us.count(tmp + "0") == 0) {
            tmp += "0";
        } else {
            return;
        }
        ans.push_back(tmp);
        us[tmp] = 1;
        cur = tmp;
    }
}

int main() {
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
    cin >> n;
    string cur = "";
    for (int i = 0; i < n; i++) {
        cur += "0";
    }
    us[cur] = 1;
    ans.push_back(cur);
    get(cur);
    for (auto i: ans) {
        cout << i << "\n";
    }
    return 0;
}
