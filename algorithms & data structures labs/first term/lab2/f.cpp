#include<bits/stdc++.h>

using namespace std;

vector<string> ans;

int main() {
    int n;
    cin >> n;
    int a[n], pos = 0;
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (st.empty()) {
            st.push(x);
            ans.push_back("push");
            continue;
        }
        while (!st.empty() && st.top() < x) {
            a[pos++] = st.top(); st.pop();
            ans.push_back("pop");
        }
        st.push(x);
        ans.push_back("push");
    }
    while (!st.empty()) {
        ans.push_back("pop");
        a[pos++] = st.top(); st.pop();
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "impossible\n"; return 0;
        }
    }
    for (auto i: ans) {
        cout << i << "\n";
    }
    return 0;
}
