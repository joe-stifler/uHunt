/*------------------------------------------------*/
// Uva Problem No: 634
// Problem Name: Polygon
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-08 12:14:10
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-12
#define pi acos(-1)

struct point {
    int x, y;

    point () { x = y = 0.0; }
    point (int _x, int _y) : x(_x), y(_y) {}
};

struct vec {
    int x, y;
    vec(int _x, int _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

double angle(point o, point a, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(dot(oa, oa) * dot(ob, ob)));
}

int cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

bool ccw(point o, point a, point b) {
    return cross(toVec(o, a), toVec(o, b)) > 0;
}

bool inPolygon(point p, vector<point> &pts) {
    if ((int) pts.size() == 0) return false;

    double sum = 0;
    for (int i = 0; i < (int) pts.size() - 1; i++) {
        if (ccw(p, pts[i], pts[i+1])) sum += angle(p, pts[i], pts[i+1]);
        else sum -= angle(p, pts[i], pts[i+1]);
    }

    return fabs(fabs(sum) - 2 * pi) < EPS;
}

int main() {
    int n, t;

    while (true) {
        scanf("%d", &n);

        if (n == 0) break;

        int x, y;
        vector<point> pts;
        while(n--) {
            scanf("%d %d", &x, &y);
            pts.push_back(point(x, y));
        }

        pts.push_back(pts[0]);

        scanf("%d %d", &x, &y);
        if (inPolygon(point(x, y), pts)) printf("T\n");
        else printf("F\n");
    }

    return 0;
}
