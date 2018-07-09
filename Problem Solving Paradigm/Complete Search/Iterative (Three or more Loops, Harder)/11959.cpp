/*------------------------------------------------*/
// Uva Problem No: 11959
// Problem Name: Dice
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-09 00:59:26
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d%*c", &t);

    while(t--) {
        char dice1[6], dice2[6];
        scanf("%c%c%c%c%c%c ", &dice1[0], &dice1[5], &dice1[2], &dice1[3], &dice1[4], &dice1[1]);
        scanf("%c%c%c%c%c%c%*c", &dice2[0], &dice2[5], &dice2[2], &dice2[3], &dice2[4], &dice2[1]);

        bool status = false;
        for (int i = 0; i < 6; i++) {
            if (dice1[0] == dice2[i]) {
                vector<int> v;
                if (i == 0) {
                    int vec[] = {dice2[0], dice2[1], dice2[2], dice2[3], dice2[4], dice2[5]};
                    v = vector<int>(vec, vec + 6);
                } else if (i == 1) {
                    int vec[] = {dice2[1], dice2[5], dice2[2], dice2[0], dice2[4], dice2[3]};
                    v = vector<int>(vec, vec + 6);
                } else if (i == 2) {
                    int vec[] = {dice2[2], dice2[5], dice2[3], dice2[0], dice2[1], dice2[4]};
                    v = vector<int>(vec, vec + 6);
                } else if (i == 3) {
                    int vec[] = {dice2[3], dice2[5], dice2[4], dice2[0], dice2[2], dice2[1]};
                    v = vector<int>(vec, vec + 6);
                } else if (i == 4) {
                    int vec[] = {dice2[4], dice2[1], dice2[0], dice2[3], dice2[5], dice2[2]};
                    v = vector<int>(vec, vec + 6);
                } else if (i == 5) {
                    int vec[] = {dice2[5], dice2[4], dice2[3], dice2[2], dice2[1], dice2[0]};
                    v = vector<int>(vec, vec + 6);
                }

                for (int i = 0; i < 6 && !status; i++) {
                    bool stat = true;
                    for (int j = 0; j < 6 && stat; j++)
                        if (dice1[j] != v[j]) stat = false;

                    if (stat) status = true;

                    int aux = v[4];
                    for (int j = 4; j > 1; j--) v[j] = v[j-1];
                    v[1] = aux;
                }
            }
        }

        if (status) printf("Equal\n");
        else printf("Not Equal\n");
    }

    return 0;
}
