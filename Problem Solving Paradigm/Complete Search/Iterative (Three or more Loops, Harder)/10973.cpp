/*------------------------------------------------*/
// Uva Problem No: 10973
// Problem Name: Triangle Counting
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-15 10:55:23
// Runtime: 0.930s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        bool mat[n+1][n+1];
        int weights[n+1][n+1];
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                mat[i][j] = false;
                weights[i][j] = 0;
            }

        while(m--) {
            int u, v;
            scanf("%d %d", &u, &v);

            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
            mat[u-1][v-1] = mat[v-1][u-1] = true;
            weights[u-1][v-1] = weights[v-1][u-1] = 2;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            int a = i;
            for (int j = 0; j < graph[a].size(); j++) {
                int b = graph[a][j];
                if (weights[a][b] > 0) {
                    weights[a][b] = 0;
                    weights[b][a] = 0;
                    for (int k = 0; k < graph[b].size(); k++) {
                        int c = graph[b][k];
                        if (c == b || c == a) continue;
                        if (weights[b][c] > 0) {
                            if (mat[a][c] == true && weights[a][c] > 0) {
                                count++;

                                weights[b][c]--;
                                weights[c][b]--;

                                weights[a][c]--;
                                weights[c][a]--;
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
