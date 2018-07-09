/*------------------------------------------------*/
// Uva Problem No: 12192
// Problem Name: Grapevine
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-02-05 08:28:39
// Runtime: 2.220s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    while(true) {
        int n, m;
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) return 0;

        int mat[n+1][m+1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) scanf("%d", &mat[i][j]);

        vector<int> vec[n+1][m+1];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int pi = i, pj = j;
                do {
                    vec[i][j].push_back(mat[pi][pj]);
                    pi++, pj++;
                } while(pi < n && pj < m);
            }

        int q;
        scanf("%d", &q);

        while(q--) {
            int l, u;
            scanf("%d %d", &l, &u);

            int maximo = 0;
            for (int i = 0; i < n; i++) {
                int *pos = lower_bound(mat[i], mat[i] + m, l);
                if (pos != mat[i] + m) {
                    int j = pos - mat[i];
                    vector<int>::iterator it = upper_bound(vec[i][j].begin(), vec[i][j].end(), u);
                    maximo = max(maximo, (int) distance(vec[i][j].begin(), it));
                }
            }

            printf("%d\n", maximo);
        }

        printf("-\n");
    }
}
