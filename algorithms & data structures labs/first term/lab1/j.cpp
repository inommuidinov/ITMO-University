#include<bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;

double vp, vf, a;

double dis(double x) {
    return sqrt((0 - x) * (0 - x) + (1 - a) * (1 - a)) / vp + sqrt((x - 1) * (x - 1) + (a - 0) * (a - 0)) / vf;
}

int main() {
    cin >> vp >> vf >> a;
    double mn = INT_MAX;
    double ans = 0;
    for (double i = 0; i <= 1; i = i + 0.0001) {
        if (dis(i) < mn) {
            mn = dis(i); ans = i;
        }
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}
