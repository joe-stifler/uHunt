/*------------------------------------------------*/
// Uva Problem No: 256
// Problem Name: Quirksome Squares
// Type: Iterative (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-03 13:02:16
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    char str2[3][3] = {"00", "01", "81"};

    char str4[5][5] = { "0000", "0001", "2025",
                       "3025", "9801" };

    char str6[5][7] = {"000000",
                     "000001",
                     "088209",
                     "494209",
                     "998001"};

    char str8[9][9] = {"00000000", "00000001", "04941729",
                    "07441984", "24502500", "25502500",
                    "52881984", "60481729", "99980001" };

    int n;
    while(scanf("%d", &n) != EOF) {
        if (n == 2) {
            for (int i = 0; i < 3; i++) {
                printf("%s\n", str2[i]);
            }
        } else if (n == 4) {
            for (int i = 0; i < 5; i++) {
                printf("%s\n", str4[i]);
            }
        } else if (n == 6) {
            for (int i = 0; i < 5; i++) {
                printf("%s\n", str6[i]);
            }
        } else {
            for (int i = 0; i < 9; i++) {
                printf("%s\n", str8[i]);
            }
        }
    }

    return 0;
}
