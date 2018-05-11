/*
 * @Samaritan_infi
 */
/// 求取一颗树上，找到一个大小为（n - k）的子图，使权值最大
/// 每一个节点的权值为(2^i)
/// 从最大的节点贪心，然后往下，如果可以取，
/// 就将该节点以及它到子图的璐径添加进入子图
/// 求得时候，维护每个节点的20个祖先
/// 可以快速找到第一个已经被添加到子图的祖先
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
const int maxn = 1e6 + 5;

vector<int> edge[maxn];
bool vis[maxn];
int par[20][maxn], deep[maxn];
void dfs(int now, int pre, int dep) {
    par[0][now] = pre;
    deep[now] = dep;
    for(int son : edge[now]) {
        if(son == pre) continue;
        dfs(son, now, dep + 1);
    }
}

int main() {
    int n = read(), k = read();
    int l, r;
    for(int i = 1; i < n; i ++) {
        l = read(), r = read();
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    dfs(n, n, 0);
    for(int j = 1; j < 20; j ++) {
        for(int i = 1; i <= n; i ++) 
            par[j][i] = par[j - 1][ par[j - 1][i] ];
    }
//    for(int i = 1; i <= n; i ++) {
//        for(int j = 0; j <20; j ++)
//            cout <<par[j][i] <<" "; cout <<endl;
//    }
    k = n - k;
    /// 2^n = 2^(n-1) + ... + 2^0 + 1 
    /// 所以如果当前最大的能取，一定取
    vis[n] = true;
    k --;
    for(int i = n - 1; i >= 1 && k > 0; i --) {
        if(vis[i]) continue;
        int cur = i;
        for(int j = 19; j >= 0; j --) 
            /// 找到第一个已经添加到子图里的祖先
            if(! vis[ par[j][cur] ])
                cur = par[j][cur];
        /// 将当前节点以及它到子图的路径全部添加进去
        /// 如果总点数小于等于k的话
        if(deep[i] - deep[cur] + 1 <= k) {
            cur = i;
            while(! vis[cur]) {
                vis[cur] = true;
                k --;
                cur = par[0][cur];
            }
        }
    }
    for(int i = 1; i <= n; i ++)
        if(! vis[i])
            printf("%d ", i);
    puts("");
    return 0;
}
