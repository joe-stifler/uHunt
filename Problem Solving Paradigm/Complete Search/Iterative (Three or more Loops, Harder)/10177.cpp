/*------------------------------------------------*/
// Uva Problem No: 10177
// Problem Name: (2/3/4)-D Sqr/Rects/Cubes/Boxes?
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-07 01:13:30
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        long long tG = pow(n * (n + 1) / 2, 2), tC = pow(n * (n + 1) / 2, 3), tH = pow(n * (n + 1) / 2, 4);
        long long sG = n * (n + 1) * (2 * n + 1) / 6, sC = 0, sH = 0;

        for (int i = 0; i <= n; i++) {
            sC += pow(i, 3);
            sH += pow(i, 4);
        }

        printf("%lld %lld %lld %lld %lld %lld\n", sG, tG - sG, sC, tC - sC, sH, tH - sH);
    }

    return 0;
}
