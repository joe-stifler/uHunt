/*------------------------------------------------*/
// Uva Problem No: 10742
// Problem Name: The New Rule in Euphomia
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-31 09:32:38
// Runtime: 0.040s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sieve_size; i++) {
        if (bs[i]) {
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            primes.push_back((int) i);
        }
    }
}

int main() {
    sieve(10000000);

    // printf("Size: %d\n", primes.size());
    // for (int i = 0; i < 10; i++) printf("%d - ", primes[i]);
    // printf("\n");

    bool ps[1000001];

    memset(ps, false, sizeof(bool) * 1000001);

    int pVals[1000001];
    pVals[0] = 0;
    for (int i = 0; primes[i] <= 1000001; i++) ps[primes[i]] = true;

    for (int i = 1; i < 1000002; i++) {
        pVals[i] = pVals[i-1];
        if (ps[i] == true) pVals[i]++;
    }

    int caso = 1;
    while(true) {
        int val;
        cin >> val;
        if (val == 0) return 0;

        vi::iterator it = lower_bound(primes.begin(), primes.end(), val);
        if (it == primes.end() || *it >= val) it--;

        long long count = 0;
        while(it > primes.begin()) {
            int v = val - *it;
            if (v >= *it) count += pVals[*it - 1];
            else count += pVals[v];

            it--;
        };

        printf("Case %d: %lld\n", caso, count);
        caso++;
    }
}
