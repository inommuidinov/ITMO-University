#include<bits/stdc++.h>

using namespace std;

int ans;

int main() {
    int n; cin >> n;
    stack<int> st;
    int a[10] = {0};
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (st.empty()) {
            a[x]++; st.push(x); continue;
        }
        int cur = st.top();
        if (cur == x) {
            st.push(x); a[x]++; continue;
        }
        else {
            if (a[cur] >= 3) {
                int val = 0;
                while (!st.empty() && st.top() == cur) {
                    a[cur]--; st.pop(); val++;
                }
                if (val < 3) {
                    a[cur] += val;
                    for (int j = 0; j < val; j++) {
                        st.push(cur);
                    }
                } else {
                    ans += val;
                }
            }
            st.push(x); a[x]++;
        }
    }
    int cur = st.top();
    if (a[cur] >= 3) {
        int val = 0;
        while (!st.empty() && st.top() == cur) {
            a[cur]--; st.pop(); val++;
        }
        if (val < 3) {
            for (int j = 0; j < val; j++) {
                st.push(cur);
            }
        } else {
            ans += val;
        }
    }
    cout << ans << "\n";
    return 0;
}
