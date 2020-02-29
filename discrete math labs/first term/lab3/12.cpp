/// FUCK YOU, PIECE OF SHIT!!!

#include<bits/stdc++.h>

using namespace std;

int n, k;
int sum[15];
int cnt[15];
int depth;
bool ok = false;
vector<int> us(15);
vector<int> cur;
vector<int> verr[15];
map<vector<int>, bool> ass;
map<set<vector<int>>, int> was;
set<vector<vector<int> > > dolbayob;

void print() {
    for (int i = 0; i < k; i++) {
        for (auto j: verr[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void rec(int st, int pos, int num) {
    if (pos == cur.size()) {
        print(); return;
    }
    if (num == cur[pos]) {
        st = 1;
        if (cur[pos] == cur[pos + 1]) {
            st = verr[pos][0] + 1;//cur[pos] - 1;
        }
        rec(st, pos + 1, 0);
        return;
    }
    for (int i = st; i <= n; i++) {
        if (!us[i]) {
            us[i] = 1;
            verr[pos].push_back(i);
            /**if (num + 1 == cur[pos]) {
                if (pos == cur.size()) {
                    print(); return;
                }
                if (cur[pos] == cur[pos + 1]) {
                    rec(verr[pos][0] + cur[pos] - 1, pos + 1, 0);
                } else {
                    rec(1, pos + 1, 0);
                }
                return;
            }**/
            rec(i + 1, pos, num + 1);
            us[i] = 0;
            verr[pos].pop_back();
        }
    }
    return;
}

void show(int pos) {
    cur.clear();
    cur.push_back(sum[1]);
    for (int i = 2; i <= pos; i++) {
        cur.push_back(sum[i]);
    }
    if (cur.size() == k) {
        for (int i = 0; i <= n; i++) {
            us[i] = cnt[i] = 0;
            verr[i].clear();
        }
        /**cout << "show with ";
        for (auto i: cur) {
            cout << i << " ";
        }
        cout << endl;
        cout << cur.size() << "\n";**/
        rec(1, 0, 0);
        /// ans.push_back(cur);
    }
    return;
}

void raz(int step, int start, int left) {
    if (start > left) {
        return;
    }
    if (step > 1) {
        sum[step] = left;
        show(step);
    }
    for (int i = start; i <= left; i++) {
        sum[step] = i;
        raz(step + 1, i, left - i);
    }
}

int main() {
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        return 0;
    }
    raz(1, 1, n);
    /*for (auto i: dolbayob) {
        for (auto j: i) {
            for (auto k: j) {
                cout << k << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/
    return 0;
}
