/*------------------------------------------------*/
// Uva Problem No: 11107
// Problem Name: Life Forms
// Type: Suffix Trie, Tree, Array (String Processing)
// Autor: Joe Stifler
// Data: 2017-10-02 01:54:01
// Runtime: 0.540s
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
int owner(int i, int pos[]) {
    for (int j = 1; j <= t; j++)
        if (SA[i] < pos[j]) return j;
}

int main() {
    string a, b;
    int cont = 0;
    while (true) {
        scanf ("%d", &t);

        if (t == 0) return 0;

        n = 0;
        int k = t / 2 + 1, pos[t+1];

        if (cont != 0) printf("\n");

        for (int i = 1; i <= t; i++) {
            cin >> a;

            if (t == 1) cout << a << endl;

            for (int j = 0; j < a.length(); j++, n++) T[n] = a[j] + 5;

            pos[i] = n;
            T[n++] = i-1;
        }

        constructSA();
        computeLCP();

        if (t != 1) {
            int maior = 0, owner1;
            map<int, int> res;
            map<int, int> ativos;

            for (int i = 1, j = 1; i < n; i++) {
                while (ativos.size() < k && j < n) {
                    owner1 = owner(j, pos);
                    if (ativos.find(owner1) == ativos.end()) ativos[owner1] = 1;
                    else ativos[owner1]++;

                    j++;
                }

                if (ativos.size() < k) continue;

                int pMenor = i + 1, menor = LCP[i + 1];
                for (int l = i + 1; l <= j-1; l++) {
                    if (LCP[l] < menor) {
                        menor = LCP[l];
                        pMenor = l;
                    }
                }

                if (menor >= maior && menor > 0) {
                    if (menor > maior) res.clear();

                    bool valid = true;
                    for (auto it = res.begin(); valid && it != res.end(); it++) {
                        bool notfound = true;
                        for (int l = 0, m = 0; notfound && l < it->second && m < menor; l++, m++) {
                            if (T[SA[it->first] + l] != T[SA[pMenor] + m]) notfound = false;
                        }

                        if (notfound) valid = false;
                    }

                    maior = menor;
                    if (valid) res.insert(make_pair(pMenor, menor));
                }

                owner1 = owner(i, pos);

                ativos[owner1]--;
                if (ativos[owner1] == 0) ativos.erase(owner1);
            }

            if (maior == 0) printf("?\n");
            else {
                for (auto it = res.begin(); it != res.end(); it++) {
                    for (int l = 0; l < it->second; l++) printf("%c", T[SA[it->first] + l] - 5);
                    printf("\n");
                }
            }
        }

        cont++;
    }

    return 0;
}
