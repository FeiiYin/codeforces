/*
 * @Samaritan_infi
 */
/// 题意: 超大约瑟夫环问题(min(m, k) < 2e6)
/// 题解: 分k=1，m小和k小的情况讨论
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 5;
int moni[N];

int main () {
    LL n, k;
    scanf("%lld %lld", &n, &k);
    if (k > (LL)1e8) {
        printf("-1\n");
        return 0;
    }
    LL b = n / (k * (k + 1) / 2);
    if (b == 0)
    {
        printf("-1\n");
        return 0;
    }
    LL r = 1;
    for (LL x = 1; x * x <= n; x++)
    {
        if (n % x) continue;
        if (x <= b && x > r) r = x;
        if (n / x <= b && n / x > r) r = n / x;
    }
    for (int i = 1; i < k; i++)
        printf("%lld ", r * i);
    n -= r * k * (k - 1) / 2;
    printf("%lld\n", n);

    return 0;
}
