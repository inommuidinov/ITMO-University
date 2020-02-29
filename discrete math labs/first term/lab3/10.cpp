#include<bits/stdc++.h>

using namespace std;

int n, sum[50];
vector<vector<string> > ans;

string convert(int x) {
    string res = "";
    while (x != 0) {
        res = char(x % 10 + 48) + res;
        x /= 10;
    }
    return res;
}

bool check(vector<int> verr) {
    for (auto i: verr) {
        if (i == 1) return false;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) return false;
        }
    }
    return true;
}

void show(int pos) {
    vector<string> cur;
    vector<int> curr;
    cur.push_back(convert(sum[1]));
    curr.push_back(sum[1]);
    for (int i = 2; i <= pos; i++) {
        cur.push_back(convert(sum[i]));
        curr.push_back(sum[i]);
    }
    if (check(curr)) ans.push_back(cur);
    return;
}

void rec(int step, int start, int left) {
    if (start > left) {
        return;
    }
    if (step > 1) {
        sum[step] = left;
        show(step);
    }
    for (int i = start; i <= left; i++) {
        sum[step] = i;
        rec(step + 1, i, left - i);
    }
}

int main() {
    //freopen("partition.in", "r", stdin);
    //freopen("partition.out", "w", stdout);
    cin >> n;
    rec(1, 1, n);
    vector<string> cur;
    vector<int> curr;
    cur.push_back(convert(n));
    curr.push_back(n);
    if (check(curr)) ans.push_back(cur);
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++) {
            cout << "+" << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
