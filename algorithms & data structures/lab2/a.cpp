#include<bits/stdc++.h>

using namespace std;

const int N = 1000001;

struct Stack {
    int sz = 0;
    int data[N];
};

void push(Stack &a, int x) {
    if (a.sz == 0) {
        a.data[a.sz++] = x;
    } else {
        int last = a.sz - 1;
        a.data[a.sz++] = min(x, a.data[last]);
    }
    return;
}

void pop(Stack &a) {
    a.sz--;
    return;
}

int get_min(Stack &a) {
    return a.data[a.sz - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    Stack a;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; push(a, x);
        } else if (t == 2) {
            pop(a);
        } else {
            cout << get_min(a) << "\n";
        }
    }
    return 0;
}
