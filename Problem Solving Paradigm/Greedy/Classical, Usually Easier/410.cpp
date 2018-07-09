/*------------------------------------------------*/
// Uva Problem No: 410
// Problem Name: Station Balance
// Type: Classical, Usually Easier (Greedy)
// Autor: Joe Stifler
// Data: 2018-02-25 02:25:04
// Runtime: 0.010s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, c, cont = 1 ;
    while(scanf("%d %d", &c, &s) != EOF) {
        vector<vector<int>> res(c);
        vector<int> specs(s);
        double media = 0.0;
        for (int i = 0; i < s; i++) {
            scanf("%d", &specs[i]);
            media += (double) specs[i];
        }

        media /= c;

        sort(specs.begin(), specs.end());

        int k = 1, pos = 0;
        for (int i = s-1; i >= 0; i--) {
            if (pos < c)
                res[pos++].push_back(specs[i]);
            else {
                res[pos-k].push_back(specs[i]);
                k++;
            }
        }

        printf("Set #%d\n", cont);

        double imbalance = 0.0;
        for (int i = 0; i < c; i++) {
            printf(" %d:", i);
            double totalMass = 0.0;
            for (int j = res[i].size()-1; j >= 0; j--) {
                printf(" %d", res[i][j]);
                totalMass += (double) res[i][j];
            }
            imbalance += fabs(totalMass - media);
            printf("\n");
        }

        printf("IMBALANCE = %.5lf\n\n", imbalance);


        cont++;
    }

    return 0;
}
