/*------------------------------------------------*/
// Uva Problem No: 10037
// Problem Name: Bridge
// Type: Classical, Usually Easier (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-10 02:10:56
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    int caso = 0;
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<int> vals;
        while(n--) {
            int v;
            scanf("%d", &v);
            vals.push_back(v);
        }

        sort(vals.begin(), vals.end());

        int i;
        int cont = 0;
        int total = 0;
        int count = 0;
        vector<int> res;

        int a, b;
        int A = vals[0], B = vals[1];
        for (i = vals.size() - 1; i > 2; i -= 2) {
            a = vals[i];
            b = vals[i-1];

            int t1 = a + b + 2 * A;
            int t2 = a + A + 2 * B;
            if (t1 < t2) {
                total += t1;
                res.push_back(A);
                res.push_back(b);

                res.push_back(A);

                res.push_back(A);
                res.push_back(a);

                res.push_back(A);
            } else {
                total += t2;
                res.push_back(A);
                res.push_back(B);

                res.push_back(A);

                res.push_back(b);
                res.push_back(a);

                res.push_back(B);
            }
        }

        if (caso != 0) printf("\n");

        if (vals.size() == 1)
            printf("%d\n%d\n", vals[0], vals[0]);
        else {
            if (vals.size() % 2 == 0) {
                total += vals[1];
                res.push_back(vals[0]);
                res.push_back(vals[1]);
            } else {
                total += vals[2] + vals[0] + vals[1];
                res.push_back(vals[0]);
                res.push_back(vals[1]);
                res.push_back(vals[0]);

                res.push_back(vals[0]);
                res.push_back(vals[2]);
            }

            printf("%d\n", total);
            for (int i = 0; i < res.size(); i++) {
                if (i % 3 == 2) printf("\n");
                else if (i % 3 == 1) printf(" ");

                printf("%d", res[i]);

                if (i % 3 == 2) printf("\n");
            }
            printf("\n");
        }

        caso++;
    }
    return 0;
}
