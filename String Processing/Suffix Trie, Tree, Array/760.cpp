/*------------------------------------------------*/
// Uva Problem No: 760
// Problem Name: DNA Sequencing
// Type: Suffix Trie, Tree, Array (String Processing)
// Autor: Joe Stifler
// Data: 2017-10-01 03:53:47
// Runtime: 0.000s
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
    Phi[SA[0]] = 0;

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

int owner(int i, int pos) {
    return SA[i] < pos ? 1 : 2;
}

int main() {
    string a, b;
    int t = 0;
    while (cin >> a >> b) {
        for (n = 0; n < a.length(); n++) T[n] = a[n] + 10;

        if (t != 0) printf("\n");

        int pos = n;
        T[n++] = 0;

        for (int i = 0; i < b.length(); i++, n++) T[n] = b[i] + 10;

        T[n++] = '.';

        constructSA();
        computeLCP();

        int maior = -1;
        set<string> vals;
        for (int i = 1; i < n; i++) {
            if (owner(i-1, pos) != owner(i, pos)) {
                if (LCP[i] >= maior) {
                    string str = "";

                    for (int j = 0; j < LCP[i]; j++) str.append(1u, T[SA[i] + j] - 10);

                    if (LCP[i] > maior) vals.clear();

                    vals.insert(str);

                    maior = LCP[i];
                }
            }
        }

        if (maior == 0) printf("No common sequence.\n");
        else {
            for (set<string>::iterator it = vals.begin(); it != vals.end(); it++) {
                cout << *it << endl;
            }
        }

        t++;
    }

    return 0;
}
