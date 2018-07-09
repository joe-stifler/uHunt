/*------------------------------------------------*/
// Uva Problem No: 10249
// Problem Name: The Grand Dinner
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-16 22:41:21
// Runtime: 0.030s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct v {
    int label, num;
    v(){}
    v(int _l, int _n) {
        label = _l;
        num = _n;
    }

    bool operator <(const v &other) const {
        return num > other.num;
    }
};

int main() {
    while(true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        int num, label = 0;
        vector<v> vals;
        while(n--) {
            scanf("%d", &num);
            vals.emplace_back(label, num);
            label++;
        }

        sort(vals.begin(), vals.end());

        int pos = 0;
        vector<int> ms(m);
        while(m--) scanf("%d", &ms[pos++]);

        bool stat = true;
        vector<vector<int>> res(vals.size());
        for (int i = 0; i < vals.size() && stat; i++) {
            for (int j = 0; j < ms.size() && vals[i].num > 0; j++) {
                if (ms[j] > 0) {
                    ms[j] = ms[j] - 1;
                    vals[i].num = vals[i].num - 1;
                    res[vals[i].label].push_back(j+1);
                }
            }

            if (vals[i].num != 0) stat = false;
        }

        if (stat) {
            printf("1\n");
            for (int i = 0; i < res.size(); i++) {
                for (int j = 0; j < res[i].size(); j++) {
                    printf("%d", res[i][j]);
                    if (j + 1 < res[i].size()) printf(" ");
                    else printf("\n");
                }
            }
        } else printf("0\n");
    }
    return 0;
}
