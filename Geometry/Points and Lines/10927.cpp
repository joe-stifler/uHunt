/*------------------------------------------------*/
// Uva Problem No: 10927
// Problem Name: Bright Lights
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-08-04 06:47:25
// Runtime: 0.090s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-14
using namespace std;

struct point {
    double x, y;
    double r, teta, z;
    point () { r = teta = z = 0; }
    point (double _r, double _teta, double _z, double _x, double _y) {
        r = _r;
        teta = _teta;
        z = _z;

        x = _x;
        y = _y;
    }

    bool operator <(point other) const {
        if (fabs(teta - other.teta) < EPS) return r < other.r;
        else return teta < other.teta;
    }
};

struct point2 {
    double x, y;
    point2 () {}
    point2 (double _x, double _y) {
        x = _x;
        y = _y;
    }

    bool operator <(point2 other) const {
        if (x == other.x) return y < other.y;
        else return x < other.x;
    }
};

int main() {
    int cont = 1;
    while (true) {
        int n;
        scanf ("%d", &n);

        if (n == 0) break;

        vector<point> pts;

        for (int i = 0; i < n; i++) {
            double x, y;
            point p;
            scanf ("%lf %lf %lf", &x, &y, &p.z);

            p.r = sqrt(x*x + y*y);
            p.teta = acos(x / p.r);
            p.x = x;
            p.y = y;

            pts.push_back(p);
        }

        sort(pts.begin(), pts.end());

        point p;
        vector<point2> inv;
        for (int unsigned i = 0; i < pts.size(); i++) {
            if (i > 0) {
                if (fabs(pts[i].teta - pts[i-1].teta) < EPS && pts[i].z <= pts[i-1].z) {
                    inv.push_back(point2(pts[i].x, pts[i].y));
                    pts[i] = pts[i-1];
                }
            }
        }

        printf("Data set %d:\n", cont);

        if (inv.size() > 0) {
            sort(inv.begin(), inv.end());

            printf("Some lights are not visible:\n");

            for (int unsigned i = 0; i < inv.size(); i++) {
                printf("x = %d, y = %d", (int) inv[i].x, (int) inv[i].y);
                if (i + 1 != inv.size()) printf(";\n");
                else printf(".\n");
            }
        } else printf("All the lights are visible.\n");

        cont++;
    }

    return 0;
}
