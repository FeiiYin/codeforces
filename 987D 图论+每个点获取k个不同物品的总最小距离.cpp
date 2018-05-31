/*
 * @Samaritan_infi
 */
/// 题意：每个点有一个种类，要求获得 图中每个点获得至少s个种类的物品的最少距离和
/// 注意: 种类数很少只有100，从这里出发
/// 对于每一种物品的种类，bfs每一个点，求得每一个点到该种类的最小距离
/// 然后排序求最小的和， 由于只要求和，所以用nth_element(start, start + n, end)，
/// 这样排序的复杂度降为O(n)

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
const int maxn = 1e5 + 5;

vector<int> edge[maxn];


int dp[maxn][3];
int type[maxn];
int dis[maxn][200];
bool vis[maxn];
queue<int> pq;

void bfs(int st, int n) {
    memset(vis, 0, sizeof vis);
    while(! pq.empty()) pq.pop();
    for(int i = 1; i <= n; i ++) {
        if(type[i] == st) {
            vis[i] = true;
            pq.push(i);
            dis[i][st] = 0;
        }
    }

    while(! pq.empty()) {
        int x = pq.front();
        pq.pop();
        for(int to : edge[x]) {
            if(! vis[to]) {
                pq.push(to);
                vis[to] = true;
                dis[to][st] = dis[x][st] + 1;
            }
        }
    }
}

int main() {
    int n = read(), m = read(), k = read(), s = read();
    for(int i = 1; i <= n; i ++) type[i] = read();
    int l, r;
    while(m --) {
        l = read(), r = read();
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    for(int i = 1; i <= k; i ++) {
        bfs(i, n);
    }
    for(int i = 1; i <= n; i ++) {
        nth_element(dis[i] + 1, dis[i] + s ,dis[i] + 1 + k);
        int ans = 0;
        for(int j = 1; j <= s; j ++) ans += dis[i][j];
        printf("%d ", ans);
    }
    puts("");
    return 0;
}
