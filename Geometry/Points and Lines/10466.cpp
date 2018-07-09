/*------------------------------------------------*/
// Uva Problem No: 10466
// Problem Name: How Far?
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-31 15:51:37
// Runtime: 0.010s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;

struct point {
    double r, w;

    point () {
        r = w = 0.0;
    }

    point (double _r, double _w) : r(_r), w(_w) {}
};

double dist(double x1, double y1, double x2, double y2) {
    return hypot(x1 - x2, y1 - y2);
}

int main() {
    double n, t;
    while (scanf("%lf %lf", &n, &t) != EOF) {
        double r, tr;
        vector<point> pts;
        while (n--) {
            scanf ("%lf %lf", &r, &tr);
            pts.push_back(point(r, 2*PI/tr));
        }

        double x = 0.0, y = 0.0;
        double x1 = 0.0, y1 = 0.0;
        // (cos(wt), sin(wt))
        for (int unsigned i = 0; i < pts.size(); i++) {
            double x2 = pts[i].r * cos(pts[i].w * t) + x1, y2 = pts[i].r * sin(pts[i].w * t) + y1;
            printf("%.4lf", dist(x, y, x2, y2));
            x1 = x2;
            y1 = y2;
            if (i+1 != pts.size()) printf (" ");
        }
        printf("\n");
    }
}
