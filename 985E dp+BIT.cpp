/*
 * @Samaritan_infi
 */
/// 题目问 能否将n个值分组，每组至少k个元素，组内极差小于等于d
/// dp，考虑到如果前l个已经能成功分组，并且第l+1到i满足条件，即可更新dp
/// 即看dp在区间（l到i-k+1）区间是否有1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;
int s[maxn];
int dp[maxn];

int tree[maxn];
int low_bit(int x) {return x & -x;}
void add(int pos, int x, const int n) {
    for(; pos <= n; pos += low_bit(pos)) tree[pos] += x;
}
int query(int pos) {
    int ans = 0;
    for(; pos > 0; pos -= low_bit(pos)) ans += tree[pos];
    return ans;
}

int get(int l, int r) {
    if(l > r) return 0;
    return query(r) - query(l - 1);
}

int main() {
    int n, k, d;
    scanf("%d %d %d", &n, &k, &d);
    for(int i = 1; i <= n; i ++) scanf("%d", &s[i]);
    sort(s + 1, s + n + 1);
    memset(dp, 0, sizeof dp);
    dp[1] = 1; add(1, 1, n);
    int l = 1;
//    for(int j = 0; j <= n; j ++) cout << s[j] << " "; cout << endl;
//    for(int j = 0; j <= n; j ++) cout << dp[j] << " "; cout << endl;
    for(int i = 1; i <= n; i ++) {
        while(l < i && s[i] - s[l] > d) l ++;
        dp[i + 1] = (get(l, i - k + 1) >= 1);
//        for(int j = 0; j <= n; j ++) cout << dp[j] << " "; cout << endl;
        if(dp[i + 1]) add(i + 1, 1, n);
    }
    printf("%s\n", dp[n + 1] ? "YES" : "NO");
    return 0;
}
