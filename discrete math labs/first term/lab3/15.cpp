/// FUCK YOU, PIECE OF SHIT !!!

#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 35;

int n, k, m;
int c[N][N];
vector<int> ans;

int fact(int x) {
    int s = 1;
    for (int i = 2; i <= x; i++) {
        s *= i;
    }
    return s;
}

/*int C(int n, int k) {
    return fact(n) / fact(k) / fact(n - k);
}*/

void get() {
    int cur = 1;
    while (k > 0) {
        if (!n) {
            return;
        }
        if (m < c[n - 1][k - 1]) {
            ans.push_back(cur);
            k--;
        } else {
            m -= c[n - 1][k - 1];
        }
        n--; cur++;
    }
    return;
}

signed main() {
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    cin >> n >> k >> m;
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    get();
    for (auto i: ans) {
        cout << i << " ";
    }
    return 0;
}
