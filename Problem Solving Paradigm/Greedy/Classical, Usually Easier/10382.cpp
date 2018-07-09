/*------------------------------------------------*/
// Uva Problem No: 10382
// Problem Name: Watering Grass
// Type: Classical, Usually Easier (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-09 07:48:14
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct rect {
    double l, r;
    rect() {}
    rect(double _l, double _r) {
        l = _l;
        r = _r;
    }

    bool operator <(const rect other) const {
        return l < other.l || (l == other.l && r < other.r);
    }
};

int main() {
    int n;
    double M, w;

    while(scanf("%d %lf %lf", &n, &M, &w) != EOF) {

        w /= 2.0;

        double p, R;
        vector<rect> vals;
        while(n--) {
            scanf("%lf %lf", &p, &R);
            if (R <= w) continue;
            double d = sqrt(R * R - w * w);
            vals.emplace_back(p - d, p + d);
        }

        if (vals.size() == 0) {
            printf("-1\n");
            continue;
        }

        sort(vals.begin(), vals.end());

        int i, atual = 0;

        rect *res = (rect *) malloc(vals.size() * sizeof(rect));
        res[0] = vals[0];

        double fim = vals[0].r;
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

        if (state == false || res[0].l > 0 || res[atual].r < M) printf("-1\n");
        else printf("%d\n", atual + 1);

        free(res);
    }

    return 0;
}
