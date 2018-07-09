/*------------------------------------------------*/
// Uva Problem No: 471
// Problem Name: Magic Numbers
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-07 01:52:57
// Runtime: 0.090s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long> vals;

    for (long i = 1; i < 1e6; i++) {
        string str = to_string(i);

        bool vec[10];
        memset(vec, false, sizeof vec);

        bool valid = true;
        for (long i = 0; i < (long) str.size(); i++) {
            if (vec[str[i] - '0'] == true) valid = false;
            vec[str[i] - '0'] = true;
        }

        if (valid) vals.push_back(i);
    }


    int t;
    scanf("%d", &t);

    for (int k = 0; k < t; k++) {
        long long num;
        scanf("%lld", &num);

        if (k != 0) printf("\n");

        for (long long i = 0; i < (long long) vals.size() && (long long) vals[i] * num < (long long)1e10; i++) {
            string str = to_string((long long) vals[i] * num);
            bool vec[10];
            memset(vec, false, sizeof vec);

            bool valid = true;
            for (long i = 0; i < (long) str.size(); i++) {
                if (vec[str[i] - '0'] == true) valid = false;
                vec[str[i] - '0'] = true;
            }

            if (valid) printf("%lld / %lld = %lld\n", (long long) vals[i] * num, (long long) vals[i], num);
        }
    }

    return 0;
}
