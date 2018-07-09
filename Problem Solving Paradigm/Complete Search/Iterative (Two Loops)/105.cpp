/*------------------------------------------------*/
// Uva Problem No: 105
// Problem Name: The Skyline Problem
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-06 21:42:23
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int vec[10005];

    memset(vec, 0, sizeof vec);

    int l, h, r, xmin = 10005, xmax = -1;
    while(scanf("%d %d %d", &l, &h, &r) != EOF) {
        xmin = min(xmin, min(l, r));
        xmax = max(xmax, max(l, r));

        for (int i = min(l, r); i < max(l, r); i++) vec[i] = max(vec[i], h);
    }

    printf("%d ", xmin);
    for (int i = xmin + 1, cont = 1; i <= xmax; i++, cont++) {
        if (vec[i] != vec[i-1])
            printf("%d %d ", vec[i-1], i);
    }

    printf("0\n");

    return 0;
}
