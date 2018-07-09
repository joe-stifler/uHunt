/*------------------------------------------------*/
// Uva Problem No: 12210
// Problem Name: A Match Making Problem
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-17 03:33:20
// Runtime: 0.010s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int test = 1;
    while (true) {
        int b, s;
        scanf("%d %d", &b, &s);
        if (b == 0 || s == 0) break;

        int menor = 1000;
        vector<int> m(b), f(s);
        for (int i = 0; i < b; i++) {
            scanf("%d", &m[i]);
            menor = min(menor, m[i]);
        }
        for (int i = 0; i < s; i++) scanf("%d", &f[i]);

        int total = max(0, b - s);

        printf("Case %d: %d", test, total);

        if (b > s) printf(" %d", menor);
        printf("\n");

        test++;
    }
    return 0;
}
