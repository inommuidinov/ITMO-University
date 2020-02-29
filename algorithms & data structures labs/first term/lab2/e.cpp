#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (s[i] >= '0' && s[i] <= '9') {
                st.push(s[i] - 48);
            }
            else {
                int k = st.top(); st.pop();
                int k1 = st.top(); st.pop();
                if (s[i] == '+') st.push(k1 + k);
                if (s[i] == '-') st.push(k1 - k);
                if (s[i] == '*') st.push(k1 * k);
                if (s[i] == '/') st.push(k1 / k);
            }
        }
    }
    cout << st.top();
}
