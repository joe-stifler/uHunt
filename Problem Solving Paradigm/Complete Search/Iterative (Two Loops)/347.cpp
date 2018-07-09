/*------------------------------------------------*/
// Uva Problem No: 347
// Problem Name: Run
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-07 00:45:14
// Runtime: 0.610s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> res;

    for (int i = 11; i <= 9682415; i++) {
        string str;
        int aux = i;
        while(aux != 0) {
            str.insert(0, 1u, aux % 10 + '0');
            aux /= 10;
        }

        bool vec[10];
        memset(vec, false, sizeof vec);
        vec[0] = true;
        bool valid = true;
        for (int j = 0; j < (int) str.size() && valid; j++) {
            if (vec[str[j] - '0'] == true) valid = false;
            vec[str[j] - '0'] = true;
        }

        if (valid == false) continue;

        memset(vec, false, sizeof vec);
        int pos = 0, cont = 0;
        do {
            vec[pos] = true;
            pos = (pos + str[pos] - '0') % str.size();
            cont++;
        } while(vec[pos] == false);

        if (cont == str.size() && pos == 0) res.push_back(i);
    }

    int t = 1;
    while(true) {
        int n;
        scanf("%d", &n);

        if (n == 0) return 0;

        vector<int>::iterator pos = upper_bound(res.begin(), res.end(), n);

        int ans, dist = pos - res.begin() - 1;
        if (dist >= 0 && res[dist] == n) ans = res[dist];
        else ans = *pos;

        printf("Case %d: %d\n", t, ans);
        t++;
    }
}
