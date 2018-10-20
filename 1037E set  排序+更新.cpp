/*
 * @Samaritan_infi
 */
/// 题意: 每天加一条边，选的点必须至少ｋ个点也被选，问每天最多选几个点
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
pair<int, int> edge[N];
vector<pair<int, int>> adj[N];
int deg[N] = {0};
int ans[N];
bool vis[N];
set<pair<int, int>> friends;
inline void delete_edge (int v) {
    friends.erase(make_pair(deg[v], v)); deg[v]--;
    friends.insert(make_pair(deg[v], v));
}
/// delete the edge between u and v
void update (int k, int step) {
    while (! friends.empty() && friends.begin()->first < k) {
        int node = friends.begin()->second;
        for (auto temp : adj[node]) {
            if (temp.second >= step) continue;
            if (vis[temp.first]) delete_edge(temp.first);
        }
        friends.erase(make_pair(deg[node], node));
        vis[node] = false;
    }
}
int main () {
    //freopen("in.txt", "r", stdin);
    int n, day, k;
    scanf("%d %d %d", &n, &day, &k);
    int x, y;
    memset(deg, 0, sizeof deg); memset(vis, true, sizeof vis);
    for (int i = 1; i <= day; ++i) {
        scanf("%d %d", &x, &y);
        edge[i] = make_pair(x, y);
        adj[x].push_back(make_pair(y, i)); adj[y].push_back(make_pair(x, i));
        deg[x]++, deg[y]++;
    }
    for (int i = 1; i <= n; ++i)
        friends.insert(make_pair(deg[i], i));
    update(k, day+1);
    for (int i = day; i >= 1; --i) {
        ans[i] = friends.size();
        int u = edge[i].first, v = edge[i].second;
        if (vis[u] && vis[v]) {
            delete_edge(u); delete_edge(v);
            update(k, i);
        }
    }
    for (int i = 1; i <= day; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
