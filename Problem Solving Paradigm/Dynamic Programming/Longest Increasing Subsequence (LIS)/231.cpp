/*------------------------------------------------*/
// Uva Problem No: 231
// Problem Name: Testing the CATCHER
// Type: Longest Increasing Subsequence (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-06-17 04:40:28
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int aux;
    int test = 1;
    while(true) {
        scanf("%d", &aux);
        if (aux == -1) break;

        vector<int> vals;
        vals.push_back(aux);
        while(true) {
            scanf("%d", &aux);
            if (aux == -1) break;
            vals.push_back(aux);
        }

        long maior = 0;
        long res[vals.size()];
        for (int i = 0; i < vals.size(); i++) {
            res[i] = 0;
            for (int j = i; j >= 0; j--) {
                if (vals[i] <= vals[j]) {
                    res[i] = max(res[i], res[j] + 1);
                    maior = max(maior, res[i]);
                }
            }
        }

        if (test != 1) printf("\n");

        printf("Test #%d:\n", test);
        printf("  maximum possible interceptions: %ld\n", maior);

        test++;
    }

    return 0;
}
