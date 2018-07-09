/*------------------------------------------------*/
// Uva Problem No: 10502
// Problem Name: Counting Rectangles
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-10 08:52:42
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cont, n, m;
    char mat[101][101];
    int status[101][101];

    while(true) {
        scanf("%d %d%*c", &n, &m);

        if (n == 0) return 0;

        cont = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%c", &mat[i][j]);
                if (mat[i][j] == '0') status[i][j] = 0;
                else {
                     if (j > 0) status[i][j] = status[i][j-1] + 1;
                     else status[i][j] = (mat[i][j] == '0') ? 0 : 1;
                }

                int menor = status[i][j];
                for (int k = i; k >= 0 && mat[k][j] != '0'; k--) {
                    menor = min(menor, status[k][j]);
                    cont += menor;
                }
            }

            scanf("%*c");
        }

        printf("%d\n", cont);
    }
}
