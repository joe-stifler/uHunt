/*------------------------------------------------*/
// Uva Problem No: 587
// Problem Name: There's treasure everywhere!
// Type: Computational Geometry
// Autor: Joe Stifler
// Data: 2017-07-26 15:21:06
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    int cont = 1;
    int valid = 1;
    while(valid) {
        char s[2];

        int N = 0, S = 0, W = 0, E = 0, NE = 0, NW = 0, SE = 0, SW = 0;
        while(true) {
            char c;

            if (scanf("%d%c%c", &p, &s[0], &s[1]) == 0) {
                valid = 0;
                break;
            }

            if (s[1] != ',' && s[1] != '.') scanf("%c", &c);
            else c = s[1];

            switch(s[0]) {
                case 'N':
                    if (s[1] == 'W'){
                        NW += p;
                    } else if (s[1] == 'E') {
                        NE += p;
                    }  else {
                        N += p;
                    }

                    break;
                case 'S':
                    if (s[1] == 'W'){
                        SW += p;
                    } else if (s[1] == 'E') {
                        SE += p;
                    }  else {
                        S += p;
                    }

                    break;
                case 'W':
                    W += p;
                    break;
                case 'E':
                    E += p;
                    break;
            }

            if (c == '.') {
                printf("Map #%d\n", cont);
                printf("The treasure is located at (%.3lf,%.3lf).\n", E - W + (NE - SW  - NW + SE)/sqrt(2),  N - S + (NE - SW - SE + NW)/sqrt(2));
                printf("The distance to the treasure is %.3lf.\n\n", sqrt(pow(E - W + (NE - SW  - NW + SE)/sqrt(2), 2) + pow(N - S + (NE - SW - SE + NW)/sqrt(2), 2)));

                break;
            }
        }

        cont++;
    }



    return 0;
}
