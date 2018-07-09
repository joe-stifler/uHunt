/*------------------------------------------------*/
// Uva Problem No: 437
// Problem Name: The Tower of Babylon
// Type: Longest Increasing Subsequence (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-07-09 00:15:40
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y, z;
    point() {}
    point(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
};

int valid(point &p1, point &p2) {
    return (p1.x < p2.x && p1.y < p2.y) || (p1.x < p2.y && p1.y < p2.x);
}

int dfs(int root, vector<vector<int>> &graph, vector<point> &vec, vector<int> &pd) {
    if (pd[root] == -1) {
        pd[root] = vec[root].z;
        for (int i = 0; i < graph[root].size(); i++)
            pd[root] = max(pd[root], dfs(graph[root][i], graph, vec, pd) + vec[root].z);
    }

    return pd[root];
}

int main() {
    int caso = 1;
    while(true) {
        point p1;
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        int x, y, z;
        vector<point> vec;
        while(n--) {
            scanf("%d %d %d", &x, &y, &z);
            vec.emplace_back(x, y, z);
            vec.emplace_back(x, z, y);
            vec.emplace_back(y, z, x);
        }

        vector<vector<int>> graph(vec.size());
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (valid(vec[i], vec[j]))
                    graph[i].push_back(j);
                else if (valid(vec[j], vec[i]))
                    graph[j].push_back(i);
            }
        }

        vector<int> pd(vec.size(), -1);

        int maximo = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (pd[i] == -1) maximo = max(maximo, dfs(i, graph, vec, pd));
        }
        printf("Case %d: maximum height = %d\n", caso++, maximo);
    }
    return 0;
}
