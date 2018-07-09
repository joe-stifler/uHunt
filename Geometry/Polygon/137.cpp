/*------------------------------------------------*/
// Uva Problem No: 137
// Problem Name: Polygons
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-15 01:54:56
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define pi acos(-1)
#define EPS 1e-9

struct point {
    double x, y;
    point() {}
    point (double _x, double _y) : x(_x), y(_y) {}

    bool operator <(point other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};


struct vec {
    int x, y;
    vec(int _x, int _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

double angle(point o, point a, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(dot(oa, oa) * dot(ob, ob)));
}

int cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

bool ccw(point o, point a, point b) {
    return cross(toVec(o, a), toVec(o, b)) > 0;
}

bool inPolygon(point p, vector<point> &pts) {
    if ((int) pts.size() == 0) return false;

    double sum = 0;
    for (int i = 0; i < (int) pts.size() - 1; i++) {
        if (ccw(p, pts[i], pts[i+1])) sum += angle(p, pts[i], pts[i+1]);
        else sum -= angle(p, pts[i], pts[i+1]);
    }

    return fabs(fabs(sum) - 2 * pi) < EPS;
}

/*
 * dado tres pontos p, q e r colineares, a função cheka se
 * o ponto r repousa dentro do segmento de reta pq
 */
bool onSegment(point p, point q, point r) {
    if (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x)
            && r.y <= max(p.y, q.y) && r.y >= min(p.y, q.y))
                return true;

    return false;
}

/*
 * 0 --> p, q e r são colineares
 * 1 --> horário (negativo)
 * 2 --> antihorário (positivo)
 */
double cross2(vec a, vec b) {
    double val = a.x * b.y - a.y * b.x;
    if (val == 0) return 0;
    else if (val > 0) return 1;
    else return 2;
}

/*
 * retorna true se o segmento de reta p1q1 intersecta
 * o segmento de reta p2q2
 */
bool doIntersect(point p1, point q1, point p2, point q2) {
    double o1 = cross2(toVec(p1, q1), toVec(p1, p2));
    double o2 = cross2(toVec(p1, q1), toVec(p1, q2));
    double o3 = cross2(toVec(p2, q2), toVec(p2, p1));
    double o4 = cross2(toVec(p2, q2), toVec(p2, q1));
    // Casos especiais
    // p1, q1 e p2 são colineares e p2 repousa no segmento p1q1
    if (o1 == 0 && onSegment(p1, q1, p2)) return true;
    // p1, q1 e q2 são colineares e q2 repousa no segmento p1q1
    if (o2 == 0 && onSegment(p1, q1, q2)) return true;
    // p2, q2 e p1 são colineares e p1 repousa no segmento p2q2
    if (o3 == 0 && onSegment(p2, q2, p1)) return true;
     // p2, q2 e q1 são colineares e q1 repousa no segmento p2q2
    if (o4 == 0 && onSegment(p2, q2, p1)) return true;
    // Caso geral
    if (o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0) return true;
    return false; // não existe intersecção
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
      double a = B.y - A.y;
      double b = A.x - B.x;
      double c = B.x * A.y - A.x * B.y;
      double u = fabs(a * p.x + b * p.y + c);
      double v = fabs(a * q.x + b * q.y + c);
      return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}

double cross(const point &o, const point &a, const point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
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
    while (true) {
        scanf("%d", &n);

        if (n == 0) {
            printf("\n");
            return 0;
        }

        double x, y;
        vector<point> poli1;
        while (n--) {
            scanf("%lf %lf", &x, &y);
            poli1.push_back(point(x, y));
        }

        poli1.push_back(poli1[0]);

        scanf("%d", &n);

        vector<point> poli2;
        while (n--) {
            scanf("%lf %lf", &x, &y);
            poli2.push_back(point(x, y));
        }

        poli2.push_back(poli2[0]);

        set<point> pts;
        for (int i = 0; i < poli1.size(); i++) {
            bool valid = true;
            for (int j = 0; j < poli2.size()-1; j++) {
                if (cross(toVec(poli1[i], poli2[j]), toVec(poli1[i], poli2[j+1])) == 0
                        && onSegment(poli2[j], poli2[j+1], poli1[i])) {
                    pts.insert(poli1[i]);
                    valid = false;
                } else if (i > 0 &&
                    doIntersect(poli1[i-1], poli1[i], poli2[j], poli2[j+1])) {
                    pts.insert(lineIntersectSeg(poli1[i-1], poli1[i], poli2[j], poli2[j+1]));
                }
            }

            if (valid && inPolygon(poli1[i], poli2)) pts.insert(poli1[i]);
        }

        for (int i = 0; i < poli2.size(); i++) {
            bool valid = true;
            for (int j = 0; j < poli1.size()-1; j++) {
                if (cross(toVec(poli2[i], poli1[j]), toVec(poli2[i], poli1[j+1])) == 0
                        && onSegment(poli1[j], poli1[j+1], poli2[i])) {
                    pts.insert(poli2[i]);
                    valid = false;
                } else if (i > 0 &&
                    doIntersect(poli2[i-1], poli2[i], poli1[j], poli1[j+1])) {
                    pts.insert(lineIntersectSeg(poli2[i-1], poli2[i], poli1[j], poli1[j+1]));
                }
            }

            if (valid && inPolygon(poli2[i], poli1)) pts.insert(poli2[i]);
        }

        vector<point> points;
        for (auto it = pts.begin(); it != pts.end(); it++) {
            points.push_back(*it);
        }

        points = convexHull(points);

        // printf("tam: %d\n", points.size());
        double area1 = 0, area2 = 0, areaInter = 0;
        for (int i = 0; i < poli1.size() - 1; i++) {
            area1 += poli1[i].x * poli1[i+1].y - poli1[i+1].x * poli1[i].y;
        }

        for (int i = 0; i < poli2.size() - 1; i++) {
            area2 += poli2[i].x * poli2[i+1].y - poli2[i+1].x * poli2[i].y;
        }

        for (int i = 1; i < points.size(); i++) {
            areaInter += points[i-1].x * points[i].y - points[i].x * points[i-1].y;
        }

        double total1 = fabs(area1) / 2.0 + fabs(area2) / 2.0 - fabs(areaInter);

        int intPart = (int) total1;
        if (intPart <= 10) intPart = 10;
        while (intPart <= 10000) {
            printf(" ");
            intPart *= 10;
        }
        printf("%.2lf", total1);
    }

    return 0;
}
