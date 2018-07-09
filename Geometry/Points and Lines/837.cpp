/*------------------------------------------------*/
// Uva Problem No: 837
// Problem Name: There's treasure everywhere!
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-26 18:48:21
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    int e;
    double x, y;
    double trans;

    point(int _e, double _x, double _y, double _trans) : e(_e), x(_x), y(_y), trans(_trans) { }

    bool operator < (point other) const {
        if (x == other.x)
            return y > other.y;
        return x > other.x;
    }

    point& operator= (point const& a) {
        e = a.e;
        x = a.x;
        y = a.y;
        trans = a.trans;

        return *this;
    }
};

int main() {
    int n;
    scanf ("%d\n\n", &n);

    while (n--) {
        int k;
        scanf ("%d", &k);

        priority_queue<point> points;

        for (int i = 0; i < k; i++) {
            double x1, y1, x2, y2, trans;
            scanf ("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &trans);

            if (x1 < x2) {
                points.push(point(0, x1, y1, trans));
                points.push(point(1, x2, y2, trans));
            } else {
                points.push(point(1, x1, y1, trans));
                points.push(point(0, x2, y2, trans));
            }
        }

        printf("%d\n", k * 2 + 1);


        point p = points.top();
        double status = 1;
        printf("-inf %.3lf %.3lf\n", p.x, status);
        status = p.trans;
        points.pop();

        double x = p.x;
        while (!points.empty()) {
            p = points.top();
            printf("%.3lf %.3lf %.3lf\n", x, p.x, status);
            if (p.e == 0) status *= p.trans;
            else status /= p.trans;
            x = p.x;
            points.pop();
        }

        printf("%.3lf +inf %.3lf\n", p.x, 1.0);


    }

    return 0;
}
