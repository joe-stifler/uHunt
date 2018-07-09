/*------------------------------------------------*/
// Uva Problem No: 11512
// Problem Name: GATTACA
// Type: Suffix Trie, Tree, Array (String Processing)
// Autor: Joe Stifler
// Data: 2017-09-29 09:19:46
// Runtime: 0.020s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 100010
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

char P[MAX_N];
int m;

int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];

bool cmp(int a, int b) { return strcmp(T + a, T + b) < 0; }

void countingSort(int k) {
    int i, sum, maxi = max(300, n);

    memset(c, 0, sizeof c);

    for (i = 0; i < n; i++) c[i + k < n ? RA[i + k] : 0]++;

    for (i = sum = 0; i < maxi; i++) {
        int t = c[i];
        c[i] = sum; sum += t;
    }

    for (i = 0; i < n; i++) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];

    for (i = 0; i < n; i++)

    SA[i] = tempSA[i];
}

// O(n log n)
void constructSA() {
    int i, k, r;

    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;

    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;

        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;

        for (i = 0; i < n; i++) RA[i] = tempRA[i];

        if (RA[SA[n-1]] == n-1) break;
    }
}

void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;

    for (i = 1; i < n; i++) Phi[SA[i]] = SA[i-1];

    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }

        while (T[i + L] == T[Phi[i] + L]) L++;

        PLCP[i] = L;
        L = max(L-1, 0);
    }

    for (i = 0; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}

// string matching in O(m log n)
ii stringMatching() {
    int lo = 0, hi = n-1, mid = lo;

    while (lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(T + SA[mid], P, m);
        if (res >= 0) hi = mid;
        else lo = mid + 1;
    }

    if (strncmp(T + SA[lo], P, m) != 0) return ii(-1, -1);

    ii ans; ans.first = lo;
    lo = 0; hi = n - 1; mid = lo;

    while (lo < hi) {
        mid = (lo + hi) / 2;
        int res = strncmp(T + SA[mid], P, m);
        if (res > 0) hi = mid;
        else lo = mid + 1;
    }

    if (strncmp(T + SA[hi], P, m) != 0) hi--;

    ans.second = hi;

    return ans;
}

int main() {
    int t;

    scanf ("%d", &t);

    while (t--) {
        scanf ("%s%*c", T);
        n = (int) strlen(T);
        T[n++] = '$';

        constructSA();
        computeLCP();

        int pos = -1, val = 0;
        for (int i = 0; i < n; i++) {
            if (LCP[i] > val) {
                val = LCP[i];
                pos = i;
            }
        }

        if (pos == -1) printf("No repetitions found!\n");
        else {
            char str[MAX_N];
            for (int i = 0; i < LCP[pos]; i++) {
                P[i] = T[SA[pos] + i];
            }

            m = LCP[pos];
            P[LCP[pos]] = 0;

            ii found = stringMatching();

            printf("%s %d\n", P, abs(found.second - found.first) + 1);
        }
    }

    return 0;
}
