/*------------------------------------------------*/
// Uva Problem No: 11900
// Problem Name: Boiled Eggs
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-17 03:18:08
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        int n, p, q;
        scanf("%d %d %d", &n, &p, &q);
        vector<int> eggs(n);
        while(n--) scanf("%d", &eggs[n]);

        sort(eggs.begin(), eggs.end());

        int total = 0, peso = 0;
        for (int i = 0; i < eggs.size(); i++) {
            if (total < p && eggs[i] + peso <= q) {
                total++;
                peso += eggs[i];
            } else break;
        }

        printf("Case %d: %d\n", test, total);
    }
    return 0;
}
