#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-10;

double func(double x) {
    return x * x + sqrt(x);
}

int main() {
    double c; cin >> c;
    double l = 0.0, r = c * 1.0;
    while (r - l > EPS) {
        double m = (l + r) / 2;
        if (func(m) > c) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << fixed << setprecision(6) << l << "\n";
    return 0;
}
