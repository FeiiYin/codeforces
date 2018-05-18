/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

#define pb push_back

const int MXL = 0x3f3f3f3f;
const int mxn = 500006;
using ai = int[mxn];
using avi = vi[mxn];

ai dfn, low, scc; int cnt, scnt;
stack<int,vi> sta; bool ins[mxn];
int tarjan(int x, vi *e) {
        dfn[x] = low[x] = ++cnt;
        sta.push(x); ins[x] = true;
        for (auto i : e[x]) low[x] = min(low[x],
                dfn[i] ? dfn[ins[i] ? i : x] : tarjan(i, e));
        if (low[x] == dfn[x]) {
                ++scnt; int t;
                do { t = sta.top(); sta.pop(); ins[t] = false;
                        scc[t] = scnt; } while (t != x);
        }
        return low[x];
}

int n, m;
avi e;
int sz[mxn];

int s;

bool v[mxn];
vi ring;
bool dfs(int x) { // 从固定点s找环的dfs
        if (v[x] && x == s) return true;
        if (v[x]) return false;
        v[x] = true;
        ring.pb(x);
        for (auto i : e[x])
                if (dfs(i))
                        return true;
        ring.pop_back();
        return false;
}

int rid[mxn];

avi e2;

struct MM { // minmax
        int mn, mx;
        MM() : mn(MXL), mx(-MXL) {}
        MM(int x) : mn(x), mx(x) {}
        MM(int mn, int mx) : mn(mn), mx(mx) {}
        void add(MM b) {
                mn = min(mn, b.mn);
                mx = max(mx, b.mx);
        }
};

// forward / back
avi ef, eb;
MM ff[mxn], fb[mxn];
bool vf[mxn], vb[mxn];

int c[mxn];

// 似乎比题解讲的复杂，因为环外边的准确定义应该是不经过环上节点的路径（起点、终点除外）!!
// 环上节点不能自己更新自己…否则会产生自环的意义… !!
void dp(vi *e, MM *f, bool *v) {
        function<void(int)> cal = [&](int x) {
                if (v[x]) return;
                v[x] = true;
                for (auto i : e[x]) {
                        if (!rid[i]) {
                                cal(i);
                                f[x].add(f[i]);
                        } else {
                                f[x].add(rid[i]);
                        }
                }
        };
        for (int i = 1; i <= n; ++i) if (!v[i])
                cal(i);
}

int main() {
        #define NIE ({puts("-1"); return 0;})
        #define ZERO ({puts("-1"); puts(""); return 0;})
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
                int x, y;
                scanf("%d%d", &x, &y);
                e[x].pb(y);
        }

        for (int i = 1; i <= n; ++i) if (!dfn[i])
                tarjan(i, e);

        for (int i = 1; i <= n; ++i)
                ++sz[scc[i]];

        for (int i = 1; i <= n; ++i) if (sz[scc[i]] > 1)
                s = i;

        // 无环

        if (!s) NIE;

        // 找出第一个环

        dfs(s);

        int rn = ring.size();

        for (int i = 0; i < rn; ++i)
                rid[ring[i]] = i + 1;

        // 判第二个环

        fill(dfn, dfn + n + 1, 0);
        cnt = scnt = 0;
        for (int i = 1; i <= n; ++i)
                for (auto j : e[i])
                        if (!rid[i] && !rid[j])
                                e2[i].pb(j);

        fill(sz, sz + n + 1, 0);

        for (int i = 1; i <= n; ++i) if (!dfn[i])
                tarjan(i, e2);

        for (int i = 1; i <= n; ++i)
                ++sz[scc[i]];

        for (int i = 1; i <= n; ++i) if (sz[scc[i]] > 1)
                ZERO;

        // 环上DP

        for (int i = 1; i <= n; ++i)
                for (auto j : e[i])
                        /*if (!rid[i] || !rid[j] || (rid[i] - 1 + 1) % rn != rid[j] - 1) */{ // 直接用原图应该也没问题? 毕竟对环交点来说环上边不影响结果？
                                ef[i].pb(j);
                                eb[j].pb(i);
                        }

        dp(ef, ff, vf);
        dp(eb, fb, vb);

        auto rem = [](int l, int r) {
                if (l <= r) {
                        ++c[l];
                        --c[r + 1];
                }
        };

        for (int i = 1; i <= rn; ++i) {
                int x = ring[i - 1];
                // 下面都有等于的可能，虽然没有自环
                if (ff[x].mx >= i) rem(i + 1, ff[x].mx - 1); // 环序号是i不是x!!!!!
                if (ff[x].mn <= i) rem(i + 1, rn);
                if (fb[x].mx >= i) rem(1, i - 1);
        }

        partial_sum(c, c + rn + 1, c);

        vi sol;
        for (int i = 1; i <= rn; ++i) if (!c[i])
                sol.pb(ring[i - 1]);

        sort(sol.begin(), sol.end());
        if (sol.size()==0){ puts("-1"); return 0; }
        cout << sol[0] << endl;


        return 0;
}
