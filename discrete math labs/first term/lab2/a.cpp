#include<bits/stdc++.h>

#define int long long

using namespace std;

int n;
multiset<int> st;

signed main() {
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    int ans = 0;
    while (!(st.size() == 1)) {
        int x = *st.begin(); st.erase(st.begin());
        int y = *st.begin(); st.erase(st.begin());
        ans += (x + y);
        st.insert(x + y);
    }
    cout << ans;
    return 0;
}
