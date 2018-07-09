/*------------------------------------------------*/
// Uva Problem No: 386
// Problem Name: Perfect Cubes
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-06 22:45:12
// Runtime: 0.130s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long pows[202];
    for (int i = 0; i <= 200; i++) pows[i] = pow(i, 3);

    for (int i = 2; i <= 200; i++) {
        long powI = pows[i];
        for (int j = 2; j <= 200 && pows[j] <= powI; j++) {
            long powJ = pows[j];
            for (int k = 2; k <= 200 && pows[k] <= powI - powJ; k++) {
                if (k < j) continue;
                long powK = pows[k];
                for (int l = 2; l <= 200 && pows[l] <= powI - powJ - powK; l++) {
                    if (l < k) continue;
                    long powL = pows[l];
                    if (powI == powJ + powK + powL)
                        printf("Cube = %ld, Triple = (%ld,%ld,%ld)\n", i, j, k, l);
                }
            }
        }
    }

    return 0;
}
