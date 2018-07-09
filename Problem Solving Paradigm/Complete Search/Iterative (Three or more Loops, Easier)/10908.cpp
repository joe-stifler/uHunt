/*------------------------------------------------*/
// Uva Problem No: 10908
// Problem Name: Largest Square
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-10 09:45:21
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m, q;
        scanf("%d %d %d%*c", &n, &m, &q);

        char grid[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                scanf("%c", &grid[i][j]);
            scanf("%*c");
        }

        printf("%d %d %d\n", n, m, q);

        int a, b;
        while(q--) {
            scanf("%d %d", &a, &b);
            // a--, b--;

            int k = 0, valid = 1;
            while(valid && b - k >= 0 && b + k < m
                        && a - k >= 0 && a + k < n) {
                for (int i = a - k; i <= a + k && valid == 1; i++) {
                    if (grid[a][b] != grid[i][b-k] ||
                            grid[a][b] != grid[i][b+k]) valid = 0;
                }

                for (int j = b - k; j <= b + k && valid == 1; j++) {
                    if (grid[a][b] != grid[a-k][j] ||
                            grid[a][b] != grid[a+k][j]) valid = 0;
                }

                if (valid == 1) k++;
            }

            printf("%d\n", 2 * k - 1);
        }
    }

    return 0;
}
