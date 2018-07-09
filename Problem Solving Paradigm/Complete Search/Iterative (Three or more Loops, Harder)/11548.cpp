/*------------------------------------------------*/
// Uva Problem No: 11548
// Problem Name: Blackboard Bonanza
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-28 06:13:39
// Runtime: 1.760s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        vector<string> *strs = new vector<string>();

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            strs->push_back(str);
        }

        int contMaior = 0;
        for (int i = 1; i < n; i++) {
            int indexI, indexJ;
            for (int z = 0; z < n; z++) {
                if (i == z) continue;
                if ((*strs)[i].size() > (*strs)[z].size()) {
                    indexI = i;
                    indexJ = z;
                } else {
                    indexI = z;
                    indexJ = i;
                }

                for (int j = 0; j < (*strs)[indexI].size(); j++) {
                    int cont1 = 0, cont2 = 0;
                    for (int k = 0; k < (*strs)[indexJ].size() && k + j < (*strs)[indexI].size(); k++) {
                        if ((*strs)[indexI][j + k] == (*strs)[indexJ][k]) {
                            cont1++;
                            contMaior = max(contMaior, cont1);
                        }
                    }

                    for (int k = 0; k < (*strs)[indexJ].size() && j - k >= 0; k++) {
                        if ((*strs)[indexI][j - k] == (*strs)[indexJ][(*strs)[indexJ].size() - k - 1]) {
                            cont2++;
                            contMaior = max(contMaior, cont2);
                        }
                    }
                }
            }
        }

        printf("%d\n", contMaior);
    }

    return 0;
}
