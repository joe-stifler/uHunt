/*------------------------------------------------*/
// Uva Problem No: 920
// Problem Name: Sunny Mountains
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-28 03:28:07
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct line {
    double a, b, c;

    line () {
        a = b = c = 0;
    }
};


struct point {
    double x, y;

    point () {
        x = y = 0;
    }

    point(double _x, double _y) : x(_x), y(_y) { }

    bool operator < (point other) const {
        if (x == other.x)
            return y > other.y;
        return x > other.x;
    }

    point& operator= (point const& a) {
        x = a.x;
        y = a.y;

        return *this;
    }
};

// equacao da reta a partir de dois pontos
line pointsToLine(point p1, point p2) {
    line l;
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// return true + intersection point if two lines are intersectio
point areIntersect(line l1, line l2) {
    point p;

    // solve system of two linear algebraic equations with 2 unkowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return p;
}


int main () {
    int n;
    scanf ("%d", &n);

    while (n--) {
        int f;
        vector<point> pts;
        scanf ("%d", &f);

        while (f--) {
            double x, y;

            scanf ("%lf%lf", &x, &y);
            pts.push_back(point(x, y));
        }

        sort(pts.begin(), pts.end());

        int unsigned j = 0;
        double tam = 0;
        point p = pts[0];

        while (j < pts.size()) {
            while (j < pts.size() && p.y >= pts[j].y) j++;

            if (j < pts.size()) {
                line l1 = pointsToLine(p, point(pts[j-1].x, p.y));
                line l2 = pointsToLine(pts[j], pts[j-1]);
                tam += dist(pts[j], areIntersect(l1, l2));

                p = pts[j];
            }

            j++;
        }

        printf ("%.2lf\n", tam);
    }

    return 0;
}
