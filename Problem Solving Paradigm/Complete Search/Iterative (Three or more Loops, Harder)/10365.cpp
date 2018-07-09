/*------------------------------------------------*/
// Uva Problem No: 10365
// Problem Name: Blocks
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-07 03:30:00
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        long area = 10000000000;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                for (int j = 1; j <= n; j++) {
                    if (i % j == 0)
                        area = min(area, (long) 2 * n / j + 2 * j * n / i + 2 * i);
                }
            }
        }

        printf("%ld\n", area);
    }

    return 0;
}
