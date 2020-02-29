#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    double m[n];
    int v[n], w[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
        m[i] = v[i] * 1.0 / w[i];
    }
    sort(m, m + n);
    
}