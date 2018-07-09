/*------------------------------------------------*/
// Uva Problem No: 10730
// Problem Name: Antiarithmetic?
// Type: Iterative (Two Nested Loops) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-07 04:44:44
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    while(true) {
        int n;
        scanf("%d:", &n);

        if (n == 0) return 0;

        int num;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            vec[num] = i;
        }

        bool valid = true;
        for (int i = 0; i < n && valid; i++) {
            for (int j = 0; j < n && valid; j++){
                if (vec[j] > vec[i]) {
                    int k = 2 * j - i;
                    if (k >= n || k < 0) continue;
                    if (vec[k] > vec[j]) valid = false;
                }
            }
        }

        if (!valid) printf("no\n");
        else printf("yes\n");
    }
}
