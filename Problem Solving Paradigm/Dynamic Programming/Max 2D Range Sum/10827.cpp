/*------------------------------------------------*/
// Uva Problem No: 10827
// Problem Name: Maximum sum on a torus
// Type: Max 2D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-13 06:02:20
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int kadane(int vec[], int n, int sign) {
    int maior = sign * vec[0], current = 0;

    for (int i = 0; i < n; i++) {
        if (current + sign * vec[i] >= sign * vec[i]) current += sign * vec[i];
        else current = sign * vec[i];

        maior = max(maior, current);
    }

    return maior;
}

int maxCircular(int vec[], int n) {
    int total = accumulate(vec, vec + n, 0);
    int maior = kadane(vec, n, 1);
    int menor = kadane(vec, n, -1);

    int valid = 0;
    for (int i = 0; i < n; i++) if (vec[i] >= 0) valid = 1;

    if (valid) return max(maior, total + menor);
    else return maior;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int vec[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) scanf("%d", &vec[i][j]);

        int maior = vec[0][0], temp[n];
        for (int left = 0; left < n; left++) {
            for (int i = 0; i < n; i++) temp[i] = 0;

            for (int right = left, cont = 0; cont < n; right = (right + 1) % n, cont++) {
                for (int linha = 0; linha < n; linha++) temp[linha] += vec[linha][right];

                maior = max(maior, maxCircular(temp, n));
            }
        }

        printf("%d\n", maior);
    }

    return 0;
}
