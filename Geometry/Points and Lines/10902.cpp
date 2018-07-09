/*------------------------------------------------*/
// Uva Problem No: 10902
// Problem Name: Pick-up Sticks
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-09-04 07:23:34
// Runtime: 0.110s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point {
    double x, y;
    point () {}
    point (double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};


struct seg {
    point ini, end;
    int ind;

    seg () {}
    seg (double x1, double y1, double x2, double y2, int _ind) : ini(x1, y1), end(x2, y2), ind(_ind) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

/*
 * dado tres pontos p, q e r colineares, a função cheka se
 * o ponto r repousa dentro do segmento de reta pq
 */
bool onSegment(point p, point q, point r)
{
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
double cross(vec a, vec b) {
    double val = a.x * b.y - a.y * b.x;
    if (val == 0) return 0;
    else if (val > 0) return 1;
    else return 2;
}

/*
 * retorna true se o segmento de reta p1q1 intersecta
 * o segmento de reta p2q2
 */
bool doIntersect(point p1, point q1, point p2, point q2)
{
    double o1 = cross(toVec(p1, q1), toVec(p1, p2));
    double o2 = cross(toVec(p1, q1), toVec(p1, q2));
    double o3 = cross(toVec(p2, q2), toVec(p2, p1));
    double o4 = cross(toVec(p2, q2), toVec(p2, q1));

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
    if (o1 != o2 && o3 != o4 &&
        o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0) return true;

    return false; // não existe intersecção
}

int main() {

    while (true) {
        int n;
        scanf ("%d", &n);
        if (n == 0) break;

        double x1, y1, x2, y2;
        seg aux;
        queue<seg> segs;
        for (int i = 1; i <= n; i++) {
            scanf ("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

            int tam = segs.size();
            for (int j = 0; j < tam; j++) {
                if (doIntersect(point(x1, y1), point(x2, y2), segs.front().ini, segs.front().end) == true) {
                    segs.pop();
                } else {
                    aux = segs.front();
                    segs.pop();
                    segs.push(aux);
                }
            }

            segs.push(seg(x1, y1, x2, y2, i));
        }

        printf("Top sticks: ");
        while (!segs.empty()) {
            printf("%d", segs.front().ind);
            segs.pop();

            if (segs.empty()) printf(".\n");
            else printf(", ");
        }
    }
    return 0;
}
