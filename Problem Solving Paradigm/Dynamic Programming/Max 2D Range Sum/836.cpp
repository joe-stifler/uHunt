/*------------------------------------------------*/
// Uva Problem No: 836
// Problem Name: Largest Submatrix
// Type: Max 2D Range Sum (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-02-12 13:09:55
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d\n\n", &n);

    while(n--) {
        string str;
        vector<string> strs;
        while(true) {
            getline(cin, str);
            if (str.size() == 0) break;
            strs.push_back(str);
        }

        int l = strs.size(), c = strs[0].size();
        int vec[strs.size()][strs[0].size()];

        memset(vec, 0, sizeof(vec));

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                if (strs[i][j] == '1')
                    vec[i][j] = ((i > 0) ? vec[i-1][j] : 0) + 1;
            }
        }

        int maior = 0, menor = 30000;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                int cont = 0;
                menor = 30000;
                for (int k = j; k < c; k++) {
                    if (strs[i][k] == '0') {
                        cont = 0;
                        menor = 30000;
                    } else {
                        cont++;
                        menor = min(menor, vec[i][k]);
                        maior = max(maior, cont * menor);
                    }
                }
            }
        }

        printf("%d\n", maior);
        if (n != 0) printf("\n");
    }
    return 0;
}
