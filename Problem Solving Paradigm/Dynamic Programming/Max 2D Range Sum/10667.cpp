/*------------------------------------------------*/
// Uva Problem No: 10667
// Problem Name: Largest Block
// Type: Max 2D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-12 15:17:35
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    scanf("%d", &p);

    while(p--) {
        int n;
        scanf("%d", &n);

        bool vec[n][n];

        memset(vec, true, sizeof(vec));

        int b;
        scanf("%d", &b);
        while(b--) {
            int iIni, iFin, jIni, jFin;
            cin >> iIni >> jIni >> iFin >> jFin;

            iIni--, jIni--, iFin--, jFin--;

            for (int i = iIni; i <= iFin; i++)
                for (int j = jIni; j <= jFin; j++) vec[i][j] = false;
        }

        int temp[n][n];
        memset(temp, 0, sizeof(temp));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (vec[i][j]) temp[i][j] = ((i > 0) ? temp[i-1][j] : 0) + 1;
            }

        int maior = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int cont = 0, menor = 30000;
                for (int k = j; k < n; k++) {
                    if (vec[i][k]) {
                        cont++;
                        menor = min(menor, temp[i][k]);

                        maior = max(maior, cont * menor);
                    } else {
                        cont = 0;
                        menor = 30000;
                    }
                }
            }

        printf("%d\n", maior);

    }

    return 0;
}
