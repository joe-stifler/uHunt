/*------------------------------------------------*/
// Uva Problem No: 441
// Problem Name: Lotto
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-09 21:46:50
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cont = 0;
    while(true) {
        int n;
        scanf("%d", &n);

        if (n == 0) return 0;

        if (cont != 0) printf("\n");
        cont++;

        int vec[n+1];
        for (int i = 0; i < n; i++) scanf("%d", vec + i);

        for (int i = 0; i < n - 5; i++)
            for (int j = i + 1; j < n - 4; j++)
                for (int k = j + 1; k < n - 3; k++)
                    for (int l = k + 1; l < n - 2; l++)
                        for (int m = l + 1; m < n - 1; m++)
                            for (int o = m + 1; o < n - 0; o++)
                                printf("%d %d %d %d %d %d\n", vec[i], vec[j], vec[k], vec[l], vec[m], vec[o]);
    }
}
