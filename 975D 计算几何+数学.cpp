/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
const int MX = 2e5+5;
using namespace std;
typedef long long ll;
int main() {
    int n;cin>>n;ll a,b;cin>>a>>b;
    map<ll,ll> vis;
    map<pair<int,int>,int> sim;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        int x,vx,vy;
        scanf("%d%d%d",&x,&vx,&vy);
        /// x 相遇
        /// t*vx1 + x1 = t * vx2 + x2
        /// y 相遇
        /// t * vy1 + (ax1 + b) = t * vy2 + (ax2 + b)
        /// 两个t相等，即相遇
        /// x2 - x1    ax2 - ax1
        /// ------- = -----------
        /// vx1-vx2    vy1 - vy2
        /// 即
        /// a*x1 - x1 = a*x2 - x2
        /// 再去掉速度平行的点
        ans += vis[a*vx-vy] - sim[{vx,vy}];
        vis[a*vx-vy]++;
        sim[{vx,vy}]++;
    }
    cout<<2*ans<<endl;
    return 0;
}
