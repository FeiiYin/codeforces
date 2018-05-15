/*
 * @Samaritan_infi
 */
/// 用动态字典树可以节省内存，静态的可能开不下
/// 查询x < s' 的条件，用字典树来维护每个结点之后的最小值
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

struct trie_node {
    int mi; /// 维护的最小值
    trie_node * next[2];

    trie_node () {
        mi = maxn, next[0] = next[1] = nullptr;
    }
} * trie[maxn];
vector<int> factor[maxn];
void init() {
    for(int i = 1; i < maxn; i ++) {
        for(int j = i; j < maxn; j += i)
            factor[j].emplace_back(i);
        trie[i] = new trie_node();
    }
}

void trie_insert(int k, int u) {
    trie_node *now = trie[k];
    now->mi = min(now->mi, u);
    for(int i = 18; i >= 0; i --) {
        if(now->next[u >> i & 1] == nullptr)
            now->next[u >> i & 1] = new trie_node();
        now = now->next[u >> i & 1];
        now->mi = min(now->mi, u);
    }
}

int trie_query(int x, int k, int s) {
    trie_node *now = trie[k];
    if(x % k != 0 || now->mi + x > s)
        return -1;
    int ret = 0;
    for(int i = 18; i >= 0; i --) {
        int to = x >> i & 1;
        if(now->next[to ^ 1] != nullptr && now->next[to ^ 1]->mi + x <= s) {
            ret += ((to ^ 1) << i);
            now = now->next[to ^ 1];
        } else {
            /// 因为要么这个树就没有一个数，即根节点维护的mi = 1e5
            /// 不然有一个数的话，就一定能往下走到底
            ret += (to << i);
            now = now->next[to];
        }
    }
    return ret;
}

bool vis[maxn] = {0};
int main() {
    init();
    int op = read(), q, x, k, s;
    while(op --) {
        q = read();
        if(q == 1) {
            x = read();
            if(! vis[x]) {
                vis[x] = true;
                for(int k : factor[x])
                    trie_insert(k, x);
            }
        } else {
            x = read(), k = read(), s = read();
            printf("%d\n", trie_query(x, k, s));
        }
    }
    return 0;
}
