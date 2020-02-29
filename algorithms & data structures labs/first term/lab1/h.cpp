#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define int long long
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);

using namespace std;

const int N = 500;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int TN = 1;

int w, h, n;

void solve() {
    cin >> w >> h >> n;
    int l = min(w, h), r = n * max(w, h);
    while (l < r) {
        int mid = (l + r) / 2;
        if (n <= (mid / w) * (mid / h)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
    return;
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // in; out; // cin >> TN;
    while (TN--) solve();
    return 0;
 }
