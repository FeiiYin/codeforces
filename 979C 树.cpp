/*
 * @Samaritan_infi
 */

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
const int maxn = 3e5 + 5;

vector<int> edge[maxn];

int son[maxn], a, b;
bool vis[maxn];
void dfs(int x, int pre) {
    if(x == b) vis[x] = true;
    son[x] = 1;
    for(int to : edge[x]) {
        if(to == pre) continue;
        //deep[to] = deep[x] + 1;
        dfs(to, x);
        son[x] += son[to];
        if(vis[to]) vis[x] = true;
    }

}
int main() {
    memset(vis, 0, sizeof vis);
    int n = read();
    a = read(), b = read();
    int l, r;
    for(int i = 1; i < n; i ++) {
        l = read(), r = read();
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    dfs(a, 0);
//    for(int i = 1; i <= n; i ++) cout << son[i] << " " ; cout << endl;
//    for(int i = 1; i <= n; i ++) cout << vis[i] << " " ; cout << endl;
    ll ans = (ll)n * (n - 1);
    ll temp = 1;
    for(int to : edge[a]) {
        if(vis[to]) continue;
        temp += son[to];
    }
    //cout << temp << " " << son[b] << endl;
    ans -= temp * son[b];
    printf("%lld\n", ans);
    return 0;
}
