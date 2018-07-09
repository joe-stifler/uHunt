/*------------------------------------------------*/
// Uva Problem No: 253
// Problem Name: Cube painting
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-21 22:39:56
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char cubos[2][6];

    while(true) {
        for (int i = 0; i < 2; i++) {
            if (scanf("%c", &cubos[i][1]) == EOF) return 0;
            scanf("%c", &cubos[i][2]);
            scanf("%c", &cubos[i][5]);
            scanf("%c", &cubos[i][0]);
            scanf("%c", &cubos[i][4]);
            scanf("%c", &cubos[i][3]);
        }

        scanf("%*c");

        n = 2;
        bool valid, visited[n];
        int cont = 0, aux, vec[4];

        memset(visited, false, sizeof visited);

        for(int i = 0; i < n; i++) {
            // caso cubo nao tenha sido igual a algum anterior...
            if (visited[i] == false) {
                // verifica se cada um dos cubos restantes eh igual ao cubo[i]
                for (int j = i + 1; j < n; j++) {
                    if (visited[j] == false) {
                        valid = false;
                        for (int k = 0; k < 6 && valid == false; k++) {
                            if (cubos[i][0] == cubos[j][k]) {
                                switch(k) {
                                    case 0:
                                    case 5:
                                        if (k == 0) {
                                            vec[0] = cubos[j][1];
                                            vec[1] = cubos[j][2];
                                            vec[2] = cubos[j][3];
                                            vec[3] = cubos[j][4];
                                        } else {
                                            vec[0] = cubos[j][3];
                                            vec[1] = cubos[j][2];
                                            vec[2] = cubos[j][1];
                                            vec[3] = cubos[j][4];
                                        }

                                        for (int l = 0; l < 4; l++) {
                                            if (cubos[i][1] == vec[0] && cubos[i][2] == vec[1] &&
                                                    cubos[i][3] == vec[2] && cubos[i][4] == vec[3]) {

                                                    if((k == 0 && cubos[i][5] == cubos[j][5]) ||
                                                            (k == 5 && cubos[i][5] == cubos[j][0])) {
                                                                valid = true;
                                                    }
                                            }

                                            aux = vec[0];
                                            vec[0] = vec[1];
                                            vec[1] = vec[2];
                                            vec[2] = vec[3];
                                            vec[3] = aux;
                                        }

                                        break;
                                    case 1:
                                    case 3:
                                        if (k == 1) {
                                            vec[0] = cubos[j][2];
                                            vec[1] = cubos[j][0];
                                            vec[2] = cubos[j][4];
                                            vec[3] = cubos[j][5];
                                        } else {
                                            vec[0] = cubos[j][0];
                                            vec[1] = cubos[j][2];
                                            vec[2] = cubos[j][5];
                                            vec[3] = cubos[j][4];
                                        }

                                        for (int l = 0; l < 4; l++) {
                                            if (cubos[i][1] == vec[0] && cubos[i][2] == vec[1] &&
                                                    cubos[i][3] == vec[2] && cubos[i][4] == vec[3]) {

                                                    if((k == 1 && cubos[i][5] == cubos[j][3]) ||
                                                            (k == 3 && cubos[i][5] == cubos[j][1])) {
                                                                valid = true;
                                                    }
                                                }

                                                aux = vec[0];
                                                vec[0] = vec[1];
                                                vec[1] = vec[2];
                                                vec[2] = vec[3];
                                                vec[3] = aux;
                                        }

                                        break;
                                    case 2:
                                    case 4:
                                        if (k == 2) {
                                            vec[0] = cubos[j][0];
                                            vec[1] = cubos[j][1];
                                            vec[2] = cubos[j][5];
                                            vec[3] = cubos[j][3];
                                        } else {
                                            vec[0] = cubos[j][0];
                                            vec[1] = cubos[j][3];
                                            vec[2] = cubos[j][5];
                                            vec[3] = cubos[j][1];
                                        }

                                        for (int l = 0; l < 4; l++) {
                                            if (cubos[i][1] == vec[0] && cubos[i][2] == vec[1] &&
                                                    cubos[i][3] == vec[2] && cubos[i][4] == vec[3]) {

                                                    if((k == 2 && cubos[i][5] == cubos[j][4]) ||
                                                            (k == 4 && cubos[i][5] == cubos[j][2])) {
                                                                valid = true;
                                                            }
                                                }

                                                aux = vec[0];
                                                vec[0] = vec[1];
                                                vec[1] = vec[2];
                                                vec[2] = vec[3];
                                                vec[3] = aux;
                                        }

                                        break;
                                }
                            }
                        }

                        visited[j] = valid;
                        if (valid == true) cont++;
                    }
                }
            }
        }

        if (cont == 0) printf("FALSE\n");
        else printf("TRUE\n");
    }
}
