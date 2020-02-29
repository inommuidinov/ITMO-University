#include<bits/stdc++.h>

using namespace std;

const int N = 100100;

int n;
int cnt;
int us[N];
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            dq.push_back(x); us[x] = dq.size() - 1 + cnt; continue;
        }
        if (t == 2) {
            cnt++;
            dq.pop_front(); continue;
        }
        if (t == 3) {
            dq.pop_back();
        }
        if (t == 4) {
            int x; cin >> x;
            cout << us[x] - cnt << "\n";
        }
        if (t == 5) {
            cout << dq.front() << "\n";
        }
    }
    return 0;
}
