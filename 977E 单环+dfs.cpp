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

const int maxn = 2e5 + 5;

int deg[maxn];
bool vis[maxn];
vector<int> comp;
vector<int> edge[maxn];

void dfs(int v) {
    vis[v] = true;
    comp.push_back(v);
    for(auto to : edge[v]) {
        if(! vis[to]) dfs(to);
    }
}

int main() {
    int n = read(), m = read();
    for(int i = 0; i < m; i ++) {
        int l = read(), r = read();
        edge[l].push_back(r);
        edge[r].push_back(l);
        deg[l] ++, deg[r] ++;
    }
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(! vis[i]) {
            comp.clear();
            dfs(i);
            bool flag = true;
            for(auto v : comp) flag &= deg[v] == 2;
            if(flag) ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}
