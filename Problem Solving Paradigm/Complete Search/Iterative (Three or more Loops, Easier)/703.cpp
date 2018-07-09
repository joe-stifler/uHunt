/*------------------------------------------------*/
// Uva Problem No: 703
// Problem Name: Triple Ties: The Organizer's Nightmare
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-14 00:43:22
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
                for (int k = 0; k < n; k++) {
                        if ((mat[i][j] == 0 && mat[j][i] == 0 &&
                            mat[j][k] == 0 && mat[k][j] == 0 &&
                            mat[i][k] == 0 && mat[k][i] == 0 &&
                            res.find(mp(i, mp(j, k))) == res.end() &&
                            res.find(mp(k, mp(i, j))) == res.end() &&
                            res.find(mp(j, mp(k, i))) == res.end() &&
                            res.find(mp(k, mp(j, i))) == res.end() &&
                            res.find(mp(j, mp(i, k))) == res.end() &&
                            res.find(mp(i, mp(k, j))) == res.end())
                            ||
                            (mat[i][j] == 1 && mat[j][k] == 1 && mat[k][i] == 1) &&
                            res.find(mp(i, mp(j, k))) == res.end() &&
                            res.find(mp(k, mp(i, j))) == res.end() &&
                            res.find(mp(j, mp(k, i))) == res.end()) {

                            bool valid = true;
                            int a = i, b = j, c = k, aux;

                            for (int l = 0; l < 4; l++) {
                                if ((a < b && b < c) || (a > b && b > c)) {
                                    valid = false;
                                    res.insert(mp(a, mp(b, c)));
                                    break;
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
                                        break;
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

        printf("%d\n", res.size());
        for (auto i = res.begin(); i != res.end(); i++) printf("%d %d %d\n", i->first + 1, i->second.first + 1, i->second.second + 1);
    }

    return 0;
}
