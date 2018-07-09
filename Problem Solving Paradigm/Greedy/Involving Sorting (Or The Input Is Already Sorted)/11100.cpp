/*------------------------------------------------*/
// Uva Problem No: 11100
// Problem Name: The Trip, 2007
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-16 21:48:30
// Runtime: 0.010s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t = 0;
    while(true) {
        scanf("%d", &n);
        if (n == 0) break;
        vector<int> vals(n);
        map<int, int> total;
        while(n--) {
            scanf("%d", &vals[n]);
            total[vals[n]]++;
        }

        sort(vals.begin(), vals.end());

        int nums = 0;
        for (map<int,int>::iterator it = total.begin(); it != total.end(); it++) nums = max(nums, it->second);

        int pos = 0;
        vector<vector<int>> res(nums);
        for (int i = 0; i < vals.size(); i++) {
            res[pos].push_back(vals[i]);
            pos = (pos + 1) % nums;
        }

        if (t != 0) printf("\n");
        t++;

        printf("%d\n", res.size());
        for (int i = 0; i < res.size(); i++)
            for (int j = 0; j < res[i].size(); j++) {
                printf("%d", res[i][j]);
                if (j + 1 < res[i].size()) printf(" ");
                else printf("\n");
            }
    }
    return 0;
}
