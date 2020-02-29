#include<bits/stdc++.h>

using namespace std;

const int N = 105;

int n, k;
int a[N][N];
int make[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int cnt = 1; cnt <= n; cnt++) {
        for (int i = 1; i <= k; i++) {
            int post = 0;
            bool ok = false;
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == 1) {
                    post = j;
                }
                if (a[i][j] == 1 && make[j] == 1) {
                    ok = true;
                } else if (a[i][j] == 0 && make[j] == 0) {
                    ok = true;
                }
            }
            if (post > 0 && !ok) {
                make[post] = true;
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        bool ans = false;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 && make[j] == 1) {
                ans = true;
            } else if (a[i][j] == 0 && make[j] == 0) {
                ans = true;
            }
        }
        if (ans == false) {
            puts("YES"); return 0;
        }
    }
    puts("NO");
    return 0;
}
