/*------------------------------------------------*/
// Uva Problem No: 10125
// Problem Name: Sumsets
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-07 00:07:25
// Runtime: 1.730s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(true) {
        scanf("%d", &n);

        if (n == 0) return 0;

        long vec[n+1];
        for (int i = 0; i < n; i++) scanf("%ld", &vec[i]);

        map<long, vector<pair<int, int>>> rA, rB;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                rA[vec[i] + vec[j]].push_back(make_pair(i, j));

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                rB[vec[i] - vec[j]].push_back(make_pair(i, j));
                rB[vec[j] - vec[i]].push_back(make_pair(j, i));
            }

        long d = -9999999999;
        bool status = false;
        for (auto it = rA.begin(); it != rA.end(); it++) {
            if (rB[it->first].size() > 0) {
                auto aux = rB.find(it->first);
                for (auto it2 = aux->second.begin(); it2 != aux->second.end(); it2++) {
                    for (auto it3 = it->second.begin(); it3 != it->second.end(); it3++) {
                        if (it2->first != it3->first && it2->first != it3->second &&
                            it2->second != it3->first && it2->second != it3->second) {
                                status = true;
                                d = max(d, vec[it2->first]);
                            }
                    }
                }
            }
        }

        if (status) printf("%ld\n", d);
        else printf("no solution\n");
    }
}
