/*------------------------------------------------*/
// Uva Problem No: 11236
// Problem Name: Grocery store
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-17 04:06:20
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct st {
    int a, b, c, d;
    st(int _a, int _b, int _c, int _d) : a(_a), b(_b), c(_c), d(_d) {}
};

int main() {
    vector<st> res;
    long total4 = (long) 2 * 1e9;
    long total3 = (long) 2 * 1e7;
    long total2 = (long) 2 * 1e5;
    long total1 = (long) 2 * 1e3;
    for (long i = 1; i <= total1; i++) {
        for (long j = i; j <= 2000 && (i + j) <= 2000 && (i * j) <= total2; j++) {
            for (long k = j; k <= 2000 && (i + j + k) <= 2000 && (i * j * k) <= total3; k++) {
                for (long l = k; l <= 2000 && (i + j + k + l) <= 2000 && (i * j * k * l) <= total4; l++) {
                    if ((i + j + k + l) * 1000000 == (i * j * k * l)) {
                        res.push_back(st(i, j, k, l));
                    }
                }
            }
        }
    }

    for (int i = 0; i < (int) res.size(); i++) {
        printf("%.2lf %.2lf %.2lf %.2lf\n", (double) res[i].a / 100, (double) res[i].b / 100, (double) res[i].c / 100, (double) res[i].d / 100);
    }

    return 0;
}
