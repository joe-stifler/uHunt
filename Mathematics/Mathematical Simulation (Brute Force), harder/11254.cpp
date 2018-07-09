/*------------------------------------------------*/
// Uva Problem No: 11254
// Problem Name: Consecutive Integers
// Type: Mathematical Simulation (Brute Force), harder  (Mathematics)
// Autor: Joe Stifler
// Data: 2017-12-02 00:10:42
// Runtime: 0.010s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n;
        scanf("%d", &n);

        if (n == -1) return 0;

        int res1, res2;
        for (int i = (int) sqrt(2 * n); i > 0; i--) {
            // aplicacao direta da formula da PA
            if ((2 * n - i * i + i) % (2 * i) == 0) {
                res1 = (2 * n - i * i + i) / (2 * i);
                res2 = res1 + i - 1;
                break;
            }
        }

        printf("%d = %d + ... + %d\n", n, res1, res2);
    }
}
