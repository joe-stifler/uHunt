/*------------------------------------------------*/
// Uva Problem No: 10670
// Problem Name: Work Reduction
// Type: Involving Sorting (Greedy)
// Autor: Joe Stifler
// Data: 2018-06-17 02:03:59
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct dat {
    int val;
    string nome;
    dat(){}
    dat(int _val, char *_nome, int size) {
        val = _val;

        nome = string(_nome, _nome + size);
    }

    bool operator < (const dat &other) const {
        return val < other.val || (val == other.val && nome < other.nome);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        int n, m, l;
        scanf("%d %d %d%*c", &n, &m, &l);

        int a, b;
        char nome[20];
        vector<dat> res;
        while(l--) {
            int pos = -1;
            do scanf("%c", &nome[++pos]);
            while(nome[pos] != ':');
            nome[pos] = 0;

            scanf("%d,%d%*c", &a, &b);

            int val = 0;
            int total = n;
            while(total > m) {
                if (total / 2 >= m) {
                    if (b <= a * (total - total / 2)) {
                        val += b;
                    } else val += a * (total - total / 2);

                    total /= 2;
                } else {
                    val += a * (total - m);
                    total -= m;
                }
            }

            res.emplace_back(val, nome, pos);
        }

        sort(res.begin(), res.end());

        printf("Case %d\n", test);
        for (int i = 0; i < res.size(); i++) cout << res[i].nome << " " << res[i].val << endl;
    }
    return 0;
}
