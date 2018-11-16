/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 3e5 + 5;
int n; LL ans;

int main () {
    scanf("%d", &n);
    LL ans = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            ans += j / i * 2;
        }
    }
    printf("%lld\n", ans << 1);
    return 0;
}
