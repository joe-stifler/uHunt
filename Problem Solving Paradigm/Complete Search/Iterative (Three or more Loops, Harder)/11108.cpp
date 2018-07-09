/*------------------------------------------------*/
// Uva Problem No: 11108
// Problem Name: Tautology
// Type: Iterative (Three or More Nested Loops, Harder) (Complete Search)
// Autor: Joe Stifler
// Data: 2018-01-20 04:55:09
// Runtime: 0.000s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while(cin >> str) {
        if (str.size() == 1 && str[0] == '0') return 0;
        // cout << "here: " << str << endl;
        bool status = true;
        for (int p = 0; p <= 1 && status; p++)
            for (int q = 0; q <= 1 && status; q++)
                for (int r = 0; r <= 1 && status; r++)
                    for (int s = 0; s <= 1 && status; s++)
                        for (int t = 0; t <= 1 && status; t++) {
                            vector<char> aux1;
                            for (int pos = 0; pos < (int) str.size(); pos++) {
                                switch(str[pos]) {
                                    case 'p':
                                        aux1.push_back(p);
                                        break;
                                    case 'q':
                                        aux1.push_back(q);
                                        break;
                                    case 'r':
                                        aux1.push_back(r);
                                        break;
                                    case 's':
                                        aux1.push_back(s);
                                        break;
                                    case 't':
                                        aux1.push_back(t);
                                        break;
                                    default:
                                        aux1.push_back(str[pos]);
                                }
                            }

                            while(aux1.size() > 1 && status) {
                                vector<char> aux2;
                                for (int pos = 0; pos < (int) aux1.size() && status; pos++) {
                                    switch(aux1[pos]) {
                                        case 'K':
                                            if ((aux1[pos + 1] == 0 || aux1[pos + 1] == 1) &&
                                                    (aux1[pos + 2] == 0 || aux1[pos + 2] == 1)) {
                                                aux2.push_back(aux1[pos+1] & aux1[pos + 2]);
                                                pos += 2;
                                            } else {
                                                aux2.push_back(aux1[pos]);
                                                if (aux1[pos + 1] == 0 || aux1[pos + 1] == 1) {
                                                    aux2.push_back(aux1[pos + 1]);
                                                    pos++;
                                                }
                                            }
                                            break;
                                        case 'A':
                                            if ((aux1[pos + 1] == 0 || aux1[pos + 1] == 1) &&
                                                    (aux1[pos + 2] == 0 || aux1[pos + 2] == 1)) {
                                                aux2.push_back(aux1[pos+1] || aux1[pos + 2]);
                                                pos += 2;
                                            } else {
                                                aux2.push_back(aux1[pos]);
                                                if (aux1[pos + 1] == 0 || aux1[pos + 1] == 1) {
                                                    aux2.push_back(aux1[pos + 1]);
                                                    pos++;
                                                }
                                            }
                                            break;
                                        case 'N':
                                            if ((aux1[pos + 1] == 0 || aux1[pos + 1] == 1)) {
                                                aux2.push_back(!aux1[pos + 1]);
                                                pos++;
                                            } else aux2.push_back(aux1[pos]);
                                            break;
                                        case 'C':
                                            if ((aux1[pos + 1] == 0 || aux1[pos + 1] == 1) &&
                                                    (aux1[pos + 2] == 0 || aux1[pos + 2] == 1)) {
                                                aux2.push_back(!aux1[pos+1] || aux1[pos + 2]);
                                                pos += 2;
                                            } else {
                                                aux2.push_back(aux1[pos]);
                                                if (aux1[pos + 1] == 0 || aux1[pos + 1] == 1) {
                                                    aux2.push_back(aux1[pos + 1]);
                                                    pos++;
                                                }
                                            }
                                            break;
                                        case 'E':
                                            if ((aux1[pos + 1] == 0 || aux1[pos + 1] == 1) &&
                                                    (aux1[pos + 2] == 0 || aux1[pos + 2] == 1)) {
                                                aux2.push_back(aux1[pos+1] == aux1[pos + 2]);
                                                pos += 2;
                                            } else {
                                                aux2.push_back(aux1[pos]);
                                                if (aux1[pos + 1] == 0 || aux1[pos + 1] == 1) {
                                                    aux2.push_back(aux1[pos + 1]);
                                                    pos++;
                                                }
                                            }
                                            break;
                                        default:
                                            aux2.push_back(aux1[pos]);
                                    }
                            }

                            aux1 = vector<char>(aux2.begin(), aux2.end());
                            // cout << "vec: " << aux1.size() << endl;
                            // for (int pos = 0; pos < (int) aux1.size(); pos++) {
                            //     if (aux1[pos] == 0) printf("0");
                            //     else if (aux1[pos] == 1) printf("1");
                            //     else printf("%c", aux1[pos]);
                            // }
                            // printf("\n");
                        }

                        if (aux1[0] == 0) {
                            status = false;
                            // printf("p: %d e q: %d\n", p, q);
                        }
                    }

            if (status) printf("tautology\n");
            else printf("not\n");
    }
}
