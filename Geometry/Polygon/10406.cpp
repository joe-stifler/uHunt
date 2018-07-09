/*------------------------------------------------*/
// Uva Problem No: 10406
// Problem Name: Cutting tabletops
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-15 21:29:21
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define pi acos(-1)

struct point {
    double x, y;
    point () {}
    point (double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec() {}
    vec(double _x, double _y) : x(_x), y(_y) {}
    vec(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

double vecLeng(vec v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

vec normalize(vec v) {
    return vec(v.x / vecLeng(v), v.y / vecLeng(v));
}

vec scale(vec v, double u) {
    return vec(v.x * u, v.y * u);
}

double dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

double angle(vec a, vec b) {
    return acos(dot(a, b) / sqrt(dot(a ,a) * dot(b, b)));
}

struct line {
    double a, b, c;
    line () { a = b = c = 0; }
    line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};



/*
 * retorna a reta definida pelos pontos p1 e p2,
 * com base na fórmula a * x + b * y + c = 0
 */
 line pointsToLine(point p1, point p2) {
     line l;
     if (fabs(p1.x - p2.x) < EPS) { // reta vertical
         l.a = 1.0;
         l.b = 0.0;
         l.c = -p1.x;
     } else {
         l.a = - (p1.y - p2.y) / (p1.x - p2.x);
         l.b = 1.0;
         l.c = -(l.a * p1.x) - p1.y;
     }

     return l;
}

/*
 * -1: em caso degenerado (ponto ou plano)
 *  0: em caso de retas coincidentes
 *  1: em caso de retas paralelas
 *  2: em caso de retas com um ponto único em comum
 */
int lineRelation(line l1, line l2) {
    double a = l1.a, b = l1.b, c = l1.c, d = l2.a, e = l2.b, f = l2.c;

    // casos degenerados
    if ((fabs(a) < EPS && fabs(b) < EPS) ||
            (fabs(d) < EPS && fabs(e) < EPS))
                return -1;

    if (fabs(b) < EPS) {
        double u = d / a;

        if (fabs(u * b - e) < EPS && fabs(u * c - f) < EPS) return 0;
        else if (fabs(u * b - e) < EPS) return 1;
    } else {
        double u = e / b;

        if (fabs(u * a - d) < EPS && fabs(u * c - f) < EPS) return 0;
        else if (fabs(u * a - d) < EPS) return 1;
    }

    return 2;
}

/*
 * retorna o ponto de interseção de duas retas e point(inf, inf) do contrário.
 */
point lineIntersect(line l1, line l2) {
    double x, y;
    double a = l1.a, b = l1.b, c = l1.c, d = l2.a, e = l2.b, f = l2.c;

    if (fabs(b) < EPS && fabs(a) > EPS) {  // reta vertical
        x = - c / a;
        y = - (f + d * x) / e;
    } else if (fabs(a) < EPS && fabs(b) > EPS) { // reta horizontal
        y = - c / b;
        x = - (f + e * y) /d;
    } else {
        x = (e * c - b * f) / (b * d - e * a);
        y = - (c + a * x) / b;
    }

    return point(x, y);
}

int main() {

    while (true) {
        int n;
        double d;

        scanf("%lf %d", &d, &n);

        if (d == 0 && n == 0) return 0;

        double x, y;
        vector<point> pts;
        while (n--) {
            scanf("%lf %lf", &x, &y);

            pts.push_back(point(x, y));
        }

        vector<point> ptsN;
        for (int i = 0; i < (int) pts.size(); i++) {
            vec a, b;
            if (i == 0) a = vec(pts[0], pts[pts.size()-1]);
            else a = vec(pts[i], pts[i-1]);

            if (i + 1 == (int) pts.size()) b = vec(pts[i], pts[0]);
            else b = vec(pts[i], pts[i+1]);

            a = normalize(a);
            b = normalize(b);

            double u = d / sin(angle(a, b));

            vec dv = scale(b, u);
            vec ev = scale(a, u);

            line al = pointsToLine(point(pts[i].x + dv.x, pts[i].y + dv.y),
                                        point(pts[i].x + dv.x + a.x, pts[i].y + dv.y + a.y));

            line bl = pointsToLine(point(pts[i].x + ev.x, pts[i].y + ev.y),
                                        point(pts[i].x + ev.x + b.x, pts[i].y + ev.y + b.y));

            ptsN.push_back(lineIntersect(al, bl));
        }

        ptsN.push_back(ptsN[0]);

        double area = 0;
        for (int i = 0; i < (int) ptsN.size() - 1; i++)
            area += ptsN[i].x * ptsN[i + 1].y - ptsN[i+1].x * ptsN[i].y;

        printf("%.3lf\n",  fabs(area / 2.0));
    }

    return 0;
}
