/*------------------------------------------------*/
// Uva Problem No: 378
// Problem Name: Intersecting Lines
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-26 04:00:58
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

// a way to represent a line
struct line {
    double a, b, c;
};

// equacao da reta a partir de dois pontos
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

// verifica se duas retas são paralelas
bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}

// verifica se duas retas são equivalentes
bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

// return true + intersection point if two lines are intersectio
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;

    // solve system of two linear algebraic equations with 2 unkowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("INTERSECTING LINES OUTPUT\n");

    while (n--) {
        point p1, p2, p3, p4, c;
        scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
        scanf("%lf %lf %lf %lf", &p3.x, &p3.y, &p4.x, &p4.y);

        line l1, l2;

        pointsToLine(p1, p2, l1);
        pointsToLine(p3, p4, l2);

        if (areSame(l1, l2)) printf("LINE\n");
        else if (areParallel(l1, l2)) printf("NONE\n");
        else {
            areIntersect(l1, l2, c);
            printf("POINT %.2lf %.2lf\n", c.x, c.y);
        }
    }

    printf("END OF OUTPUT\n");

    return 0;
}
