/*------------------------------------------------*/
// Uva Problem No: 12190
// Problem Name: Electric Bill
// Type: Binary Search the Answer (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-02-09 04:53:01
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

long long f(long x) {
    long long res = (x <= 100) ? 2 * x : 100 * 2;
    if (x > 100) res += (x <= (long) 1e4) ? (x - 100) * 3 : 9900 * 3;
    if (x > (long) 1e4) res += (x <= (long) 1e6) ? (x - (long) 1e4) * 5 : 990000 * 5;
    if (x > (long) 1e6) res += (x - (long) 1e6) * 7;

    return res;
}

long long f2(long alfa, long x) {
    return f(alfa - x) - f(x);
}

int main() {
    long long a, b;

    while(true) {
        scanf("%lld %lld", &a, &b);

        if (a == 0 && b == 0) return 0;

        long low = 0, high = (long) 5e9;
        long res1;
        do {
            res1 = (long) (high + low) / 2.0;
            if (f(res1) <= a) low = res1;
            else high = res1;
        } while(f(high) != a && f(low) != a);

        res1 = (f(high) == a) ? high : low;

        low = 0; high = (long) 1e9;
        long res2;
        do {
            res2 = (high + low) / 2;
            if (f2(res1, res2) <= b) high = res2;
            else low = res2;
        } while(f2(res1, high) != b && f2(res1, low) != b);

        res2 = (f2(res1, high) == b) ? high : low;

        printf("%lld\n", f(res2));
    }
}
