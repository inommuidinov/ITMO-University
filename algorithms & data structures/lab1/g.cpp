#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, i, j, l, r, now;
    scanf("%d%d%d", &n, &i, &j);
    x = i < j ? i : j;
    y = i > j ? i : j;
    l = 0; r = (n - 1) * y;
    while (l != r) {
        now = (l + r) / 2;
        j = now / x + now / y;
        if (j < n - 1) l = now + 1;
        else r = now;
    }
    printf("%d", r + x);
    return 0;
}
