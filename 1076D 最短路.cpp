/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 3e5 + 5;
#define INF 1000000000000000005

struct qnode{
    LL v; LL c ;
    qnode(LL tempv = 0, LL tempc = 0) : v(tempv),c(tempc) {}
    bool operator < (const qnode &r) const{
        return c > r.c ;
    }
};

struct Edge{
    LL start; LL cost;
    int id;
    Edge () {}
    Edge(LL tempstart, LL tempcost, int _id) : start(tempstart),cost(tempcost), id(_id){}
};

int deg[N], pre[N];
vector <Edge> E[N];
inline void add_edge(LL u, LL v, LL w, int id){
    E[u].push_back(Edge(v, w, id));
    E[v].push_back(Edge(u, w, id));
}
bool vis[N];
LL dist[N];

void dij (LL tot) {
    LL start = 1;
    memset(vis, 0, sizeof(vis[0]) * (tot + 3));
    for(LL i = 0 ; i <= tot; i ++ ) dist[i] = INF ;
    priority_queue <qnode> pq ;
    while(! pq.empty())  pq.pop(); // reset
    dist[start] = 0;
    pq.push(qnode(start, 0LL));
    qnode tmp;

    while (! pq.empty()) {
        tmp = pq.top();
        pq.pop();
        LL u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(LL i = 0; i < E[u].size(); i ++) {
            LL v = E[u][i].start;
            LL cost = E[u][i].cost;
            if (! vis[v] ) {
                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    pq.push(qnode(v, dist[v]));
                    deg[ E[u][i].id ]++;
                    if (pre[v]) deg[ pre[v] ]--;
                    pre[v] = E[u][i].id;
                }
            }
        }
    }
}

bool cmp (int i, int j) {
    return deg[i] > deg[j];
}
vector <pair<LL, int>> ans;
int main () {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    int u, v, w;
    memset(deg, 0, sizeof (deg[0]) * (m + 3));
    memset(pre, 0, sizeof (pre[0]) * (m + 3));
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w, i);
    }
    dij(n);
//    for (int i = 1; i <= m; ++i) printf("%d ", dist[i]); puts("");
//    for (int i = 1; i <= m; ++i) printf("%d ", pre[i]); puts("");
//    for (int i = 1; i <= m; ++i) printf("%d ", deg[i]); puts("");
    ans.resize(n - 1);
    for (int i = 2; i <= n; ++i) ans[i - 2] = make_pair(dist[i], pre[i]);
    sort (ans.begin(), ans.end());

    k = min(k, n - 1);
    printf("%d\n", k);
    for (int i = 0; i < k; ++i) printf("%d ", ans[i].second); puts("");
    return 0;
}
