/*------------------------------------------------*/
// Uva Problem No: 102
// Problem Name: Ecological Bin Packing
// Type: Iterative (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-03 11:57:44
// Runtime: 0.010s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int vec[9];
    while(scanf("%d %d %d", &vec[0], &vec[1], &vec[2]) != EOF) {
        for (int i = 3; i < 9; i++) scanf("%d", &vec[i]);

        int bins[6];
        memset(bins, 0, sizeof bins);

        // brown clear green
        for (int i = 0; i < 9; i++) {
            if (i != 0 && i != 5 && i != 7) bins[0] += vec[i];
        }

        // brown, green, clear
        for (int i = 0; i < 9; i++) {
            if (i != 0 && i != 4 && i != 8) bins[1] += vec[i];
        }

        // clear brown green
        for (int i = 0; i < 9; i++) {
            if (i != 2 && i != 3 && i != 7) bins[2] += vec[i];
        }

        // clear green brown
        for (int i = 0; i < 9; i++) {
            if (i != 2 && i != 4 && i != 6) bins[3] += vec[i];
        }

        // green brown clear
        for (int i = 0; i < 9; i++) {
            if (i != 1 && i != 3 && i != 8) bins[4] += vec[i];
        }

        // green clear brown
        for (int i = 0; i < 9; i++) {
            if (i != 1 && i != 5 && i != 6) bins[5] += vec[i];
        }

        int indice = 0;
        for (int i = 1; i < 6; i++) {
            if (bins[i] < bins[indice]) indice = i;
        }

        char str[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
        printf("%s %d\n", str[indice], bins[indice]);

    }


    return 0;
}
