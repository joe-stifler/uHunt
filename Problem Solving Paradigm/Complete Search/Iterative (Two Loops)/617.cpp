/*------------------------------------------------*/
// Uva Problem No: 617
// Problem Name: Nonstop Travel
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-09 18:16:51
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6

int main() {
    int cont = 1;
    while(true) {
        int n;
        scanf("%d", &n);

        if (n == -1) return 0;

        double l[n+1];
        int green[n+1], yellow[n+1], red[n+1];

        for (int i = 0; i < n; i++) scanf("%lf %d %d %d", l + i, green + i, yellow + i, red + i);

        int k;
        double t;
        bool res[65], valid;

        memset(res, false, sizeof res);

        int last;
        for (double j = 30; j <= 60; j++) {
            valid = true;
            for (int i = 0; i < n && valid; i++) {
                t = ((double) l[i] / j) * 3600;
                k = ((int)floor(t)) % (green[i] + yellow[i] + red[i]);

                t = fabs(t - ((double) floor(t)));

                if (k + t > (green[i] + yellow[i]) &&
                        k + t < green[i] + yellow[i] + red[i] &&
                            fabs(k + t - (green[i] + yellow[i] + red[i])) > EPS) valid = false;
            }

            if (valid) {
                res[(int) j] = true;
                last = j;
            }
        }

        valid = true;
        printf("Case %d: ", cont);
        for (int i = 30; i <= 60; i++) {
            if (res[i] == true) {
                valid = false;
                printf("%d", i);
                if (res[i+1] == false) {
                    if (last > i) printf(", ");
                    else printf("\n");
                } else {
                    int j = i + 1;
                    while(res[j] == true) j++;
                    j--;
                    printf("-%d", j);
                    if (last > j) printf(", ");
                    else printf("\n");
                    i = j;
                }
            }
        }

        if (valid) printf("No acceptable speeds.\n");

        cont++;
    }
}
