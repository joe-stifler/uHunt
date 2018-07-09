/*------------------------------------------------*/
// Uva Problem No: 1111
// Problem Name: Trash Removal
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-15 14:26:43
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator <(point other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator !=(point other) const {
        return x != other.x || y != other.y;
    }
};

double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double cross(point o, point a, point b) {
    double oax = a.x - o.x, oay = a.y - o.y;
    double obx = b.x - o.x, oby = b.y - o.y;

    return oax * oby - obx * oay;
}

point scale(point ab, double u) {
    return point(ab.x * u, ab.y * u);
}

point translate(point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}

double dist(point a, point b) {
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y, 2));
}

bool onSegment(point p, point a, point b) {
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
                p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

double distToLine(point p, point a, point b, point &c) {
    point ap(p.x - a.x, p.y - a.y), ab(b.x - a.x, b.y - a.y);
    double u = dot(ap, ab) / dot(ab, ab);
    c = translate(a, scale(ab, u));

    return dist(p, c);
}

vector<point> convexHull(vector<point> &pts) {
    int n = pts.size(), k = 0;
    vector<point> convex(2 * n + 1);

    sort(pts.begin(), pts.end());

    // constroi lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    // constroi upper hull
    for (int i = n - 1, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(convex[k-2], convex[k-1], pts[i]) <= 0) k--;
        convex[k++] = pts[i];
    }

    convex.resize(k);

    return convex;
}

int main() {
    int n;
    int cont = 1;

    while(true) {
        scanf("%d", &n);

        if (n == 0) return 0;

        double x, y;
        vector<point> pts;
        while(n--) {
            scanf("%lf %lf", &x, &y);
            pts.push_back(point(x, y));
        }

        vector<point> convex = convexHull(pts);

        point c;
        double distancia, menorDist = 99999999.0;
        for (int i = 0; i < (int) convex.size() - 1; i++) {
            double maiorDist = 0;
            point pi = convex[i], pi1 = convex[i+1];
            point a = convex[i], b = convex[i+1];
            for (int j = 0; j < (int) convex.size()-1; j++) {
                if (j != i && j != i + 1) {
                    distancia = distToLine(convex[j], pi, pi1, c);
                    maiorDist = max(maiorDist, distancia);

                    if (!onSegment(c, pi, pi1)) {
                        if (dist(pi, c) < dist(pi1, c) &&
                                dist(pi, c) > dist(a, pi)) {
                            a = c;
                        } else if(dist(pi, c) > dist(pi1, c) &&
                                    dist(pi1, c) > dist(b, pi1)) {
                            b = c;
                        }
                    }
                }
            }

            menorDist = min(menorDist, maiorDist);
            menorDist = min(menorDist, dist(a, b));
        }

        printf("Case %d: %.2lf\n", cont, menorDist);
        cont++;
    }

    return 0;
}
