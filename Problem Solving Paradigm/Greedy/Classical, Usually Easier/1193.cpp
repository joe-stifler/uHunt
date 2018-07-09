/*------------------------------------------------*/
// Uva Problem No: 1193
// Problem Name: Radar Installation
// Type: Classical, Usually Easier (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-09 09:22:36
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    bool operator <(const point &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int main() {
    int caso = 0;

    while(true) {
        int n;
        double d;
        scanf("%d %lf", &n, &d);
        if (n == 0) break;

        double x, y;
        vector<point> pts;
        bool state = true;
        while(n--) {
            scanf("%lf %lf", &x, &y);
            if (y * y > d * d) state = false;
            pts.emplace_back(x, y);
        }

        caso++;

        printf("Case %d: ", caso);

        if (state) {
            sort(pts.begin(), pts.end());

            double dx;
            double xm = pts[0].x, dxm = sqrt(d * d - pts[0].y * pts[0].y);

            int total = 1;
            for (int i = 1; i < pts.size(); i++) {
                x = pts[i].x;
                y = pts[i].y;
                dx = sqrt(d * d - y * y);
                if (x + dx < xm + dxm) {
                    xm = x;
                    dxm = dx;
                } else if ((x - (xm + dxm)) * (x - (xm + dxm)) + y * y > d * d) {
                    total++;
                    xm = x;
                    dxm = dx;
                }
            }

            printf("%d\n", total);
        } else printf("-1\n");
    }

    return 0;
}
