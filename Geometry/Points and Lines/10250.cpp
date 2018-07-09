/*------------------------------------------------*/
// Uva Problem No: 10250
// Problem Name: The Other Two Trees
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-28 06:05:46
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

    point& operator /(int const& other) {
        x = x / other;
        y = y / other;

        return *this;
    }
};

#define PI acos(-1.0)
double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}

double RAD_to_DEG(double d) {
    return d * 180.0 / PI;
}

// rotate p by theta degrees with relation to origin (0,0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

double dist(point a) {
    return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

int main() {
    point a, b;

    while (scanf ("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y) != EOF) {
        point p = a, q = b;
        point r = (p + q) / 2;

        p = a-r;
        q = b-r;

        p = rotate(p, 90);
        q = rotate(q, 90);

        p = p + r;
        q = q + r;

        printf("%.10lf %.10lf %.10lf %.10lf\n", q.x, q.y, p.x, p.y);
    }

    return 0;
}
