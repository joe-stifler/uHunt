/*------------------------------------------------*/
// Uva Problem No: 11701
// Problem Name: Cantor
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-02-05 09:33:33
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    while(true) {
        string str;
        cin >> str;

        if (str.compare("END") == 0) return 0;

        if (str[0] == '1') printf("MEMBER\n");
        else if (str.size() == 1) printf("MEMBER\n");
        else {
            int cont = 10;
            bool status = true;
            int num = atof(&str[0]) * 1e6;

            while(cont--) {
                if (floor(num / 1000000.0) == 1) status = false;
                num = (num % 1000000) * 3;
            }

            if (status) printf("MEMBER\n");
            else printf("NON-MEMBER\n");
        }
    }
}
