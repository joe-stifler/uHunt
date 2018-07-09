/*------------------------------------------------*/
// Uva Problem No: 11881
// Problem Name: Internal Rate of Return
// Type: Binary Search the Answer (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-02-09 05:42:33
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-11

double f(double x, vector<int> &vals) {
    double res = 0.0;
    for (int i = 0; i < (int) vals.size(); i++) {
        if (pow(1 + x, i) > EPS)
            res += (double) vals[i] / pow(1 + x, i);
    }

    return res;
}

int main() {
    int t;
    while(true) {
        scanf("%d", &t);
        if (t == 0) return 0;

        bool multSols = true;
        vector<int> vals(t+1);
        for (int i = 0; i <= t; i++) {
            scanf("%d", &vals[i]);
            if (vals[i] != 0) multSols = false;
        }

        if (multSols) printf("Too many\n");
        else {
            double low = -0.999999, high = 1e8;
            double f1 = f(low, vals);
            double f2 = f(high, vals);

            if (f1 >= 0 && f2 <= 0) {
                double mid;
                while(high - low > EPS) {
                    mid = (high + low) / 2.0;
                    if (f(mid, vals) <= 0.0) high = mid;
                    else low = mid;
                }

                printf("%.2lf\n", mid);
            } else printf("No\n");
        }
    }
}
