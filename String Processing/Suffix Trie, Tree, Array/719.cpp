/*------------------------------------------------*/
// Uva Problem No: 719
// Problem Name: Glass Beads
// Type: Suffix Trie, Tree, Array (String Processing)
// Autor: Joe Stifler
// Data: 2017-10-06 07:38:30
// Runtime: 1.130s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

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
        string str;

        scanf("%*c%s", T);
        n = strlen(T);

        for (int i = 0; i < n; i++) T[n+i] = T[i];

        T[2 * n] = '$';
        n = 2 * n;

        constructSA();
        computeLCP();

        // for (int i = 0; i < n; i++) {
        //     printf("%d -> SA = %d -- string: ", i, SA[i]);
        //     // printf("%d:%d:", LCP[i], owner(i, pos));
        //     for (int j = SA[i]; j < n; j++) printf("%c", T[j]);
        //     printf("\n");
        // }

        int k = n / 2, minimo;
        for (int i = 0; i < n; i++) {
            if (abs(n - SA[i]) >= k) {
                bool valid = true;
                minimo = SA[i];
                while (i < n && LCP[i+1] >= k) {
                    minimo = min(minimo, SA[i + 1]);
                    i++;
                }

                break;
            }
        }

        printf("%d\n", minimo+1, k);
    }
}
