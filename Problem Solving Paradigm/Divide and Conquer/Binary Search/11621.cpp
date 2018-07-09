/*------------------------------------------------*/
// Uva Problem No: 11621
// Problem Name: Small Factors
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-31 09:44:33
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long> vec;
    for (int i = 0; i < 33; i++)
        for (int j = 0; j < 33; j++) vec.push_back(pow(2, i) * pow(3, j));

    sort(vec.begin(), vec.end());

    while(true) {
        int m;
        scanf("%d", &m);
        if (m == 0) return 0;

        vector<long>::iterator it = lower_bound(vec.begin(), vec.end(), m);
        printf("%ld\n", *it);
    }
}
