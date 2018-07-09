/*------------------------------------------------*/
// Uva Problem No: 108
// Problem Name: Maximum Sum
// Type: Max 2D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-12 12:16:02
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int kadane(int temp[], int n) {
    int maiorSoma = temp[0], interSoma = 0;
    for (int i = 0; i < n; i++) {
        interSoma = max(temp[i], temp[i] + interSoma);

        maiorSoma = max(maiorSoma, interSoma);
    }

    return maiorSoma;
}

int main() {
    int n;

    while(scanf("%d", &n) != EOF) {
        int vec[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) scanf("%d", &vec[i][j]);

        int maiorSoma = vec[0][0], temp[n];
        for (int left = 0; left < n; left++) {
            memset(temp, 0, sizeof(temp));

            for (int right = left; right < n; right++) {
                for (int linha = 0; linha < n; linha++) temp[linha] += vec[linha][right];

                maiorSoma = max(maiorSoma, kadane(temp, n));
            }
        }

        printf("%d\n", maiorSoma);
    }

    return 0;
}
