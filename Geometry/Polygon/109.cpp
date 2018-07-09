/*------------------------------------------------*/
// Uva Problem No: 109
// Problem Name: SCUD Busters
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-08 12:51:04
// Runtime: 0.010s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-12
#define pi acos(-1)

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

double dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

double angle(point o, point a, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(dot(oa, oa) * dot(ob, ob)));
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

double cross2(const point &o, const point &a, const point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
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
    double x, y;
    int n, t = 0;

    vector<vector<point>> pts(23);

    while (true) {
        scanf("%d", &n);

        if (n == -1) break;

        while(n--) {
            scanf("%lf %lf", &x, &y);
            pts[t].push_back(point(x, y));
        }

        pts[t].push_back(pts[t][0]);

        pts[t] = convex_hull(pts[t]);

        t++;
    }

    bool visit[23];
    memset(visit, false, sizeof visit);

    while (scanf("%lf %lf", &x, &y) != EOF) {
        for (int i = 0; i < t; i++) {
            if (inPolygon(point(x, y), pts[i])) {
                visit[i] = true;
            }
        }
    }

    double area = 0;
    for (int i = 0; i < t; i++) {
        if (visit[i] == true) {
            double tempArea = 0;
            for (int j = 0; j < pts[i].size() - 1; j++) {
                tempArea += (pts[i][j].x * pts[i][j+1].y - pts[i][j+1].x * pts[i][j].y);
            }

            area += fabs(tempArea) / 2.0;
        }
    }

    printf("%.2lf\n", area);

    return 0;
}
