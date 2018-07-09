/*------------------------------------------------*/
// Uva Problem No: 10077
// Problem Name: The Stern-Brocot Number System
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-29 01:22:15
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void search(int a, int b, int la, int lb, int ra, int rb) {
    double q = ((double) a) / ((double) b);
    double m = ((double) la + ra) / ((double) lb + rb);
    if (q < m) {
        printf("L");
        search(a, b, la, lb, la + ra, lb + rb);
    } else if (q > m) {
        printf("R");
        search(a, b, la + ra, lb + rb, ra, rb);
    }
}

int main() {
    while(true) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 1 && b == 1) return 0;

        search(a, b, 0, 1, 1, 0);
        printf("\n");
    }
}
