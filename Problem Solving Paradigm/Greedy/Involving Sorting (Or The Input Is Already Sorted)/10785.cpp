/*------------------------------------------------*/
// Uva Problem No: 10785
// Problem Name: The Mad Numerologist
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-17 02:56:36
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        int n;
        scanf("%d", &n);

        int v[] = {1, 3, 5, 6, 9};
        char vc[] = {'A', 'U', 'E', 'O', 'I'};

        char c[] = {
            '1', '1', '2', '2',
            '2', '3', '3', '4',
            '4', '4', '5', '5',
            '6', '6', '6', '7',
            '7', '8', '8',
            '8', '9'
        };

        char cc[] = {
            'J', 'S', 'B', 'K',
            'T', 'C', 'L', 'D',
            'M', 'V', 'N', 'W',
            'F', 'X', 'G', 'P',
            'Y', 'H', 'Q', 'Z', 'R'
        };

        int total = 0;
        int nv = 0, nc = 0;
        int pv = 0, pc = 0;
        printf("Case %d: ", test);
        vector<char> res1, res2;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                res1.push_back(vc[pv]);
                total += v[pv];
                nv++;
                if (nv == 21) {
                    nv = 0;
                    pv++;
                }
            } else {
                res2.push_back(cc[pc]);
                total += c[pc];
                nc++;
                if (nc == 5) {
                    nc = 0;
                    pc++;
                }
            }
        }

        sort(res1.begin(), res1.end());
        sort(res2.begin(), res2.end());

        int p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) printf("%c", res1[p1++]);
            else printf("%c", res2[p2++]);
        }
        printf("\n");
    }

    return 0;
}
