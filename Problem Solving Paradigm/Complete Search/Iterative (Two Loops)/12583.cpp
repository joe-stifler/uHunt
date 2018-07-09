/*------------------------------------------------*/
// Uva Problem No: 12583
// Problem Name: Memory Overflow
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-09 21:15:23
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int l = 0; l < t; l++) {
        int n, k;
        char str[501];

        scanf("%d %d ", &n, &k);

        int cont = 0;
        for (int i = 0; i < n; i++) {
            scanf("%c", str + i);

            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                if (str[j] == str[i]) {
                    cont++;
                    break;
                }
            }
        }

        printf("Case %d: %d\n", l + 1, cont);
    }

    return 0;
}
