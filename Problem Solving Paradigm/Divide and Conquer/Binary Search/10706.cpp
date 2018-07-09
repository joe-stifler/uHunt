/*------------------------------------------------*/
// Uva Problem No: 10706
// Problem Name: Number Sequence
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-30 02:18:29
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

long func(int k) {
    long total = 0;

    if (k > 0) {
        if (k > 9) total += 9;
        else total += k;
    }

    if (k > 9) {
        if (k > 99) total += 90 * 2;
        else total += (k - 9) * 2;
    }

    if (k > 99) {
        if (k > 999) total += 900 * 3;
        else total += (k - 99) * 3;
    }

    if (k > 999) {
        if (k > 9999) total += 9000 * 4;
        else total += (k - 999) * 4;
    }

    if (k > 9999) {
        if (k > 99999) total += 90000 * 5;
        else total += (k - 9999) * 5;
    }

    return total;
}

int main() {
    int t;
    scanf("%d", &t);

    long *res = (long *) malloc(sizeof(long) * 100000);
    long *vals = (long *) malloc(sizeof(long) * 100000);

    res[0] = 0;
    vals[0] = 1;
    int size = 1;
    for (int k = 1; k < 100000; k++) {
        vals[k] = func(k);
        res[k] = res[k-1] + vals[k-1];
        size++;
        if (res[k] > 2147483647) break;
    }

    int val;
    while(t--) {
        cin >> val;

        long *pos = lower_bound(res, res + size, val);

        if (*pos > val) pos--;

        // printf("Pos: %d\n", pos - res);
        val = val - *pos + 1;

        if (val < 10) printf("%d\n", val);
        else if (val < 90 * 2 + 10) {
            val -= 9;
            string str(to_string(9 + floor((val % 2 == 0 ? val - 1 : val) / 2.0) + 1));

            int pos = val % 2;
            if (pos == 0) pos = 1;
            else pos = 0;

            printf("%c\n", str[pos]);
        } else if (val < 900 * 3 + 90 * 2 + 10) {
            val -= 9;
            val -= (90 * 2);
            string str(to_string(99 + floor((val % 3 == 0 ? val - 1 : val) / 3.0) + 1));

            int pos = val % 3;
            if (pos == 0) pos = 2;
            else if (pos == 2) pos = 1;
            else pos = 0;

            printf("%c\n", str[pos]);
        } else if (val < 9000 * 4 + 900 * 3 + 90 * 2 + 10) {
            val -= 9;
            val -= (90 * 2);
            val -= (900 * 3);
            string str(to_string(999 + floor((val % 4 == 0 ? val - 1 : val) / 4.0) + 1));

            int pos = val % 4;
            if (pos == 0) pos = 3;
            else if (pos == 3) pos = 2;
            else if (pos == 2) pos = 1;
            else pos = 0;

            printf("%c\n", str[pos]);
        } else {
            val -= 9;
            val -= (90 * 2);
            val -= (900 * 3);
            val -= (9000 * 4);
            string str(to_string(9999 + floor((val % 5 == 0 ? val - 1 : val) / 5.0) + 1));

            int pos = val % 5;
            if (pos == 0) pos = 4;
            else if (pos == 4) pos = 3;
            else if (pos == 3) pos = 2;
            else if (pos == 2) pos = 1;
            else pos = 0;

            printf("%c\n", str[pos]);
        }
    }

    free(res);
    free(vals);

    return 0;
}
