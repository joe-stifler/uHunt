/*------------------------------------------------*/
// Uva Problem No: 12488
// Problem Name: Start Grid
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-09 20:56:51
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int ini[n+1], end[n+1];

        for (int i = 0; i < n; i++) scanf("%d", ini + i);
        for (int i = 0; i < n; i++) scanf("%d", end + i);

        int j, cont = 0, aux;
        for (int i = 0; i < n; i++) {
            j = 0;
            while(end[i] != ini[j]) j++;
            while(j > i) {
                aux = ini[j];
                ini[j] = ini[j-1];
                ini[j-1] = aux;
                j--;
                cont++;
            }
        }

        printf("%d\n", cont);

    }

    return 0;
}
