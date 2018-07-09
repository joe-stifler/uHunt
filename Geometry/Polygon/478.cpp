/*------------------------------------------------*/
// Uva Problem No: 478
// Problem Name: Points in Figures: Rectangles, Circles, Triangles
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-08 10:30:19
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-12
#define pi acos(-1)

struct fig {
    int tipo;

    struct r {
        double xi, yi, xf, yf;
    } r;

    struct t {
        double xa, xb, xc;
        double ya, yb, yc;
    } t;

    struct c {
        double x, y, r;
    } c;
};

struct point {
    double x, y;
    point () : x(0.0), y(0.0) {}

    point (double _x, double _y) : x(_x), y(_y) {}
};


struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

/* Angulo formado por dois vetores */
double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(dot(oa, oa) * dot(ob, ob)));
}

int main() {
    fig f;
    char c;
    vector<fig> vec;

    while(true) {
        scanf("%c", &c);

        if (c == '*') break;
        else if (c == 'r') {
            f.tipo = 0;
            scanf("%lf %lf %lf %lf%*c", &f.r.xi, &f.r.yi, &f.r.xf, &f.r.yf);
            vec.push_back(f);
        } else if (c == 't') {
            f.tipo = 1;
            scanf("%lf %lf %lf %lf %lf %lf%*c", &f.t.xa, &f.t.ya, &f.t.xb, &f.t.yb, &f.t.xc, &f.t.yc);
            vec.push_back(f);
        } else if (c == 'c') {
            f.tipo = 2;
            scanf("%lf %lf %lf%*c", &f.c.x, &f.c.y, &f.c.r);
            vec.push_back(f);
        }
    }

    int cont = 1;
    double x, y;
    while(scanf("%lf %lf", &x, &y) != EOF) {
        bool stat = false;

        if (x == 9999.9 && y == 9999.9) return 0;

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].tipo == 0) { // retangulo
                if (x > vec[i].r.xi && x < vec[i].r.xf
                        && y < vec[i].r.yi && y > vec[i].r.yf) {
                            stat = true;
                            printf("Point %d is contained in figure %d\n", cont, i + 1);
                        }
            } else if (vec[i].tipo == 1) { // triangulo
                double angulo = angle(point(vec[i].t.xa, vec[i].t.ya), point(x, y), point(vec[i].t.xb, vec[i].t.yb))
                        + angle(point(vec[i].t.xb, vec[i].t.yb), point(x, y), point(vec[i].t.xc, vec[i].t.yc))
                            + angle(point(vec[i].t.xc, vec[i].t.yc), point(x, y), point(vec[i].t.xa, vec[i].t.ya));
                if (fabs(angulo - 2 * pi) < EPS) {
                    stat = true;

                    printf("Point %d is contained in figure %d\n", cont, i + 1);
                }
            } else if (vec[i].tipo == 2) { // circulo
                if (pow(vec[i].c.x - x, 2) + pow(vec[i].c.y - y, 2) < pow(vec[i].c.r, 2)) {
                    stat = true;

                    printf("Point %d is contained in figure %d\n", cont, i + 1);
                }
            }
        }

        if (stat == false) printf("Point %d is not contained in any figure\n", cont);
        cont++;
    }

    return 0;
}
