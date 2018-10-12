/*
 * @Samaritan_infi
 */
/// 题意：求区间恰好被覆盖ｋ次的数量
/// 题解: 类似查分数组，排序即可
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 4e5 + 5;
#define PII pair<LL, LL>
PII arr[N];
LL ans[N];
int main () {
    int n; LL x, y; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        arr[i << 1] = {x, 1};
        arr[i << 1|1] = {y + 1, -1};
    }
    sort (arr, arr + n * 2);
    x = 0;
    for (int i = 1; i < n * 2; ++i) {
        x += arr[i - 1].second;
        ans[x] += arr[i].first - arr[i - 1].first;
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ans[i]);
    return 0;
}
