/*------------------------------------------------*/
// Uva Problem No: 957
// Problem Name: Popes
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-29 03:10:13
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int y, p;

    while(scanf("%d %d", &y, &p) != EOF) {
        int popes[p + 1], endPope[p + 1];
        bool visit[p + 1];

        memset(visit, false, sizeof(sizeof(bool) * (p + 1)));


        for (int i = 0; i < p; i++) {
            scanf("%d", &popes[i]);
            if (i != 0) endPope[i-1] = popes[i] - 1;
        }

        int pA, pB, popesNum = -1;
        for (int i = 0; i < p; i++) {
            int *pos = upper_bound(popes + i + 1, popes + p, popes[i] + y - 1);
            pos--;

            int j = pos - popes, period = popes[i] + y - 1;

            if (period >= popes[j] && period <= endPope[j]) {
                if (j - i + 1 > popesNum) {
                    pA = popes[i];
                    pB = *pos;

                    popesNum = j - i + 1;
                }
            }
        }

        printf("%d %d %d\n", popesNum, pA, pB);
    }

    return 0;
}
