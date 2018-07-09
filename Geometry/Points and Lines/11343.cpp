/*------------------------------------------------*/
// Uva Problem No: 11343
// Problem Name: Isolated Segments
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-08-04 17:16:21
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point {
    double x, y;
    point () {x = y = 0;}
    point (double _x, double _y) {
        x = _x;
        y = _y;
    }
};

struct seg {
    point a, b;
    bool col;

    seg () {
        col = false;
    }

    seg (point _a, point _b) {
        a = _a;
        b = _b;

        col = false;
    }
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(point p, point q, point r)
{
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(point p1, point q1, point p2, point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

int main() {
    int n;
    scanf ("%d", &n);

    while (n--) {
        int t;
        scanf ("%d", &t);

        int x1, y1, x2, y2;
        vector<seg> segs;
        for (int i = 0; i < t; i++) {
            scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
            segs.push_back(seg(point(x1, y1), point(x2, y2)));
        }

        for (int i = 0; i < t; i++) {
            for (int j = i + 1; j < t; j++) {
                if (doIntersect(segs[i].a, segs[i].b, segs[j].a, segs[j].b) == true) {
                    segs[i].col = true;
                    segs[j].col = true;
                }
            }
        }

        int cont = 0;
        for (int i = 0; i < t; i++) {
            if (segs[i].col == false) cont++;
        }

        printf("%d\n", cont);
    }

    return 0;
}
