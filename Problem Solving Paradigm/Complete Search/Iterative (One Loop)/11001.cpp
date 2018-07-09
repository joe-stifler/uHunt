/*------------------------------------------------*/
// Uva Problem No: 11001
// Problem Name: Necklace
// Type: Iterative (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-06 20:27:03
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6

int main() {
    while(true) {
        int vT, v0;
        scanf("%d %d", &vT, &v0);

        if (vT == 0 && v0 == 0) return 0;

        int discs = 0;
        double maior = 0, aux;
        bool valid = true;
        for (int i = 1; (double) vT / i > v0; i++) {
            aux = 0.3 * i * sqrt((double) vT / i - v0);
            // printf("aux: %lf, maior: %lf\n", aux, maior);
            if (aux - maior > EPS) {
                discs = i;
                maior = aux;
                valid = true;
            } else if (fabs(aux - maior) < EPS) discs = 0;
        }

        printf("%d\n", discs);
    }
}
