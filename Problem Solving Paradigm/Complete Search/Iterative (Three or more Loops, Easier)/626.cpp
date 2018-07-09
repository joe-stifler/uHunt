/*------------------------------------------------*/
// Uva Problem No: 626
// Problem Name: Ecosystem
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-13 23:36:10
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define mp(a, b) make_pair(a, b)

int main() {

    int n;

    while(scanf("%d", &n) != EOF) {
        set<pair<int, pair<int, int>>> res;

        int mat[n+1][n+1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);

        res.clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && i != j) {
                    for (int k = 0; k < n; k++) {
                        if (mat[j][k] == 1 && mat[k][i] == 1 && k != i && k != j) {
                            bool valid = true;
                            int a = i, b = j, c = k, aux;
                            for (int l = 0; l < 4; l++) {
                                if ((a < b && b < c) || (a > b && b > c)) {
                                    valid = false;
                                    res.insert(mp(a, mp(b, c)));
                                }

                                aux = c;
                                c = b;
                                b = a;
                                a = aux;
                            }

                            if (valid) {
                                for (int l = 0; l < 4; l++) {
                                    if ((a < b && b < c) || (a > b && b > c)) {
                                        valid = false;
                                        res.insert(mp(a, mp(b, c)));
                                    }

                                    aux = a;
                                    a = b;
                                    b = c;
                                    c = aux;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (auto i = res.begin(); i != res.end(); i++) printf("%d %d %d\n", i->first + 1, i->second.first + 1, i->second.second + 1);

        printf("total:%d\n\n", res.size());
    }

    return 0;
}
