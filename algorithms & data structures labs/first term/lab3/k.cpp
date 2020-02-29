#include<bits/stdc++.h>

using namespace std;

const int N = 19;

int res;
int n, w;
int a[N];
map<int, int> us;
vector<int> ans;
vector<int> pr[1 << N];
pair<int, int> mask[1 << N];

int main() {
    freopen("skyscraper.in", "r", stdin);
    freopen("skyscraper.out", "w", stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                pr[i].push_back(j);
                sum += a[j + 1];
            }
        }
        mask[i] = {sum, i};
    }
    sort(mask + 1, mask + (1 << n));
    for (int i = (1 << n) - 1; i > 0; i--) {
        if (mask[i].first > w || mask[i].second & res) {
            continue;
        }
        ans.push_back(mask[i].second); res |= mask[i].second;
    }
    cout << ans.size() << "\n";
    for (auto i: ans) {
        cout << pr[i].size() << " ";
        for (int j = 0; j < pr[i].size(); j++)  {
            cout << pr[i][j] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
