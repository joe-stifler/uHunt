/*------------------------------------------------*/
// Uva Problem No: 11059
// Problem Name: Maximum Product
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-09 22:04:36
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cont = 1;

    while(scanf("%d", &n) != EOF) {
        int vec[n];
        for (int i = 0; i < n; i++) scanf("%d", vec + i);

        long long res = 0;

        for (int i = 0; i < n; i++) {
            long long prod = vec[i];
            res = max(res, prod);
            for (int j = i + 1; j < n; j++) {
                prod *= vec[j];
                res = max(res, prod);
            }
        }

        printf("Case #%d: The maximum product is %lld.\n\n", cont, res);
        cont++;
    }

    return 0;
}
