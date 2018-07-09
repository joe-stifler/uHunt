/*------------------------------------------------*/
// Uva Problem No: 11342
// Problem Name: Three-square
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-07 03:47:32
// Runtime: 0.180s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct Par {
    int a, b, c;
    Par() {}
    Par(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    map<int, Par> res;

    int pows[500001];
    for (int i = 0; i <= 50000; i++) pows[i] = pow(i, 2);

    for (int i = 0; pows[i] <= 50000; i++) {
        for (int j = i; pows[i] + pows[j] <= 50000; j++) {
            for (int k = j; pows[i] + pows[j] + pows[k] <= 50000; k++) {
                if (res.find(pows[i] + pows[j] + pows[k]) == res.end())
                    res.insert(make_pair(pows[i] + pows[j] + pows[k], Par(i, j, k)));
            }
        }
    }

    int k;
    while(n--) {
        scanf("%d", &k);
        if (res.find(k) != res.end()) {
            Par p = res[k];
            printf("%d %d %d\n", p.a, p.b, p.c);
        } else printf("-1\n");
    }

    return 0;
}
