/*------------------------------------------------*/
// Uva Problem No: 481
// Problem Name: What Goes Up
// Type: Longest Increasing Subsequence (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-06-17 04:40:54
// Runtime: 0.720s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void printRes(int i, int j, int **dpRes, vector<int> &vals1, vector<int> &vals2) {
    if (i == 0 || j == 0) return;
    if (dpRes[i][j] == 0) {
        printRes(i-1, j-1, dpRes, vals1, vals2);
        printf("%d\n", vals1[i-1]);
    } else if (dpRes[i][j] == 1) printRes(i-1, j, dpRes, vals1, vals2);
    else printRes(i, j-1, dpRes, vals1, vals2);
}

int main() {
    long aux;

    vector<long> vals1;

    while(scanf("%ld", &aux) != EOF) vals1.push_back(aux);

    int L = 0;
    vector<long> B(vals1.size()+1, 9999999999);
    vector<vector<long>> C(vals1.size()+1);
    for (int i = 0; i < vals1.size(); i++) {
        if (vals1[i] < B[0]) {
            B[0] = vals1[i];
            C[0] = vector<long>(1);
            C[0][0] = vals1[i];
        } else {
            vector<long>::iterator it = lower_bound(B.begin(), B.end(), vals1[i]);
            int j = it - B.begin() - 1;
            B[j + 1] = vals1[i];
            C[j + 1] = C[j];
            C[j + 1].push_back(vals1[i]);
            if (L < j + 1) L++;
        }
    }

    printf("%d\n-\n", C[L].size());
    for (int i = 0; i < C[L].size(); i++) printf("%ld\n", C[L][i]);

    return 0;
}
