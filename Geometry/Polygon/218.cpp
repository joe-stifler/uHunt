/*------------------------------------------------*/
// Uva Problem No:
// Problem Name:
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data:
// Runtime: s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct point {
    double x, y;

    point () : x(0.0), y(0.0) {}

    point (double _x, double _y) : x(_x), y(_y) {}

    bool operator <(point other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator ==(point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

double cross(const point &o, const point &a, const point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> convex_hull(vector<point> &pts) {
    int n = pts.size(), k = 0;
    vector<point> convex(2 * n + 1);

    sort(pts.begin(), pts.end());

    // constroi lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    // constroi upper hull
    for (int i = n - 1, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    convex.resize(k);

    return convex;
}

int main() {
    int n, cont = 1;
    while (true) {
        scanf("%d", &n);

        if (n == 0) break;

        point p;
        vector<point> pts;
        while (n--) {
            scanf("%lf %lf", &p.x, &p.y);
            pts.push_back(p);
        }

        vector<point> convex = convex_hull(pts);

        double perim = 0;
        printf("Region #%d:\n", cont);
        for (int i = convex.size()-1; i >= 0; i--) {
            if (i != convex.size()-1) {
                printf("-");
                perim += sqrt(pow(convex[i].x - convex[i+1].x, 2) + pow(convex[i].y - convex[i+1].y, 2));
            }
            printf("(%.1lf,%.1lf)", convex[i].x, convex[i].y);
        }

        printf("\nPerimeter length = %.2lf\n\n", perim);

        cont++;
    }
    return 0;
}
