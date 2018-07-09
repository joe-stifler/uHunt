/*------------------------------------------------*/
// Uva Problem No: 507
// Problem Name: Jill Rides Again
// Type: Max 1D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-11 06:08:23
// Runtime: 0.100s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int r;
    int i, vec[20002];

    scanf("%d", &r);

    for (int route = 1; route <= r; route++) {
        int s;
        scanf("%d", &s);

        s--;

        for (i = 0; i < s; i++) scanf("%d", &vec[i]);

        int indI = 0, indJ = 0, inicio = 0;
        long maiorSoma = -1, interSoma = 0;
        for (i = 0; i < s; i++) {
            if (interSoma + vec[i] >= vec[i])
                interSoma += vec[i];
            else {
                inicio = i;
                interSoma = vec[i];
            }

            if (interSoma >= 0 && interSoma >= maiorSoma) {
                if (interSoma > maiorSoma ||
                    (interSoma == maiorSoma && i - inicio > indJ - indI)) {
                    indI = inicio;
                    indJ = i;
                }

                maiorSoma = interSoma;
            }
        }

        if(maiorSoma < 0) printf("Route %d has no nice parts\n", route);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", route, indI + 1, indJ + 2);
    }

    return 0;
}
