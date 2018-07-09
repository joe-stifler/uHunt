/*------------------------------------------------*/
// Uva Problem No: 10662
// Problem Name: The Wedding
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-14 11:57:19
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, r, h;

    while(scanf("%d %d %d", &t, &r, &h) != EOF) {
        int tVec[t+1], rVec[r+1], hVec[h+1];
        int incid1[t+1][r+1], incid2[r+1][h+1], incid3[h+1][t+1];

        for (int i = 0; i < t; i++) {
            scanf("%d", &tVec[i]);
            for (int j = 0; j < r; j++) scanf("%d", &incid1[i][j]);
        }

        for (int i = 0; i < r; i++) {
            scanf("%d", &rVec[i]);
            for (int j = 0; j < h; j++) scanf("%d", &incid2[i][j]);
        }

        for (int i = 0; i < h; i++) {
            scanf("%d", &hVec[i]);
            for (int j = 0; j < t; j++) scanf("%d", &incid3[i][j]);
        }

        int resT = -1, resR = -1, resH = -1;
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < r; j++) {
                if (incid1[i][j] == 0) {
                    for (int k = 0; k < h; k++) {
                        if (incid2[j][k] == 0) {
                            if (incid3[k][i] == 0) {
                                if (resR == -1 ||
                                        tVec[resT] + rVec[resR] + hVec[resH] >
                                                    tVec[i] + rVec[j] + hVec[k]) {
                                    resT = i;
                                    resR = j;
                                    resH = k;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (resT == -1) printf("Don't get married!\n");
        else printf("%d %d %d:%d\n", resT, resR, resH, tVec[resT] + rVec[resR] + hVec[resH]);
    }

    return 0;
}
