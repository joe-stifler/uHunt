/*------------------------------------------------*/
// Uva Problem No: 188
// Problem Name: Perfect Hash
// Type: Iterative (Three or More Nested Loops, Easier) (Complete Search)
// Autor: Joe Stifler
// Data: 2017-12-10 02:57:33
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    string str;
    while(getline(cin, str)) {
        vector<int> vec;

        string buffer;
        stringstream stream(str);
        while(stream >> buffer) {
            long long mult = 1, val = 0;
            for (int i = (int) buffer.size() - 1; i >= 0; i--) {
                val += mult * (buffer[i] - 'a' + 1);
                mult *= 32;
            }

            vec.push_back(val);
        }

        sort(vec.begin(), vec.end());

        int C = 0, n = vec.size();
        bool valid = false;
        while(valid == false) {
            valid = true;
            for (int i = 0; i < n && valid; i++)
                for (int j = 0; j < n && valid; j++) {
                    if (i == j) continue;
                    if (((int) floor(((double) C / vec[i]))) % n
                        == ((int) floor(((double) C / vec[j]))) % n) {
                        C = min(((int) floor(((double) C / vec[i])) + 1) * vec[i],
                                ((int) floor(((double) C / vec[j])) + 1) * vec[j]);
                        valid = false;
                    }
                }
        }

        cout << str << endl;
        cout << C << endl << endl;

    }

    return 0;
}
