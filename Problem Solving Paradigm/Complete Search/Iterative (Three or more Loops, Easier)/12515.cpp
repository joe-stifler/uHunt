/*------------------------------------------------*/
// Uva Problem No: 12515
// Problem Name: Movie Police
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-18 05:00:30
// Runtime: 0.270s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n0, m;
    scanf("%d %d", &n0, &m);

    string str;
    vector<string> vec;
    while(n0--) {
        cin >> str;
        vec.push_back(str);
    }

    while(m--) {
        cin >> str;
        int greater = 200, pos;

        for (int i = 0; i < (int) vec.size(); i++) {
            for (int j = 0; j < (int) vec[i].size() - (int) str.size() + 1; j++) {
                int total = 0;
                for (int k = 0, l = j; k < (int) str.size(); k++, l++) {
                    if (str[k] != vec[i][l]) total++;
                }

                if (total < greater) {
                    greater = total;
                    pos = i;
                }
            }
        }

        printf("%d\n", pos+1);
    }

    return 0;
}
