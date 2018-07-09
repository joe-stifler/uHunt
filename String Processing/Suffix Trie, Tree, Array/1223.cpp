/*------------------------------------------------*/
// Uva Problem No: 1223
// Problem Name: Editor
// Type: Suffix Trie, Tree, Array (String Processing)
// Autor: Joe Stifler
// Data: 2017-10-06 07:55:13
// Runtime: 0.030s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define F first
#define S second
#define pb push
#define mp make_pair
#define MAX_N 1000100

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

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        scanf("%*c%s", T);
        n = strlen(T);
        T[n++] = '.';


        constructSA();
        computeLCP();

        int maior = 0;
        for (int i = 0; i < n; i++) maior = max(maior, LCP[i]);

        printf("%d\n", maior);
    }

    return 0;
}
