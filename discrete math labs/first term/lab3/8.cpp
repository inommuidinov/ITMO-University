#include<bits/stdc++.h>

using namespace std;

const int N = 20;

int n, k;
int ans[N];

bool next() {
    for (int i = k; i >= 1; i--) {
        if (ans[i] < n - k + i) {
            ans[i]++;
            for (int j = i + 1; j <= k; j++) {
                ans[j] = ans[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("choose.in", "r", stdin);
    //freopen("choose.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        ans[i] = i;
    }
    do {
        for (int i = 1; i <= k; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } while (next());
    return 0;
}
