/*------------------------------------------------*/
// Uva Problem No: 10684
// Problem Name: The jackpot
// Type: Max 1D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-11 06:37:59
// Runtime: 0.040s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int vec[10002];

    while (true) {
        int n;
        scanf("%d", &n);

        if (n == 0) return 0;

        for (int i = 0; i < n; i++) scanf("%d", vec + i);

        long maiorSoma = 0, interSoma = 0;
        for (int i = 0; i < n; i++) {
            interSoma = max(interSoma + vec[i], (long) vec[i]);

            if (interSoma >= 0) maiorSoma = max(maiorSoma, interSoma);
        }

        if (maiorSoma <= 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %ld.\n", maiorSoma);
    }
}
