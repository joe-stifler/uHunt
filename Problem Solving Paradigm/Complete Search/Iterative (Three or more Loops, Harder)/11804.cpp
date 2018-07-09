/*------------------------------------------------*/
// Uva Problem No: 11804
// Problem Name: Argentina
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-07 05:26:10
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct abilit {
    int at, de;
    string str;
    abilit() {}
    abilit(int _at, int _de) {
        at = _at;
        de = _de;
    }

    abilit(string _str, int _at, int _de) {
        at = _at;
        de = _de;
        str = _str;
    }
};

int main() {
    int t;
    scanf("%d", &t);

    for (int test = 1; test <= t; test++) {
        string str;
        int at, de;
        char c = 41;
        abilit as[10];
        map<string, abilit> plays;
        for (int i = 0; i < 10; i++) {
            cin >> str >> at >> de;
            str.push_back(c++);
            plays[str] = abilit(at, de);
        }

        int p = 0;
        for (auto it = plays.begin(); it != plays.end(); it++)
            as[p++] = abilit(it->first, it->second.at, it->second.de);

        for (auto i0 = plays.begin(); i0 != plays.end(); i0++) {
            for (auto i1 = i0; i1 != plays.end(); i1++) {
                if (i1 == i0) continue;
                for (auto i2 = i1; i2 != plays.end(); i2++) {
                    if (i2 == i1) continue;
                    for (auto i3 = i2; i3 != plays.end(); i3++) {
                        if (i3 == i2) continue;
                        for (auto i4 = i3; i4 != plays.end(); i4++) {
                            if (i4 == i3) continue;
                            abilit aux[5];
                            int pos = 0;
                            for (auto i5 = plays.begin(); i5 != plays.end(); i5++) {
                                if (i5 != i0 && i5 != i1 && i5 != i2 && i5 != i3 && i5 != i4)
                                    aux[pos++] = abilit(i5->first, i5->second.at, i5->second.de);
                            }

                            if (i0->second.at + i1->second.at + i2->second.at + i3->second.at + i4->second.at >
                                as[0].at + as[1].at + as[2].at + as[3].at + as[4].at) {
                                as[0] = abilit(i0->first, i0->second.at, i0->second.de);
                                as[1] = abilit(i1->first, i1->second.at, i1->second.de);
                                as[2] = abilit(i2->first, i2->second.at, i2->second.de);
                                as[3] = abilit(i3->first, i3->second.at, i3->second.de);
                                as[4] = abilit(i4->first, i4->second.at, i4->second.de);
                                as[5] = aux[0];
                                as[6] = aux[1];
                                as[7] = aux[2];
                                as[8] = aux[3];
                                as[9] = aux[4];
                            } else if (i0->second.at + i1->second.at + i2->second.at + i3->second.at + i4->second.at ==
                                as[0].at + as[1].at + as[2].at + as[3].at + as[4].at) {
                                    if (aux[0].de + aux[1].de + aux[2].de + aux[3].de + aux[4].de >
                                        as[5].de + as[6].de + as[7].de + as[8].de + as[9].de) {
                                            as[0] = abilit(i0->first, i0->second.at, i0->second.de);
                                            as[1] = abilit(i1->first, i1->second.at, i1->second.de);
                                            as[2] = abilit(i2->first, i2->second.at, i2->second.de);
                                            as[3] = abilit(i3->first, i3->second.at, i3->second.de);
                                            as[4] = abilit(i4->first, i4->second.at, i4->second.de);
                                            as[5] = aux[0];
                                            as[6] = aux[1];
                                            as[7] = aux[2];
                                            as[8] = aux[3];
                                            as[9] = aux[4];
                                        }
                                }
                        }
                    }
                }
            }
        }

        printf("Case %d:\n", test);
        printf("(");
        for(int i = 0; i < 5; i++) {
            if (i != 0) cout << ", ";
            str = as[i].str;
            str.erase(str.end()-1);
            cout << str;
        }
        printf(")\n");
        printf("(");
        for(int i = 5; i < 10; i++) {
            if (i != 5) cout << ", ";
            str = as[i].str;
            str.erase(str.end()-1);
            cout << str;
        }
        printf(")\n");
    }

    return 0;
}
