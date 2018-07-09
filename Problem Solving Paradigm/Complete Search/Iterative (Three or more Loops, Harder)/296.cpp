/*------------------------------------------------*/
// Uva Problem No: 296
// Problem Name: Safebreaker
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-14 05:35:27
// Runtime: 0.180s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d%*c", &n);

        int x[n], y[n];
        char tips[n][4];

        for (int i = 0; i < n; i++)
            scanf("%c%c%c%c %d/%d%*c", tips[i], tips[i] + 1, tips[i] + 2, tips[i] + 3, x + i, y + i);

        int res[4];
        bool status = false, indet = false;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++)
                    for (int l = 0; l < 10; l++) {
                        bool valid = true;
                        int vec1[] = {i, j, k, l};
                        for (int m = 0; m < n; m++) {
                            int vec2[] = {tips[m][0] - '0', tips[m][1] - '0', tips[m][2] - '0', tips[m][3] - '0'};
                            bool visited1[] = {false, false, false, false};
                            bool visited2[] = {false, false, false, false};

                            int contEq = 0, contEqdif = 0;
                            for (int z = 0; z < 4; z++) {
                                if (vec1[z] == vec2[z]) {
                                    visited1[z] = visited2[z] = true;
                                    contEq++;
                                }
                            }

                            for (int z = 0; z < 4; z++) {
                                if (visited2[z] == false) {
                                    for (int w = 0; w < 4; w++) {
                                        if (visited1[w] == false && vec1[w] == vec2[z]) {
                                            visited1[w] = visited2[z] = true;
                                            contEqdif++;
                                            break;
                                        }
                                    }
                                }
                            }

                            if (contEq != x[m] || contEqdif != y[m]) valid = false;
                         }

                        if (valid) {
                            if (status == false) {
                                status = true;
                                res[0] = i;
                                res[1] = j;
                                res[2] = k;
                                res[3] = l;
                            } else indet = true;
                        }
                    }

        if (status && !indet) printf("%d%d%d%d\n", res[0], res[1], res[2], res[3]);
        else if (status && indet) printf("indeterminate\n");
        else printf("impossible\n");
    }

    return 0;
}
