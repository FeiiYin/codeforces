/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 3e5 + 5;
vector <int> edge[N];

int siz[N], dep[N];
void dfs (int now, int par, int k) {
    siz[now] = 1;
    dep[now] = k;
    k ^= 1;
    for (int son : edge[now]) if (son != par) {
        dfs(son, now, k);
        siz[now] += siz[son];
    }
}

int main () {
    int n; scanf("%d", &n);
    int l, r;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &l, &r);
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    dfs(1, 0, 0);
    LL ans = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        ans += 1LL * (n - siz[i]) * siz[i];
        sum += dep[i];
    }
    ans += sum * (n - sum); /// 加上奇数层和偶数层的组合
    printf("%lld\n", ans >> 1);
    return 0;
}
