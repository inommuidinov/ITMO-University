#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, k;
int a[N], b[N];
map<int, int> us;
set<pair<int, int> > st;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        us[a[i]] = true;
        st.insert({a[i], i});
    }
    st.insert({INT_MAX, n + 1});
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        if (us[b[i]]) {
            cout << b[i] << "\n"; continue;
        }
        auto p = *st.lower_bound({b[i], 0});
        int pos = p.second;
        if (pos - 1 == 0) {
            cout << a[pos] << "\n";
        } else {
            if (abs(a[pos] - b[i]) < abs(a[pos - 1] - b[i])) {
                cout << a[pos] << "\n";
            } else {
                cout << a[pos - 1] << "\n";
            }
        }
    }
    return 0;
}
