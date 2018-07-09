/*------------------------------------------------*/
// Uva Problem No: 833
// Problem Name: Water Falls
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-31 15:51:37
// Runtime: 0.010s
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


struct segment {
    point upper, lower;
    bool valid;
    double a;

    segment() {
        valid = false;
    }

    segment(point a, point b) : upper(a), lower(b) { valid = false; }
};

struct line {
    double m, b;
    line () { m = b = 0; }
    line(double _m, double _b) : m(_m), b(_b) {}
};

// Y = m * x + b
line pointsToLine(point p1, point p2) {
    line l;

    if (fabs((p1.x - p2.x)) < EPS)  {
        l.m = 0;
        l.b = p2.x;
    } else {
        l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = p1.y - l.m * p1.x;
    }

    return l;
}

int findNearestSeg(point p, vector<segment> segs) {
    int pos = -1;
    double dist = p.y;

    for (int unsigned i = 0; i < segs.size(); i++) {
        if (min(segs[i].lower.x, segs[i].upper.x) < p.x && p.x < max(segs[i].lower.x, segs[i].upper.x)) {
            line l1 = pointsToLine(segs[i].upper, segs[i].lower);

            if (fabs(l1.m) > EPS && p.y >= (l1.m * p.x + l1.b) && dist > p.y - (l1.m * p.x + l1.b)) { // y = (-a*x-c) / b
                dist = p.y - (l1.m * p.x + l1.b);
                pos = i;
            }
        }
    }

    return pos;
}

int findNext(segment &s, vector<segment> &segs) {
    int pos = findNearestSeg(s.lower, segs);

    s.valid = true;
    if (pos == -1) { // nenhum segmento encontrado
        s.a = s.lower.x;
    } else {
        if (segs[pos].valid == false) {
            s.a = findNext(segs[pos], segs);
        } else {
            s.a = segs[pos].a;
        }
    }

    return s.a;
}

int main() {
    int n;
    scanf ("%d", &n);

    while (n--) {
        int l;
        scanf ("%d", &l);

        vector<segment> segs;
        double x1, y1, x2, y2;
        for (int i = 0; i < l; i++) {
            scanf ("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

            if (y1 > y2) {
                segs.push_back(segment(point(x1, y1), point(x2, y2)));
            } else segs.push_back(segment(point(x2, y2), point(x1, y1)));
        }

        for (int i = 0; i < l; i++) {
            if (segs[i].valid == false) findNext(segs[i], segs);
        }

        int k;
        scanf ("%d", &k);

        for (int j = 0; j < k; j++) {
            scanf ("%lf %lf", &x1, &y1);
            int pos = findNearestSeg(point(x1, y1), segs);

            if (pos == -1)
                printf("%d\n", (int)x1);
            else printf("%d\n", (int)segs[pos].a);
        }

        if (n > 0)
            printf("\n");
    }

    return 0;
}
