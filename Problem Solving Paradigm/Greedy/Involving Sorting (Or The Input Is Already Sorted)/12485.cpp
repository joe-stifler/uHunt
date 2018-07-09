/*------------------------------------------------*/
// Uva Problem No: 12485
// Problem Name: Perfect Choir
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-17 04:25:18
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int maior = -1000000;
        int media = 0;
        int menor = 1000000;
        vector<int> notas(n);

        while(n--) {
            scanf("%d", &notas[n]);
            media += notas[n];
            maior = max(maior, notas[n]);
            menor = min(menor, notas[n]);
        }


        if (abs(media) % notas.size() == 0) {
            media =  media / (int) notas.size();

            sort(notas.begin(), notas.end());

            int total = 0;
            for (int i = 0, j = notas.size()-1; i < j; ) {
                if (notas[i] < media && notas[j] > media) {
                    if (media - notas[i] < notas[j] - media) {
                        total += media - notas[i];
                        i++;
                    } else if (media - notas[i] > notas[j] - media) {
                        total += notas[j] - media;
                        j--;
                    } else {
                        total += notas[j] - media;
                        i++;
                        j--;
                    }
                } else break;
            }

            printf("%d\n", total + 1);
        } else printf("-1\n");
    }
    return 0;
}
