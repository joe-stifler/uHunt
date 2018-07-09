/*------------------------------------------------*/
// Uva Problem No: 10002
// Problem Name: Center of Masses
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-08 13:34:41
// Runtime: 0.050s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-12

struct point {
    double x, y;

    point () { x = y = 0.0; }
    point (double _x, double _y) : x(_x), y(_y) {}

    bool operator <(point other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator ==(point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double cross2(const point &o, const point &a, const point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> convex_hull(vector<point> &pts) {
    int n = pts.size(), k = 0;
    vector<point> convex(2 * n + 1);

    sort(pts.begin(), pts.end());

    // constroi lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross2(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    // constroi upper hull
    for (int i = n - 1, t = k + 1; i >= 0; i--) {
        while (k >= t && cross2(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    convex.resize(k);

    return convex;
}

int main() {
    int n;

    while (true) {
        scanf("%d", &n);

        if (n < 3) break;

        double x, y;
        vector<point> poli;
        while (n--) {
            scanf("%lf %lf", &x, &y);
            poli.push_back(point(x, y));
        }

        poli.push_back(poli[0]);

        poli = convex_hull(poli);

        double cx = 0, cy = 0, area = 0;
        for (int j = 0; j < poli.size() - 1; j++) {
            cx += (poli[j].x + poli[j + 1].x) * (poli[j].x * poli[j + 1].y - poli[j + 1].x * poli[j].y);
            cy += (poli[j].y + poli[j + 1].y) * (poli[j].x * poli[j + 1].y - poli[j + 1].x * poli[j].y);
            area += (poli[j].x * poli[j + 1].y - poli[j + 1].x * poli[j].y);
        }

        printf("%.3lf %.3lf\n", cx / (3.0 * area), cy / (3.0 * area));
    }

    return 0;
}
