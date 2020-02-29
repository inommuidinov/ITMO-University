#include<bits/stdc++.h>

#define rank rank228

using namespace std;

const int N = 300300;

int n;
int rank[N];
int parent[N];
int sz[N], mn[N], mx[N];

void make_set(int n) {
    for (int i = 1; i <= n; i++) {
        rank[i] = 0; parent[i] = i;
        sz[i] = 1; mn[i] = i; mx[i] = i;
    }
    return;
}

int find_set(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_set(parent[x]);
}

void union_sets(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b]; mn[a] = min(mn[a], mn[b]); mx[a] = max(mx[a], mx[b]);
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    make_set(n);
    string s;
    while (cin >> s) {
        if (s == "union") {
            int x, y; cin >> x >> y;
            union_sets(x, y);
        } else {
            int x; cin >> x;
            int ans = find_set(x);
            cout << mn[ans] << " " << mx[ans] << " " << sz[ans] << "\n";
        }
    }
    return 0;
}
