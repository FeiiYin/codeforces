/*
 * @Samaritan_infi
 */
/// 嗯  这个二分图 用 网络流   嗯  我很菜
/// 建图：求k度覆盖 (k的上限是p =  min(deg [i]))
/// 源点向每一个左半边点连边   cap = deg[i] - k
/// 每一条二分图的边改为单向， cap = 1
/// 每一条右半边点向汇点连边   cap = deg[i] - k
/// 答案为 所有非满流的边
/// 题目求 所有的k度覆盖
/// 我们让 k 从 (p to 0) 遍历
/// 每一次给两边的边 的cap 加一， 再跑一遍网络流， 将答案存储
/// 时间复杂度为 O((n + m)2)

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

const int maxn = 4100, maxm = 3e4 + 5;
const int inf = 2147483640;

struct Edge {
    int v, next, u, cap;
    int type, pos;
}edge[maxm];
int k, head[maxn], dist[maxn], que[maxn], n, m, st, ed, current[maxn];

void init() {
    memset(head, -1, sizeof head);
    k = -1; /// very important cannot change
}

void add_edge(int u, int v, int cap, int edge_pos) {
    edge[++k].u = u;
    edge[k].v = v;
    edge[k].cap = cap;
    edge[k].next = head[u];
    edge[k].type = 1;
    edge[k].pos = edge_pos;
    head[u] = k;
    edge[++k].u = v;
    edge[k].v = u;
    edge[k].cap = 0;
    edge[k].next = head[v];
    edge[k].type = 0;
    head[v] = k;
}
bool bfs() {
    int fro, top;
    memset(dist, 0, sizeof(dist));
    dist[st] = 1;
    fro = top =1;
    que[fro] = st;
    while(fro <= top)
    {
        int p = que[fro++];
        for(int kk = head[p]; ~kk; kk = edge[kk].next)
        {
            int v = edge[kk].v, cap = edge[kk].cap;
            if(cap && !dist[v])
            {
                dist[v] = dist[p] + 1;
                que[++top] = v;
                if(v == ed) return 1;
            }
        }
    }
    return 0;
}
int dfs(int u, int maxflow) {
    if(u == ed || maxflow == 0) return maxflow;
    int t = 0;
    for(int& kk = current[u]; ~kk; kk = edge[kk].next)
    {
        int v =  edge[kk].v, cap = edge[kk].cap;
        if(cap && dist[v] ==  dist[u] + 1)
        {
            int f = dfs(v, min(cap, maxflow - t));
            t += f;
            edge[kk].cap -= f;
            edge[kk ^ 1].cap += f;
            if(t == maxflow) return t;
        }
    }
    if(t == 0) dist[u] = -1;
    return t;
}
ll dinic() {
    ll maxnflow = 0, t;
    while(bfs()) {
        for(int i = 0; i <= ed; ++i) current[i] = head[i];
        while(t = dfs(st, inf))
            maxnflow += t;
    }
    return maxnflow;
}

int deg[maxn];
int ans[2050][2050];
int num[2050];
int main() {
    int n = read(), m = read(), k = read();
    init();
    st = 0, ed = 1 + n + m;
    memset(deg, 0, sizeof deg);
    memset(num, 0, sizeof num);
    int l, r;
    for(int i = 1; i <= k; i ++) {
        l = read(), r = read() + n;
        add_edge(l, r, 1, i);
        deg[l] ++; deg[r] ++;
    }
    k = 1e9;
    for(int i = 1; i <= m + n; i ++) k = min(deg[i], k);
    for(int i = 1; i <= n; i ++) add_edge(st, i, deg[i] - k, 0);
    for(int i = 1 + n; i <= n + m; i ++) add_edge(i, ed, deg[i] - k, 0);


    //cout << endl;
    for(int t = k; t >= 0; t --) {
        int max_flow = dinic();
        int x = 0;
        for(int j = 1; j <= n; j ++) {
            for(int i = head[j]; ~ i; i = edge[i].next) {
                if(edge[i].type == 1 && edge[i].cap > 0) {
                    ans[t][x ++] = edge[i].pos;
                    //cout << edge[i].u << " " << edge[i].v << " " << edge[i].pos << endl;
                }
            }
        }
        num[t] = x;

        for(int i = head[st]; ~ i; i = edge[i].next) edge[i].cap ++;
        for(int i = head[ed]; ~ i; i = edge[i].next) edge[i ^ 1].cap ++;
    }

    for(int i = 0; i <= k; i ++) {
        printf("%d", num[i]);
        for(int j = 0; j < num[i]; j ++) {
            printf(" %d", ans[i][j]);
        } puts("");
    }
    return 0;
}
