/*------------------------------------------------*/
// Uva Problem No: 10020
// Problem Name: Minimal coverage
// Type: Classical, Usually Easier (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-09 07:17:32
// Runtime: 0.030s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct rect {
    int l, r;
    int index;
    bool stat;

    rect() {}

    rect(int _l, int _r) {
        l = _l;
        r = _r;
    }

    rect(int _l, int _r, bool _stat, int _index) {
        l = _l;
        r = _r;
        stat = _stat;
        index = _index;
    }

    bool operator <(const rect other) const {
        return l < other.l || (l == other.l && r <= other.r);
    }
};

class myComparator {
public:
    int operator() (const rect &a, const rect &b) {
        return a.l < a.l || (a.l == b.l && a.r >= b.r);
    }
};

int main() {
    int t;
    int l, r;

    int teste = 0;

    scanf("%d", &t);
    while(t--) {
        int M;
        vector<rect> vals;

        scanf("%d", &M);

        while (true) {
            scanf("%d %d", &l, &r);
            if (l == 0 and r == 0) break;
            vals.emplace_back(l, r);
        }

        sort(vals.begin(), vals.end());

        int i, atual = 0;

        vector<rect> res(vals.size());
        res[0] = vals[0];

        int fim = vals[0].r;
        for (i = 1; i < vals.size() && vals[i].l <= 0; i++) {
            if (vals[i].r > fim) {
                res[0] = vals[i];
                fim = vals[i].r;
            }
        }

        bool state = true;

        rect r = res[0];
        fim = res[0].r;
        for (; i < vals.size() && res[atual].r < M && state; i++) {
            while(i < vals.size() && fim >= vals[i].l) {
                if (r.r < vals[i].r) r = vals[i];
                i++;
            }

            if (res[atual].r < r.r) {
                fim = r.r;
                res[++atual] = r;
                if (res[atual-1].r < res[atual].l) state = false;
            }

            if (i < vals.size() && r.r < vals[i].r) r = vals[i];
        }

        if (res[atual].r < M && res[atual].r < r.r) {
            res[++atual] = r;
            if (res[atual-1].r < res[atual].l) state = false;
        }

        if (teste != 0) printf("\n");

        if (state == false || res[0].l > 0 || res[atual].r < M) printf("0\n");
        else {
            printf("%d\n", atual + 1);

            for (i = 0; i <= atual; i++) printf("%d %d\n", res[i].l, res[i].r);
        }

        teste++;
    }
    return 0;
}
