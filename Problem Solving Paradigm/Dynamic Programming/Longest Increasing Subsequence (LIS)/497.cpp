/*------------------------------------------------*/
// Uva Problem No: 497
// Problem Name: Strategic Defense Initiative
// Type: Longest Increasing Subsequence (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-07-09 00:44:43
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

void printRes(vector<int> &res, int pos, vector<int> &vec) {
    if (res[pos] != pos) printRes(res, res[pos], vec);
    printf("%d\n", vec[pos]);
}

int main() {
    int t;
    scanf("%d\n \n", &t);

    int caso = 0;
    while(t--) {
        string line;
        vector<int> vec;
        while(true) {
            if (!getline(cin, line)) break;
            int a;
            istringstream iss(line);
            if (!(iss >> a)) break;
            vec.push_back(a);
        }

        int last = 0, maior = 0;
        vector<int> pd(vec.size(), 0);
        vector<int> res(vec.size(), -1);
        for (int i = 0; i < vec.size(); i++) {
            pd[i] = 1;
            res[i] = i;
            for (int j = i - 1; j >= 0; j--) {
                if (vec[j] < vec[i]) {
                    if (pd[j] + 1 >= pd[i]) {
                        res[i] = j;
                        pd[i] = pd[j] + 1;
                    }
                }
            }

            if (pd[i] > maior) {
                maior = pd[i];
                last = i;
            }
        }

        if (caso) printf("\n");
        else caso++;
        printf("Max hits: %d\n", maior);
        printRes(res, last, vec);
    }
    return 0;
}
