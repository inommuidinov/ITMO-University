#include<bits/stdc++.h>

#define sys

using namespace std;

const int N = 100100;

int n;
int a[N];
int b[N];

void prev() {
    int pos = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            pos = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[pos] && a[j] < a[i]) {
                    pos = j;
                }
            }
            swap(a[i], a[pos]);
            reverse(a + i + 1, a + n);
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << 0 << " ";
    }
    cout << endl;
    return;
}

void next() {
    int i = n - 2;
    while (i >= 0 && b[i] >= b[i + 1]) {
        i--;
    }
    if (i < 0) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    int pos = i + 1;
    while (pos < n - 1 && b[i] < b[pos + 1]) {
        pos++;
    }
    swap(b[i], b[pos]);
    reverse(b + i + 1, b + n);
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
#ifdef sys
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; b[i] = a[i];
    }
    // prev();
    next();
    return 0;
}
