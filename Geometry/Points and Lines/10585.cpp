/*------------------------------------------------*/
// Uva Problem No: 10585
// Problem Name: Center of symmetry
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-08-01 01:15:04
// Runtime: 1.660s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point {
    double x, y;

    point () {x = y = 0.0;}

    point (double _x, double _y) : x(_x), y(_y) {}

    point& operator +(point const& other) {
        x = x + other.x;
        y = y + other.y;

        return *this;
    }

    point& operator /(int const& u) {
        x = x / u;
        y = y / u;

        return *this;
    }

    bool operator ==(point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

bool test(int k, point m, vector<point> pts) {
    for (int unsigned j = 1; j < pts.size(); j++) {
        point d = pts[k];
        d = d + pts[j];
        d = d / 2;

        if (d == m) return true;
    }

    return false;
}

int main() {
    int c;
    scanf ("%d", &c);
    while (c--) {
        int n;
        scanf ("%d", &n);

        vector<point> pts;
        while (n--) {
            double x, y;
            scanf ("%lf %lf", &x, &y);
            pts.push_back(point(x, y));
        }

        bool val1 = false;
        for (int unsigned j = 1; j < pts.size(); j++) {
            point d = pts[0];
            d = d + pts[j];
            d = d / 2;

            bool val2 = true;
            for (int unsigned k = 1; k < pts.size(); k++) {
                if (k != j && test(k, d, pts) == false) {
                    val2 = false;
                    break;
                }
            }

            if (val2 == true) {
                val1 = true;
                break;
            }
        }

        if (val1) printf("yes\n");
        else printf("no\n");


    }

    return 0;
}
