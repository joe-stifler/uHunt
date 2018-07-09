/*------------------------------------------------*/
// Uva Problem No: 10474
// Problem Name: Where is the Marble?
// Type: Binary Search (Divide and Conquer)
// Autor: Joe Stifler
// Data: 2018-01-28 19:06:15
// Runtime: 0.120s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct Par {
    int key;
    int pos;
    Par() {}
    Par(int _key, int _pos) : key(_key), pos(_pos) {}

    bool operator <(const Par &other) const {
        return key < other.key || (key == other.key && pos < other.pos);
    }
};

Par res;
void binarySearch(vector<Par> &vec, int left, int right, int val) {
    int mid = (right + left) / 2;

    if (vec[mid].key == val) {
        while(mid > 0 && vec[mid - 1].key == val) mid--;
        res = vec[mid];
        res.pos = mid + 1;
        return;
    }

    if (left >= right) return;

    if (vec[mid].key > val) binarySearch(vec, left, mid, val);
    else binarySearch(vec, mid + 1, right, val);
}

int main() {
    int test = 1;
    while(true) {
        int n, q;
        scanf("%d %d", &n, &q);

        if (n == 0 && q == 0) return 0;

        int val;
        vector<Par> vec;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &val);
            vec.push_back(Par(val, i));
        }

        sort(vec.begin(), vec.end());

        printf("CASE# %d:\n", test);
        while(q--) {
            scanf("%d", &val);

            res.key = -1;
            binarySearch(vec, 0, vec.size()-1, val);

            if (res.key == -1) printf("%d not found\n", val);
            else printf("%d found at %d\n", res.key, res.pos);
        }
        test++;
    }

}
