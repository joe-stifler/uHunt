/*------------------------------------------------*/
// Uva Problem No: 12498
// Problem Name: Ant's Shopping Mall
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-18 16:41:34
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int caso = 1; caso <= t; caso++) {
        int c, r;
        scanf("%d %d\n", &r, &c);

        char mat[r+1][c+1];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                scanf("%c", &mat[i][j]);
            scanf("\n");
        }

        int res = -1;

        for (int j = 0; j < c; j++) {
            int total = 0, valid = 1;
            for (int i = 0; i < r; i++) {
                if (mat[i][j] == '1') {
                    int k = j, l = j, tot1 = 0, tot2 = 0;
                    while(k >= 0 && mat[i][k] != '0') k--, tot1++;
                    while(l < c && mat[i][l] != '0') l++, tot2++;

                    if (k < 0 && l >= c) valid = 0;
                    else if (k < 0 && l < c) total += tot2;
                    else if (k >= 0 && l >= c) total += tot1;
                    else total += min(tot1, tot2);
                }
            }

            if (valid == 0) continue;

            if (res == -1) res = total;
            else res = min(res, total);
        }

        printf("Case %d: %d\n", caso, res);
    }

    return 0;
}
