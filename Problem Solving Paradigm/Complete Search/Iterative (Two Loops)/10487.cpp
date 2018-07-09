/*------------------------------------------------*/
// Uva Problem No: 10487
// Problem Name: Closest Sums
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-06 22:20:47
// Runtime: 0.030s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t = 1;
    while(true) {
        long long n;
        scanf("%lld", &n);

        if (n == 0) return 0;

        long long vec[n+1];
        for (int i = 0; i < n; i++) scanf("%lld", &vec[i]);

        printf("Case %lld:\n", t);

        long long m, val, soma = (int) 1e13;
        scanf("%lld", &m);
        while(m--) {
            scanf("%lld", &val);

            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (abs(vec[i] + vec[j] - val) < abs(soma - val)) soma = vec[i] + vec[j];

            printf("Closest sum to %lld is %lld.\n", val, soma);
        }

        t++;
    }
}
