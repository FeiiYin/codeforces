/*
 * @Samaritan_infi
 */
/// 题解 : http://codeforces.com/blog/entry/59202
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define f first
#define s second

typedef pair<long double, long double> point;

const long double PI = acosl(-1);

point arr[200009];
long double dist[200009], ang[200009];

point get_centroid(int n) {
    long double area = 0.0, tmp;
    point a, b, res = point(0, 0);
    for (int i = 0; i < n; i++) {
        a = arr[i], b = arr[(i + 1) % n];
        tmp = a.f * b.s - b.f * a.s;
        area += tmp;
        res.f += (a.f + b.f) * tmp;
        res.s += (a.s + b.s) * tmp;
    }
    area *= 0.5;
    res.f /= (area * 6);
    res.s /= (area * 6);
    return res;
}

point get(int ind, const point &centroid, const double &angle) {
    point ans;
    ans.f = centroid.f + dist[ind] * cosl(angle + ang[ind]);
    ans.s = centroid.s + dist[ind] * sinl(angle + ang[ind]);
    return ans;
}

long double get_dist(const point &a, const point &b) {
    return sqrtl((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

int main() {
    int n, q;
    double a, b;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &a, &b);
        arr[i] = point(a, b);
    }
    long double zbx=arr[0].first,zby=arr[0].second;
    for(int i=0; i < n; i++) {
        arr[i].first-=zbx;
        arr[i].second-=zby;
    }
    int i = 0, j = 1, c, x, y;
    point centroid = get_centroid(n), top, nxt;
    long double angle = 0;
    for (int i = 0; i < n; i++) {
        dist[i] = get_dist(arr[i], centroid);
        ang[i] = atan2l(arr[i].s - centroid.s, arr[i].f - centroid.f);
        if (ang[i] < 0)
            ang[i] += 2 * PI;
    }
    while (q--) {
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d %d", &x, &y);
            x --, y --;
            if (x == i) {
                i = y;
                top = get(j, centroid, angle);
                nxt = point(top.f, top.s - dist[j]);
            } else {
                j = y;
                top = get(i, centroid, angle);
                nxt = point(top.f, top.s - dist[i]);
            }
            angle += -PI / 2 - atan2l(centroid.s - top.s, centroid.f - top.f);
            while (angle < 0)
                angle += 2 * PI;
            while (angle > 2 * PI)
                angle -= 2 * PI;
            centroid = nxt;
        } else {
            scanf("%d", &x);
            top = get(x - 1, centroid, angle);
            printf("%.10f %.10f\n", (double) (top.f+zbx), (double) (top.s+zby));
        }
    }
    return 0;
}
