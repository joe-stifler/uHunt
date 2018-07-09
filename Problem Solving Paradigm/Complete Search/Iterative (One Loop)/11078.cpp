/*------------------------------------------------*/
// Uva Problem No: 11078
// Problem Name: Open Credit System
// Type: Iterative (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-06 20:50:32
// Runtime: 0.050s
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

        int vec[n+1];
        for (int i = 0; i < n; i++) scanf("%d", &vec[i]);

        int maior = -99999999, greater = vec[0];
        for (int i = 1; i < n; i++) {
            maior = max(maior, greater - vec[i]);

            greater = max(greater, vec[i]);
        }

        printf("%d\n", maior);
    }

    return 0;
}
