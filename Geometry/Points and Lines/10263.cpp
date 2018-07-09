/*------------------------------------------------*/
// Uva Problem No: 10263
// Problem Name: Railway
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-29 05:59:19
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point {
    double x, y;

    point() { x = y = 0; }
    point(double _x, double _y) : x(_x), y(_y) { }

    bool operator ==(point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale (vec v, double s) {
    return vec(v.x * s, v.y * s);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

double proj(vec a, vec b) {
    return dot(a, b) / sqrt(dot(a, a));
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

double distToLine(point p, point a, point b, point &c) {
  // formula: c = a + u * ab
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));                  // translate a to c
  return dist(p, c); }

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / dot(ab, ab);
    if (u < 0.0) {
        c = point(a.x, a.y);

        return dist(p, a);
    }

    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }

    return distToLine(p, a, b, c);
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

int main() {
    int n;
    double a, b;

    while (scanf ("%lf %lf", &a, &b) != EOF) {
        point m(a, b);
        scanf ("%d", &n);
        vector <point> pts;

        for (int i = 0; i < n+1; i++) {
            double x, y;
            scanf ("%lf %lf", &x, &y);

            pts.push_back(point(x, y));
        }

        point c(1e10,1e10);
        for (int unsigned k = 0; k < pts.size()-1; k++) {
            point aux;
            if(dist(m, c) >  distToLineSegment(m, pts[k], pts[(k+1)%pts.size()], aux)) c = aux;
        }

        printf ("%.4lf\n%.4lf\n", c.x, c.y);
    }

}
