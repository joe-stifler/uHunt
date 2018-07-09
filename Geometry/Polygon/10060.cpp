/*------------------------------------------------*/
// Uva Problem No: 10060
// Problem Name: A hole to catch a man
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-15 18:58:41
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator ==(point other) const {
        return x == other.x && y == other.y;
    }
};

int main() {
    int n;

    while(true) {
        scanf("%d", &n);

        if (n == 0) return 0;

        double volume = 0;
        while (n--) {
            double x, y, t, area = 0;
            vector<point> pts;

            scanf("%lf", &t);
            while (true) {
                scanf("%lf %lf", &x, &y);

                pts.push_back(point(x, y));
                if (pts.size() > 1 && pts[pts.size() - 1] == pts[0]) break;
            }

            for (int i = 0; i < (int) pts.size() - 1; i++) {
                area += pts[i].x * pts[i+1].y - pts[i + 1].x * pts[i].y;
            }

            volume += fabs(area * t / 2.0);
        }

        double r, T;
        scanf("%lf %lf", &r, &T);
        printf("%d\n", (int) ((double)volume / (pi * r * r * T)));
    }

    return 0;
}
