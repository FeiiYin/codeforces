/*
 * @Samaritan_infi
 */
/// 是将x 与 (2^t - 1) ^ x 的所有子集建边，但是其实连过的子集，就不用再链接边了
/// 不过如果枚举到子集 中 等于 集合中的元素， 需要再次DFS，不然他能链接到的元素就添加不到里面了。

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
const int maxn = 5e6 + 5;

int c[300];
void init() {
    c[0] = 1;
    for(int i = 1; i <= 22; i ++)
        c[i] = c[i - 1] << 1;
}
int a[maxn];
bool vis[maxn], is[maxn];
int max_c, all;
void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;

    if(is[x]) dfs(all ^ x);

    for(int i = 0; i <= max_c; i ++) {
        if(c[i] & x) dfs(x ^ c[i]);
    }
}

int main() {
    init();
    max_c = read(), all = c[max_c] - 1;
    int n = read();
    for(int i = 0; i < n; i ++) {
        a[i] = read();
        is[ a[i] ] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(vis[ a[i] ]) continue;
        ans ++;
        vis[ a[i] ] = true;
        dfs(all ^ a[i]);
    }
    printf("%d\n", ans);
    return 0;
}
