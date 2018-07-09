/*------------------------------------------------*/
// Uva Problem No: 10976
// Problem Name: Fractions Again?!
// Type: Iterative (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-04 03:04:09
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long k;

    while(scanf("%ld", &k) != EOF) {
        long y;
        vector<pair<long, long>> res;
        for (long i = k + 1; i < 2 * k + 1; i++)
            if ((k * i) % (i - k) == 0) {
                y = ((k * i) / (i - k));
                res.push_back(make_pair(y, i));
            }

        printf("%d\n", res.size());
        for (auto i = res.begin(); i != res.end(); i++)
            printf("1/%ld = 1/%ld + 1/%ld\n", k, i->first, i->second);
    }

    return 0;
}
