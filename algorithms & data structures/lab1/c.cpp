#include<bits/stdc++.h>

using namespace std;

vector<int> a, c;

void mergee(int l, int r, int m) {
    int i = l, j = m + 1, k = l;
    while (i <= m || j <= r) {
        if (i <= m && (j > r || a[i] <= a[j])) {
            c[k] = a[i];
            i++; k++;
        }
        else if (j <= r && (i > m || a[j] <= a[i])) {
            c[k] = a[j];
            j++; k++;
        }
    }
    for (int i = l; i < k; i++) {
        a[i] = c[i];
    }
    return;
}

void mergesort(int l, int r) {
    if (l != r) {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        mergee(l, r, m);
    }
}

int main() {
    int n;
    cin >> n;
    a.resize(n); c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}