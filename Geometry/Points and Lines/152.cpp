/*------------------------------------------------*/
// Uva Problem No: 152
// Problem Name: Tree's a Crowd
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-26 13:44:58
// Runtime: 0.150s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

struct point {
    int x, y, z;

    point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) { }

    bool operator == (point other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS && fabs(z - other.z) < EPS;
    }
};

double dist(point a, point b) {
    return sqrt((a.x -  b.x) * (a.x -  b.x) +
                (a.y -  b.y) * (a.y -  b.y) +
                (a.z -  b.z) * (a.z -  b.z));
}

int main() {
    int x, y, z;
    vector<point> points;
    int vec[11] = {0};

    while (true) {
        scanf ("%d %d %d", &x, &y, &z);

        if (!x && !y && !z) break;

        point d(x, y, z);
        points.push_back(d);
    }

    for (int i = 0; i < (signed) points.size(); i++) {
        point d = points[i];

        double aux = 99999999999;
        for (int j = 0; j < (signed) points.size(); j++) {
            if (j == i) continue;

            double num = dist(d, points[j]);

            if (num < aux) aux = num;
        }

        for (int j = 0; j < 10; j++) {
            if (aux >= j && aux < j + 1) {
                vec[j]++;

                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << setw(4) << right << vec[i];
    }

    printf("\n");

    return 0;
}
