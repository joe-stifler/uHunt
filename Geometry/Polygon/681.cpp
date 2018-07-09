/*------------------------------------------------*/
// Uva Problem No: 681
// Problem Name: Convex Hull Finding
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-13 13:59:23
// Runtime: 0.030s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator <(point &other) const {
        return y < other.y || (y == other.y && x < other.x);
    }
};

double cross(point o, point a, point b) {
    point oa(a.x - o.x, a.y - o.y), ob(b.x - o.x, b.y - o.y);
    return oa.x * ob.y - ob.x * oa.y;
}

vector<point> convexHull(vector<point> pts) {
    int k = 0;
    vector<point> convex(2 * pts.size() + 1);

    sort(pts.begin(), pts.end());

    for (int i = 0; i < pts.size(); i++) {
        while (k >= 2 && cross(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    for (int i = pts.size() - 1, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    convex.resize(k);

    return convex;
}

int main() {
    int k;
    scanf("%d", &k);

    printf("%d\n", k);

    while (k--) {
        int n;
        scanf("%d", &n);

        double x, y;
        vector<point> pts;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            pts.push_back(point(x, y));
        }


        pts = convexHull(pts);

        printf("%d\n", pts.size());
        for (int i = 0; i < pts.size(); i++)
            printf("%d %d\n", (int)pts[i].x, (int)pts[i].y);

        if (k != 0) {
            scanf("%ld", &x);
            printf("-1\n");
        }
    }

    return 0;
}
