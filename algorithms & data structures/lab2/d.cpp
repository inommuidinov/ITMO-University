#include<bits/stdc++.h>

using namespace std;

deque<int> dq, q;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '+') {
            int x; cin >> x;
            dq.push_back(x);
        } else if (c == '*') {
            int x; cin >> x;
            dq.push_front(x);
        } else {
            cout << q.front() << "\n"; q.pop_front();
        }
        /// cout << "div " << dq.size() << " " << q.size() << "\n";
        while (!dq.empty() && dq.size() > q.size()) {
            q.push_back(dq.front()); dq.pop_front();
        }
    }
    return 0;


}
