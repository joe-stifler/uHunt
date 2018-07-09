/*------------------------------------------------*/
// Uva Problem No: 10242
// Problem Name: Fourth Point !!
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-28 04:38:43
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

    bool operator == (point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }

    bool operator < (point other) const {
        if (fabs(x - other.x) < EPS)
            return y < other.y;
        return x < other.x;
    }

    point& operator +(point const& other) {
        x = x + other.x;
        y = y + other.y;

        return *this;
    }

    point& operator -(point const& other) {
        x = x - other.x;
        y = y - other.y;

        return *this;
    }
};

int main() {
    point p[4];

    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y, &p[3].x, &p[3].y) != EOF) {
        sort(p, p+4);

        point pa, pb, pc;

        if (p[0] == p[1]) {
            pa = p[2] - p[1];
            pb = p[3] - p[1];
            pc = pa + pb;

            pc = pc + p[1];

        } else if (p[1] == p[2]) {
            pa = p[0] - p[1];
            pb = p[3] - p[1];
            pc = pa + pb;

            pc = pc + p[1];
        } else {
            pa = p[0] - p[2];
            pb = p[1] - p[2];
            pc = pa + pb;

            pc = pc + p[2];
        }

        printf("%.3lf %.3lf\n", pc.x, pc.y);
    }
}
