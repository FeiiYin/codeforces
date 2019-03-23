/**
`* @Samaritan
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PII pair<int, int>
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define fi  first
#define se second

const int N = 3e5 + 5;

struct node {
    LL t, v;
    int ver, id;
    node () {}
    node (LL a, LL b) : t(a), v(b) { ver = 0; }
    bool operator < (const node k) const {
        return t < k.t;
    }
    void show() {
        cout << "t:"<<t << " v:"<<v << "id: "<<id<<endl;
    }
};

bool cmp (node a, node b)
{
    return a.v < b.v;
}
node arr[N];

//int tree[N << 2];
//void build (int l, int r, int rt) {
//    if (l == r) {
//        tree[rt] = arr[l].v;
//        return;
//    }
//    int mid = (l + r) >> 1;
//    build(l, mid, rt<<1);
//    build(mid+1, r, rt<<1|1);
//    tree[rt] = min(tree[rt<<1], tree[rt<<1|1]);
//}
//int query (int l, int r, int L, int R, int rt) {
//    if (L <= l && r <= R) {
//        return tree[rt];
//    }
//    if (r < L || l > R) return 10000000;
//    int mid = (l + r) >> 1;
//    int ans = 10000000;
//    if (r >= L) ans = min(ans, query(mid+1, r, L, R, rt<<1|1));
//    if (l <= R) ans = min(ans, query(l, mid, L, R, rt<<1));
//    return ans;
//}

node temp[N];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &arr[i].t, &arr[i].v);
    }

    sort (arr, arr + n, cmp);
    LL ans = 0;
    priority_queue <node> pq;
    for (int i = 0; i < n; ++i) {
        arr[i].id = i;
        pq.push(arr[i]);
    }
    node tmp;

    set<int> ss;
    LL tot = 0;
    for (int i = 0; i < k-1; ++i) {
        tmp = pq.top();
        pq.pop();
        tot += tmp.t;
        ss.insert(tmp.id);
    }

    for (int i = 0; i < n; ++i) {
//arr[i].show();
        int lim = min (k-1, n-1-i);
        LL now_t = arr[i].t;
        arr[i].ver = 2;
        if (! ss.count(arr[i].id)) {
            ans = max(ans, (tot + now_t)*arr[i].v);
            //cout << "?? " << tot+now_t << " "  << arr[i].v << endl;
        } else {
            ss.erase(arr[i].id);
            tot -= now_t;
            while (! pq.empty()) {
                tmp = pq.top();
                pq.pop();

                if (tmp.ver < arr[ tmp.id ].ver) continue;

                tot += tmp.t;
                ss.insert(tmp.id);
                break;
                //cout << "insert id" << tmp.id << endl;
            }
            //cout << "!!"<<tot+now_t << " " << arr[i].v << endl;
            ans = max(ans, (tot + now_t)*arr[i].v);
        }

//
//        ans = max(ans, now_t * arr[i].v);
//        for (int j = 0; j < pos; ++j) {
//            pq.push(temp[j]);
//        }
    }
    printf("%lld\n", ans);
    return 0;
}
