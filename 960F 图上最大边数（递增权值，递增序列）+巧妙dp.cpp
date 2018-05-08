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
vector< map<int, int> > s;

int get_edge_len(int a, int v) {
//    for(auto it : s[a]) {
//        cout << (it.first) << " " << (it.second) << endl;
//    }
    auto it = s[a].lower_bound(v);
    if(it == s[a].begin())
        return 1;
    it --;
    return (it->second) + 1;
}

int main() {
    int n = read(), m = read();
    int a, b, v, ans = 0;
    s.resize(n + 1);
    while(m --) {
        a = read(), b = read(), v = read();
        int val = get_edge_len(a, v);
        /// 到b的且值小于 v+1 已经大于val
        /// 注意不能用大于等于，因为对于第一个都是1，就没办法判断了
        if(get_edge_len(b, v+1) > val) continue;
        s[b][v] = max(s[b][v], val);
        auto it = s[b].upper_bound(v);
        while(it != s[b].end() && it->second <= val) {
            it = s[b].erase(it);
        }
        ans = max(ans, val);
    }
    cout << ans << endl;
    return 0;
}
