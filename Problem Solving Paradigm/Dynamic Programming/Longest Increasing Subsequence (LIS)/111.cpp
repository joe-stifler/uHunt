/*------------------------------------------------*/
// Uva Problem No: 111
// Problem Name: History Grading
// Type: Longest Increasing Subsequence (Dynamic Programming)
// Autor: Joe Stifler
// Data: 2018-07-08 20:54:19
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);

    string line;
    while(getline(cin, line)) {
        int a = 0, pos = 0;
        vector<int> ord(n);
        istringstream iss(line);

        while (iss >> a) {
            ord[a-1] = pos;
            pos++;
        }

        while(true) {
            getline(cin, line);
            istringstream iss2(line);
            vector<int> vec(n);
            pos = 0;
            while(iss2 >> a) {
                vec[a-1] = pos;
                pos++;
            }

            if (pos <= 1) {
                n = a;
                break;
            }

            int pd[vec.size() + 1][vec.size() + 1];

            for (int i = 0; i <= vec.size(); i++)
                for (int j = 0; j <= vec.size(); j++) {
                    if (i == 0 || j == 0) pd[i][j] = 0;
                    else if (ord[i-1] == vec[j-1])
                        pd[i][j] = pd[i-1][j-1] + 1;
                    else
                        pd[i][j] = max(pd[i-1][j], pd[i][j-1]);

                }

            printf("%d\n", pd[vec.size()][vec.size()]);
        }
    }

    return 0;
}
