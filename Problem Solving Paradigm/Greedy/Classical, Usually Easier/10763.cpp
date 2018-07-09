/*------------------------------------------------*/
// Uva Problem No: 10763
// Problem Name: Foreign Exchange
// Type: Classical, Usually Easier (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-09 12:59:48
// Runtime: 0.060s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    int a, b;
    point() {}
    point(int _a, int _b) {
        a = _a;
        b = _b;
    }

    bool operator < (const point &other) const {
        return a < other.a || (a == other.a && b < other.b);
    }
};

int main() {
    int n;
    while(true) {
        scanf("%d", &n);
        if (n == 0) break;

        int a, b;
        unordered_map<int, int> values;
        while(n--) {
            scanf("%d %d", &a, &b);

            if (a < b) {
                values[a]++;
                values[b]++;
            } else {
                values[a]--;
                values[b]--;
            }
        }

        bool state = true;
        for (auto it = values.begin(); it != values.end(); it++) {
            if (it->second != 0) state = false;
        }

        if (!state) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
