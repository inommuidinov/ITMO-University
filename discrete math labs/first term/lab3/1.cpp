#include<bits/stdc++.h>

using namespace std;

int n;

void rec(string res) {
    if (res.size() == n) {
        cout << res << "\n";
        return;
    }
    rec(res + "0");
    rec(res + "1");
}

int main() {
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    cin >> n; rec("");
    return 0;
}
