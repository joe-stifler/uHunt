/*------------------------------------------------*/
// Uva Problem No: 11975
// Problem Name: Tele-loto
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-18 17:18:33
// Runtime: 0.040s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int caso = 1; caso <= t; caso++) {
        int n, l;
        scanf("%d %d", &n, &l);

        vector<int> bolas(n+1);
        for (int i = 0; i < n; i++) scanf("%d", &bolas[i]);

        int vals[4];
        for (int i = 0; i < 4; i++) scanf("%d", &vals[i]);

        printf("Case %d:\n", caso);
        while(l--) {
            int mat[5][5];
            bool res[5][5];
            map<int, pair<int, int>> ticks;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    scanf("%d", &mat[i][j]);
                    ticks[mat[i][j]] = make_pair(i, j);
                }
            }

            memset(res, false, sizeof res);

            for (int i = 0; i < n && i < 35; i++) {
                if (ticks.find(bolas[i]) != ticks.end())
                    res[ticks[bolas[i]].first][ticks[bolas[i]].second] = true;
            }

            int total = 0;
            if (res[0][0] && res[0][4] && res[4][4] && res[4][0]) total += vals[0];

            memset(res, false, sizeof res);

            for (int i = 0; i < n && i < 40; i++) {
                if (ticks.find(bolas[i]) != ticks.end())
                    res[ticks[bolas[i]].first][ticks[bolas[i]].second] = true;
            }

            bool valid = true;
            for (int i = 0; i < 5 && valid; i++)
                if (res[2][i] == false) valid = false;

            if (valid) total += vals[1];

            memset(res, false, sizeof res);

            for (int i = 0; i < n && i < 45; i++) {
                if (ticks.find(bolas[i]) != ticks.end())
                    res[ticks[bolas[i]].first][ticks[bolas[i]].second] = true;
            }

            valid = true;
            for (int i = 0; i < 5 && valid; i++)
                if (res[i][i] == false || res[i][4-i] == false) valid = false;

            if (valid) total += vals[2];

            memset(res, false, sizeof res);

            for (int i = 0; i < n; i++) {
                if (ticks.find(bolas[i]) != ticks.end())
                    res[ticks[bolas[i]].first][ticks[bolas[i]].second] = true;
            }

            valid = true;
            for (int i = 0; i < 5 && valid; i++)
                for (int j = 0; j < 5 && valid; j++)
                    if (res[i][j] == false) valid = false;

            if (valid) total += vals[3];

            printf("%d\n", total);
        }

        if (caso + 1 <= t) printf("\n");
    }

    return 0;
}
