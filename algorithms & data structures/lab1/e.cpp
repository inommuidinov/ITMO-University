#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, k;
int a[N];
map<int, int> first, last;

int find_pos_l(int x) {
    int l = 1, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (a[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (a[l] >= x) {
        return l;
    } else {
        return r;
    }
}

int find_pos_r(int x) {
    int l = 1, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (a[mid] > x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (a[r] <= x) {
        return r;
    }
    else {
        return l;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (first[a[i]] == NULL) {
            first[a[i]] = i;
        }
        last[a[i]] = i;
    }
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        if (a[1] > y || a[n] < x) {
            cout << 0 << " "; continue;
        }
        // cout << find_pos_l(x) << " " << find_pos_r(y) << " ";
        //cout << first[a[find_pos_l(x)]] << " " << last[a[find_pos_r(y)]] << "\n";
        cout << last[a[find_pos_r(y)]] - first[a[find_pos_l(x)]] + 1 << " ";
    }
    return 0;
}
