/*------------------------------------------------*/
// Uva Problem No: 154
// Problem Name: Recycling
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-10 01:12:34
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    char c, d;
    char vec[101][5];
    int cont = 0, pos = 0;

    while(true) {
        while(c != 'e') {
            scanf("%c", &c);

            if (c == 'e') break;
            else if (c == '#') return 0;

            scanf("/%c", &d);

            if (d == 'P') pos = 0;
            else if (d == 'G') pos = 1;
            else if (d == 'A') pos = 2;
            else if (d == 'S') pos = 3;
            else if (d == 'N') pos = 4;

            vec[cont][pos] = c;

            for (int i = 1; i <= 4; i++) {
                scanf(",%c/%c", &c, &d);

                if (d == 'P') pos = 0;
                else if (d == 'G') pos = 1;
                else if (d == 'A') pos = 2;
                else if (d == 'S') pos = 3;
                else if (d == 'N') pos = 4;

                vec[cont][pos] = c;
            }

            do scanf("%c", &c);
            while(c != '\n');

            cont++;
        }

        int total, tot[cont];
        for (int i = 0; i < cont; i++) {
            total = 0;
            for (int j = 0; j < cont; j++) {
                if (i == j) continue;
                for (int k = 0; k < 5; k++) {
                    if (vec[i][k] != vec[j][k]) total++;
                }
            }

            tot[i] = total;
        }


        int menor = tot[0], indice = 0;
        for (int i = 0; i < cont; i++) {
            if (menor > tot[i]) {
                menor = tot[i];
                indice = i;
            }
        }

        printf("%d\n", indice + 1);

        do scanf("%c", &c);
        while(c != '\n');

        cont = 0;
    }
}
