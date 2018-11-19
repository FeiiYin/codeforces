  /*
 * @Samaritan_infi
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 5;
const int M = 1e8 + 5;

struct node {
    int jump, weight, height;
    node () {}
    node (int a, int b, int c) : jump(a), weight(b), height(c) {}
    bool operator < (const node & k) const {
        return weight > k.weight;
    }
};

node arr[N];
int dp[M]; /// dp[ hold weight ] = max height

int main () {
    int n, tot;
    while (~ scanf("%d %d", &n, &tot)) {
        int l, w, h;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &l, &w, &h);
            arr[i] = node(l, w, h);
        }
        memset(dp, 0, sizeof dp);
        sort (arr, arr + n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            w = arr[i].weight;
            if (dp[w] + arr[i].jump > tot) ans++;
            int limit = min(2 * w, M);
            /// update max
            /// 因为dp递减， w >= 2*wi时, 不用再更新
            for (int j = w+1; j < limit; ++j)
                dp[j-w] = max(dp[j-w], dp[j] + arr[i].height);
        }
        printf("%d\n", ans);
    }
    return 0;
}
