/*------------------------------------------------*/
// Uva Problem No: 725
// Problem Name: Division
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-06 23:15:28
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cont = 0;


    vector<map<int, int>> res(80);
    int vec[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do {
        int num1 = vec[0] * 10000 + vec[1] * 1000 + vec[2] * 100 + vec[3] * 10 + vec[4];
        int num2 = vec[5] * 10000 + vec[6] * 1000 + vec[7] * 100 + vec[8] * 10 + vec[9];

        if (num1 % num2 == 0 && num1 / num2 < 80 && num1 / num2 > 1) res[num1 / num2][num1] = num2;
    } while(next_permutation(vec, vec + 10));

    while(true) {
        int n;
        scanf("%d", &n);

        if (n == 0) return 0;

        if (cont != 0) printf("\n");
        cont++;

        if (res[n].size() == 0) printf("There are no solutions for %d.\n", n);
        else
            for (auto i = res[n].begin(); i != res[n].end(); i++) {
                if (i->first < 10000) printf("0");
                printf("%d / ", i->first);
                if (i->second < 10000) printf("0");
                printf("%d = %d\n", i->second, n);
            }
    }
}
