/*------------------------------------------------*/
// Uva Problem No: 11626
// Problem Name: Convex Hull
// Type: Polygon (Computational Geometry)
// Autor: Joe Stifler
// Data: 2017-11-13 13:33:11
// Runtime: 0.080s
// Universidade: Unicamp
/*------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

struct point {
    double x, y;

    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator <(point &other) {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

double cross(const point &o, const point &a, const point &b) {
        return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> convexHull(vector<point> &pts) {
	int n = pts.size(), k = 0;

	vector<point> convex(2 * n + 1);

	sort(pts.begin(), pts.end());

	// constrói o lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(convex[k-2], convex[k-1], pts[i]) < 0) k--;
		convex[k++] = pts[i];
	}

	// constrói o upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(convex[k-2], convex[k-1], pts[i]) < 0) k--;
		convex[k++] = pts[i];
	}

	convex.resize(k-1);

	return convex;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        double x, y;
        vector<point> poli;
        while (n--) {
            scanf("%lf %lf %*c", &x, &y);
            poli.push_back(point(x, y));
        }

        poli = convexHull(poli);

        printf("%d\n", poli.size());
        for (int i = 0; i < poli.size(); i++)
            printf("%d %d\n", (int)poli[i].x, (int)poli[i].y);

    }

    return 0;
}
