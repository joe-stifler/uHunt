/*------------------------------------------------*/
// Uva Problem No: 1254
// Problem Name: Top 10
// Type: Suffix Trie, Tree, Array (String Processing)
// Autor: Joe Stifler
// Data: 2017-10-16 03:04:42
// Runtime: 16.960s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000100

typedef pair<int, int> ii;

int n;
int c[MAX_N];
char T[MAX_N];
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];

int m;
char P[MAX_N];

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

int t;
int pos[MAX_N];
int pos2[MAX_N];

int main() {
    scanf ("%d", &t);

    n = 0;
    string str;

    int tam[t+1];
    memset(tam, 0, sizeof tam);

    for (int j = 0; j < t; j++, n++) {
        cin >> str;

        str.append(1u, '$');

        pos2[j] = n;
        tam[j] = str.size();
        // T[n++] = '$';

        for (int i = 0; i < str.size(); i++, n++) {
            T[n] = str[i];
            pos[n] = j;
        }
    }

    constructSA();
    computeLCP();

    int v;
    scanf ("%d", &v);

    while (v--) {
        cin >> str;

        m = 0;
        for (int i = 0; i < str.size(); i++, m++) P[m] = str[i];

        bool visit[t+1];
        ii posit = stringMatching();
        if (posit.first != -1 && posit.second != -1) {
            map<int, map<string, set<int>>> mapa;

            int t = 0;
            memset(visit, false, sizeof visit);

            for (int i = posit.first; i <= posit.second; i++) {
                if (visit[pos[SA[i]]] == false) {
                    str = "";
                    for (int j = pos2[pos[SA[i]]]; j < pos2[pos[SA[i]]] + tam[pos[SA[i]]]; j++) str.append(1u, T[j]);

                    mapa[tam[pos[SA[i]]]][str].insert(pos[SA[i]]);
                    visit[pos[SA[i]]] = true;
                }
            }

            int cont = 0;
            for (auto it = mapa.begin(); it != mapa.end() && cont < 10; it++) {
                for (auto it2 = it->second.begin(); it2 != it->second.end() && cont < 10; it2++) {
                    for (auto it3 = it2->second.begin(); it3 != it2->second.end() && cont < 10; it3++) {
                        if (cont != 0) printf(" ");
                        printf("%d", *it3 + 1);
                        cont++;
                    }
                }
            }

            printf("\n");
        } else printf("-1\n");
    }
}
