/*------------------------------------------------*/
// Uva Problem No: 11505
// Problem Name: Logo
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-08-04 17:56:04
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}

int main() {
    int n;
    scanf ("%d", &n);

    while (n--) {
        int t;
        scanf ("%d%*c", &t);

        double teta = 0;
        char c;
        int tam;

        double x = 0, y = 0;
        for (int i = 0; i < t; i++) {
            scanf ("%c%*c %d%*c", &c, &tam);

            if (c == 'f') {
                double _x = (double) tam * cos(DEG_to_RAD(teta)), _y = (double) tam * sin(DEG_to_RAD(teta));

                x += _x;
                y += _y;
            } else if (c == 'b') {
                double _x = - (double) tam * cos(DEG_to_RAD(teta)), _y = - (double) tam * sin(DEG_to_RAD(teta));

                x += _x;
                y += _y;
            } else if (c == 'r') {
                teta -= tam;
            } else {
                teta += tam;
            }
        }

        int total = round(sqrt(x * x + y * y));

        printf("%d\n", total);
    }

    return 0;
}
