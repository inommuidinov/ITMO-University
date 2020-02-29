#include<bits/stdc++.h>

#define fi first
#define se second
#define rank rank228

using namespace std;

const int N = 300300;

int n;
int sum;
int cnt[N];
int rank[N];
int parent[N];

void make_set(int n) {
    for (int i = 1; i <= n; i++) {
        rank[i] = 0; parent[i] = i; cnt[i] = 0;
    }
    return;
}

int find_set(int x) {
    if (parent[x] == x) {
        sum = 0;
        return x;
    } else {
        auto cur = find_set(parent[x]);
        cnt[x] += sum; parent[x] = cur;
        sum = cnt[x];
        return parent[x];
    }
}

void union_sets(int a, int b) {
    a = find_set(a); b = find_set(b);
    /// cout << a << " " << b << "\n";
    if (a != b) {
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        cnt[b] -= cnt[a];
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

void add(int x, int val) {
    x = find_set(x); cnt[x] += val;
}

int main() {
    int n, m;
    cin >> n >> m;
    make_set(n);
    while (m--) {
        string s; cin >> s;
        if (s == "add") {
            int x, y;
            cin >> x >> y;
            add(x, y);
        }
        else if (s == "join") {
            int x, y; cin >> x >> y;
            union_sets(x, y);
        }
        else {
            int x; cin >> x;
            int y = find_set(x);
            if (y == x) {
                cout << cnt[x] << "\n";
            } else {
                /// cout << y << " " << x << "\n";
                cout << cnt[y] + cnt[x] << "\n";
            }
        }
        /**
        for (int i = 1; i <= n; i++) {
            cout << i << " " << parent[i] << " " << cnt[i] << "\n";
        }
        cout << endl;
        **/
    }
    return 0;
}
