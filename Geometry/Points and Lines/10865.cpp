/*------------------------------------------------*/
// Uva Problem No: 10865
// Problem Name: Brownie Points
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-08-02 18:27:55
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int main() {

    while (true) {
        int n;
        scanf ("%d", &n);

        if (n == 0) break;

        long long x, y, a, b;
        vector<pair<long, long> > pts;
        for (int i = 0; i < n; i++) {
            scanf ("%lld %lld", &a, &b);

            if ((n-1) / 2 == i) {
                x = a; y = b;
            } else
                pts.push_back(make_pair(a, b));
        }

        long long stan = 0, ollie = 0;

        for (int i = 0; i < n-1; i++) {
            if (pts[i].first > x) {
                if (pts[i].second > y) stan++;
                else if (pts[i].second < y) ollie++;
            } else if (pts[i].first < x) {
                if (pts[i].second > y) ollie++;
                else if (pts[i].second < y) stan++;
            }
        }

        printf("%lld %lld\n", stan, ollie);
    }
    return 0;
}
