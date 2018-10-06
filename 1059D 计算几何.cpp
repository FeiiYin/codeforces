/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 5;
double x[N], y[N];

bool check(long double k, int n) {
    long double l = -100000000000000000.0, r = 100000000000000000.0, t;
    for (int i = 1; i <= n; ++i) {
        if(y[i] > k * 2)
            return 0;
        t = sqrt(k * k - (k - y[i])*(k - y[i]));//计算圆心最远的位置
        if(l < x[i] - t) l = x[i] - t;
        if(r > x[i] + t) r = x[i] + t;
    }
    return l < r; //所有圆心区间必须有交点
}
int main() {
    int n; scanf("%d", &n);
    int positive = 0, nagative = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%lf %lf", &x[i], &y[i]);
        if (y[i] > 0)   positive++;
        else            nagative++;
    }
    if (positive * nagative > 0) {
        puts("-1");
        return 0;
    }
    if (nagative > 0)
        for (int i = 1; i <= n; ++i)
            y[i] = -y[i];

    long double l = 0, r = 100000000000000000.0, mid;
    for (int i = 1; i <= 100; ++i) {
        mid = (l + r) / 2;
        if(check(mid, n))   r = mid;
        else                l = mid;
    }
    printf("%.10Lf", mid); // long double 输出 %Lf
    return 0;
}
