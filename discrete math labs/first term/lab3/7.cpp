#include<bits/stdc++.h>

using namespace std;

const int N = 10;

int n;
int us[N];
int ans[N];

void print() {
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

void rec(int pos) {
    if (pos == n + 1) {
        print(); return;
    }
    for (int i = 1; i <= n; i++) {
        if (!us[i]) {
            ans[pos] = i;
            us[i] = 1;
            rec(pos + 1);
            us[i] = 0;
        }
    }
}

int main() {
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
    cin >> n;
    rec(1);
    return 0;
}
