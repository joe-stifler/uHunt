/*------------------------------------------------*/
// Uva Problem No: 11068
// Problem Name: An Easy Task
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-29 07:11:10
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point
{
    double x, y;
    point() {
        x = y = 0.0;
    }
    point (double _x, double _y) : x(_x), y(_y) {}
};


struct line {
    double a, b, c;

    line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};

/*
   -1: em caso degenerado (ponto e plano)
    0: em caso de retas coincidentes
    1: em caso de retas paralelas
    2: em caso de retas com um ponto único em comum
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

// return true + intersection point if two lines are intersectio
point lineIntersect(line l1, line l2) {
    double a = l1.a, b = l1.b, c = l1.c, d = l2.a, e = l2.b, f = l2.c;
    double x, y;

    if (lineRelation(l1, l2) != 2) return point();

    if (fabs(b) < EPS && fabs(a) > EPS) {  // reta vertical
        x = c / a;
        y = (f - d * x) / e;
    } else if (fabs(a) < EPS && fabs(b) > EPS) { // reta horizontal
        y = c / b;
        x = (f - e * y) /d;
    } else {
        y = (c - a * f / d) / (b - a * e / d);
        x = (f - e * y) / d;
    }

    return point(x, y);
}

int main() {
    int a, b, c;
    int d, e, f;

    while (true) {
        scanf ("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

        line l1(d, e, f), l2(a, b, c);

        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) break;

        if (lineRelation(l1, l2) != 2)
            printf("No fixed point exists.\n");
        else {
            point c = lineIntersect(l1, l2);

            printf("The fixed point is at %.2lf %.2lf.\n", c.x, c.y);
        }

    }

    return 0;
}
