/*------------------------------------------------*/
// Uva Problem No: 11876
// Problem Name: N + NOD (N)
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-30 08:28:44
// Runtime: 0.060s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int vec[1000002];

    memset(vec, 0, sizeof(int) * 1000002);
    vec[0] = 0;
    for (int i = 1; i <= 1000001; i++) {
        for (int j = i; j <= 1000001; j += i) vec[j]++;
    }

    int seq[1000002];
    seq[0] = 1;

    int size = 0;
    for (int i = 1; seq[i-1] <= 1000001; i++) {
        seq[i] = seq[i-1] + vec[seq[i-1]];
        size++;
    }

    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int *pos1 = lower_bound(seq, seq + size, a);
        int *pos2 = upper_bound(seq, seq + size, b);

        printf("Case %d: %d\n", i, pos2 - pos1);
    }


    return 0;
}
