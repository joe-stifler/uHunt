/*------------------------------------------------*/
// Uva Problem No: 11729
// Problem Name: Commando War
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-10 21:19:23
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct v {
    int a, b;
    v() {}
    v(int _a, int _b) {
        a = _a;
        b = _b;
    }

    bool operator < (const v &other) const {
        return b > other.b;
    }
};

int main() {
    int n;
    int caso = 1;
    while(true) {
        scanf("%d", &n);
        if (n == 0) break;

        v val;
        vector<v> vals;
        while(n--) {
            scanf("%d %d", &val.a, &val.b);
            vals.push_back(val);
        }

        sort(vals.begin(), vals.end());

        long int soma =  0, total = 0;
        for (int i = 0; i < vals.size(); i++) {
            soma += vals[i].a;
            total = max(total, soma + vals[i].b);
        }

        printf("Case %d: %d\n", caso, total);
        caso++;
    }
    return 0;
}
