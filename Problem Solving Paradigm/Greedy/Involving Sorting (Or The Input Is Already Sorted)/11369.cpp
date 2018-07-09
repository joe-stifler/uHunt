/*------------------------------------------------*/
// Uva Problem No: 11369
// Problem Name: Shopaholic
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-10 09:40:55
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> vals(n);
        while(n--) scanf("%d", &vals[n]);
        sort(vals.begin(), vals.end());

        long int total = 0;
        for (int i = vals.size() - 1; i >= 2; i -= 3) total += vals[i - 2];
        printf("%d\n", total);
    }
    return 0;
}
