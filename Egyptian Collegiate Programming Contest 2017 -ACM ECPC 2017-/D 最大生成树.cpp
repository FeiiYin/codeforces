/*
 * @Samaritan_infi
 */
/// 有n个数（小于1e5）每一条边的权值是两个数的gcd，建立一棵树，使权值最大
/// 即求最大生成树，主义预处理
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 1e5 + 5;
vector<int> factor[N];

int par[N];
int find_par (int x) {
    if (par[x] == -1) return x;
    return par[x] = find_par(par[x]);
}

bool unite (int x, int y) {
    int a = find_par(x), b = find_par(y);
    if (a == b) return false;
    par[a] = b;
    return true;
}

int main() {
    freopen("dream.in", "r", stdin);
    int kase, _ = 1; scanf("%d", &kase);
    while (kase--) {
        int max_num = 0;
        int n, x, y; scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            max_num = max(max_num, x);
            for (int j = 1; j <= sqrt(x); ++j) {
                if (!(x % j)) {
                    factor[j].push_back(i);
                    if (x / j != j)
                        factor[x / j].push_back(i);
                }
            }
        }
        memset(par, -1, sizeof (int) * (n + 2));
        LL ans = 0;
        for (int i = max_num; i >= 1; --i) {
            if (factor[i].empty()) continue;
            for (int j = 0; j < factor[i].size() - 1; j++) {
                if (unite(factor[i][j], factor[i][j+1])) {
                    ans += i;
                }
            }
        }
        printf("Case %d: %d\n", _++, ans);
        for (int i = 1; i <= max_num; ++i) factor[i].clear();
    }
    return 0;
}
