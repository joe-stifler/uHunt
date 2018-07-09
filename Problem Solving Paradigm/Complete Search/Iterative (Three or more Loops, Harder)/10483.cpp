/*------------------------------------------------*/
// Uva Problem No: 10483
// Problem Name: The Sum Equals the Product
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-28 03:08:49
// Runtime: 0.200s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-14

struct Par {
    long long int a, b, c;
    Par() {}
    Par(long long int _a, long long int _b, long long int _c) : a(_a), b(_b), c(_c) {}

    bool operator <(const Par &other) const {
        return a + b + c < other.a + other.b + other.c ||
            (a + b + c == other.a + other.b + other.c &&
                (a < other.a || (a == other.a && b < other.b)));
    }

    bool operator ==(const Par &other) const {
        return a == other.a && b == other.b && c == other.c;
    }
};

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    long long menor1 = min(a, b) * 100;
    long long maior1 = max(a, b) * 100;
    long long maior2 = max(a, b) * 10000;
    long long maior3 = max(a, b) * 1000000;

    set<Par> res;

    for (long long i = 1; i <= maior1; i++) {
        for (long long j = i; (i * j) <= maior2; j++) {
            if (i * j > 10000) {
                double gama = (double) 100.0 * (i + j) / (i * j - 10000.0);

                long long int k = (long long) 100 * gama;
                long long int vec[] = {i, j, k};
                sort(vec, vec + 3);

                if (fabs(i * j * k - 10000 * (i + j + k)) < 1e-5 &&
                        (i + j + k) >= menor1 && (i + j + k) <= maior1) {
                    res.insert(Par(vec[0], vec[1], vec[2]));
                }
            }
        }
    }

    for (auto &it : res) {
        printf("%.2lf = %.2lf + %.2lf + %.2lf = %.2lf * %.2lf * %.2lf\n", (it.a + it.b + it.c) / 100.0
                        , it.a / 100.0, it.b / 100.0, it.c / 100.0, it.a / 100.0, it.b / 100.0, it.c / 100.0);
    }

    return 0;
}
