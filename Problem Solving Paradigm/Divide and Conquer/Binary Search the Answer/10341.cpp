/*------------------------------------------------*/
// Uva Problem No: 10341
// Problem Name: Solve It
// Type: Binary Search the Answer (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-02-09 03:47:55
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-7

double f(int p, int q, int r, int s, int t, int u, double x, double expX, double cosX, double sinX) {
    return p * expX + q * sinX + r * cosX + s * sinX / cosX + t * x * x + u;
}

double fl(int p, int q, int r, int s, int t, double x, double expX, double cosX, double sinX) {
    return -p * expX + q * cosX - r * sinX + s * (1.0 / cosX, 2) * (1.0 / cosX, 2) + 2 * t * x;
}

int main() {
    int p, q, r, s, t, u;
    double fa, fb, x, res, co, si, ex;
    double uE = exp(-1.0), uC = cos(1.0), uS = sin(1.0);

    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        fa = f(p, q, r, s, t, u, 0.0, 1.0, 1.0, 0.0);
        fb = f(p, q, r, s, t, u, 1.0, uE, uC, uS);

        if (fa >= 0.0 && fb <= 0.0) {
            x = 1.0;

            do {
                ex = exp(-x);
                co = cos(x);
                si = sin(x);
                res = f(p, q, r, s, t, u, x, ex, co, si);
                x = x - res / fl(p, q, r, s, t, x, ex, co, si);
            } while(fabs(res) > EPS);

            printf("%.4lf\n", fabs(x));
        } else puts("No solution");
    }

    return 0;
}
