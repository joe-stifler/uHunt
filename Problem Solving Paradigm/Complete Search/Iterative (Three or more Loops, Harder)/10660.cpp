/*------------------------------------------------*/
// Uva Problem No: 10660
// Problem Name: Citizen attention offices
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-09 02:41:06
// Runtime: 0.060s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void getRes(int pos, int vals) {

}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int mat[5][5];
        int i, j, val, areas;

        scanf("%d", &areas);

        memset(mat, 0, sizeof mat);

        while(areas--) {
            scanf("%d %d %d", &i, &j, &val);

            mat[i][j] = val;
        }


        int vec[5];
        long long globalSum = (int) 1e14;
        for (i = 0; i < 25; i++)
            for (j = i + 1; j < 25; j++)
                for (int k = j + 1; k < 25; k++)
                    for (int l = k + 1; l < 25; l++)
                        for (int m = l + 1; m < 25; m++) {
                            long long soma = 0;
                            int mL = m / 5, mC = m % 5;
                            int iL = i / 5, iC = i % 5, jL = j / 5, jC = j % 5;
                            int kL = k / 5, kC = k % 5, lL = l / 5, lC = l % 5;

                            for (int n = 0; n < 5; n++) {
                                for (int p = 0; p < 5; p++) {
                                    soma += mat[n][p] * min(abs(n - iL) + abs(p - iC),
                                                            min(abs(n - jL) + abs(p - jC),
                                                                min (abs(n - kL) + abs(p - kC),
                                                                    min(abs(n - lL) + abs(p - lC),
                                                                        abs(n - mL) + abs(p - mC)))));
                                }
                            }

                            if (soma < globalSum) {
                                globalSum = soma;
                                vec[0] = i;
                                vec[1] = j;
                                vec[2] = k;
                                vec[3] = l;
                                vec[4] = m;
                            }
                        }

        for (i = 0; i < 5; i++) {
            printf("%d", vec[i]);
            if (i != 4) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
