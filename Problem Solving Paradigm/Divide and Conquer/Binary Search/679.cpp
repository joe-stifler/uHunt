/*------------------------------------------------*/
// Uva Problem No: 679
// Problem Name: Dropping Balls
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-28 20:04:39
// Runtime: 0.220s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int left(int index) {
    return 2 * index + 1;
}

int right(int index) {
    return 2 * index + 2;
}

int add(bool *tree, int levels, int cont, int index) {
    if (cont == levels) return index;

    if (tree[index] == false) {
        tree[index] = true;
        return add(tree, levels, cont + 1, left(index));
    } else {
        tree[index] = false;
        return add(tree, levels, cont + 1, right(index));
    }
}

int main() {
    int t;
    scanf("%d", &t);

    int nodes = pow(2, 21);
    int *last = (int *) malloc(sizeof(int) * nodes);
    bool *tree = (bool *) malloc(sizeof(bool) * nodes);

    memset(tree, false, sizeof(bool) * nodes);

    int levels = 0, adds = 1;
    while(adds < nodes) {
        last[adds] = add(tree, levels, 0, 0);
        levels = log2(adds);
        adds++;
    }

    while(t--) {
        scanf("%d %d", &levels, &adds);
        printf("%d\n", last[(int) pow(2, levels - 1) + adds] + 1);
    }

    free(tree);

    return 0;
}
