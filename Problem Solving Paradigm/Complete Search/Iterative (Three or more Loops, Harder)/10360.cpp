/*------------------------------------------------*/
// Uva Problem No: 10360
// Problem Name: Rat Attack
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-07 02:51:40
// Runtime: 0.030s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int d, r;
        scanf("%d %d", &d, &r);

        int mat[1026][1026];

        memset(mat, 0, sizeof mat);

        int x, y, rats;
        while(r--) {
            scanf("%d %d %d", &x, &y, &rats);
            for (int i = x - d; i <= x + d; i++) {
                if (i >= 0 && i < 1025) {
                    for (int j = y - d; j <= y + d; j++) {
                        if (j >= 0 && j < 1025) mat[i][j] += rats;
                    }
                }
            }
        }

        int maximo = 0;
        x = y = 0;
        for (int i = 0; i < 1025; i++) {
            for (int j = 0; j < 1025; j++) {
                if (mat[i][j] > maximo) {
                    x = i;
                    y = j;
                    maximo = mat[i][j];
                } else if (mat[i][j] == maximo) {
                    if (x > i || (x == i && y > j)) {
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d %d %d\n", x, y, maximo);
    }

    return 0;
}
