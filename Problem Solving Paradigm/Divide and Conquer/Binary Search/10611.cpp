/*------------------------------------------------*/
// Uva Problem No: 10611
// Problem Name: The Playboy Chimp
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-29 01:44:38
// Runtime: 0.040s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    long val;
    vector<long> vals;

    for (int i = 0; i < n; i++) {
        cin >> val;
        vals.push_back(val);
    }

    int q;
    cin >> q;

    while(q--) {
        cin >> val;

        vector<long>::iterator lo = lower_bound(vals.begin(), vals.end(), val);
        vector<long>::iterator up = upper_bound(vals.begin(), vals.end(), val);

        if (lo == vals.end() || (lo != vals.begin() && *lo >= val)) lo--;

        if (lo == vals.end() || *lo >= val) printf("X ");
        else cout << *lo << " ";

        if (up == vals.end()) printf("X\n");
        else cout << *up << endl;
    }

    return 0;
}
