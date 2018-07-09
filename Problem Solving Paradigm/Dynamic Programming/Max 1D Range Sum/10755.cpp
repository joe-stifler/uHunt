/*------------------------------------------------*/
// Uva Problem No: 10684
// Problem Name: Garbage Heap
// Type: Max 1D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-12 11:40:21
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

long long kadane(long long temp[], int size) {
    long long maiorSoma = temp[0], interSoma = 0;
    for (int i = 0; i < size; i++) {
        interSoma = max(interSoma + temp[i], temp[i]);

        if (interSoma >= 0) maiorSoma = max(maiorSoma, interSoma);
    }

    return maiorSoma;
}

int main() {
    int t;
    scanf("%d", &t);

    long long vec[21][21][21];

    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int k = 0; k < c; k++) scanf("%lld", &vec[i][j][k]);

        long long maiorSoma = vec[0][0][0], temp[21][21], temp2[21];

        for (int left = 0; left < b; left++) {
            for (int linhaCima = 0; linhaCima < a; linhaCima++) {
                memset(temp, 0, sizeof(temp));

                for (int right = left; right < b; right++) {
                    memset(temp2, 0, sizeof(temp2));

                    for (int linhaBaixo = linhaCima; linhaBaixo < a; linhaBaixo++) {
                        for (int k = 0; k < c; k++) {
                            temp[linhaBaixo][k] += vec[linhaBaixo][right][k]; // armazena o somatorio da ith linha, kth altura
                            temp2[k] += temp[linhaBaixo][k]; // armazena a area (acumulada das iteracoes anteriores) da kth altura
                        }

                        /**
                         * Calcula a altura inicial e a altura final (kadane) das areas que somadas resultam
                         * no maior volume possivel. Area esta composta pelos valores das linhas no range
                         * [linhaCima, linhaBaixo].
                         **/
                        maiorSoma = max(maiorSoma, kadane(temp2, c));
                    }
                }
            }
        }

        printf("%lld\n", maiorSoma);
        if (t != 0) printf("\n");
    }

    return 0;
}
