/*------------------------------------------------*/
// Uva Problem No: 10041
// Problem Name: Vito's Family
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-06 22:08:10
// Runtime: 2.600s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int vec[30002];
        memset(vec, 0, sizeof vec);

        int u;
        while(n--) {
            scanf("%d", &u);
            for (int i = 1; i < 30000; i++)
                if (i != u) vec[i] += abs(i - u);
        }

        int menor = vec[1];
        for (int i = 1; i < 30000; i++) menor = min(menor, vec[i]);

        printf("%d\n", menor);
    }

    return 0;
}
