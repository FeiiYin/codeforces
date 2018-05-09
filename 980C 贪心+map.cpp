 /*
 * @Samaritan_infi
 */
/// 求字典序最小的替换序列，只能在k的范围内替换
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

/// first : color value
/// second : last appear
map<int, int> pq;
int ans[maxn];
int main() {
    int n = read(), k = read();
    pq[0] = -1;
    for(int i = 0; i < n; i ++) {
        int x = read();
        if(pq.size() == 1) {
            int now = x - k + 1;
            if(now <= 0) {
                now = 0;
            } else {
                now = max(pq[0] + 1, now);
            }
            ans[i] = now;
            if(now) pq[now] = x;
            else pq[0] = max(pq[0], x);
            continue;
        }
//        for(auto x : pq) {
//            cout << x.first << " " << x.second << endl;
//        }
        auto pos = pq.upper_bound(x);
        if(pos == pq.end()) pos --;
        int val = pos->first;
        //cout << pos->first << " " << pos->second << endl;
        if(val > x) {
            pos --;
            val = pos->first;
        }
        if(x - val >= k) {
            int now = max(x - k + 1, pq[val] + 1);
            ans[i] = now;
            pq[now] = x;
        } else {
            ans[i] = val;
            pq[val] = max(pq[val], x);
        }
    }
    for(int i = 0; i < n; i ++) {
        printf("%d ", ans[i]);
    }puts("");
    return 0;
}
