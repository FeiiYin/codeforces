/*
 * @Samaritan_infi
 */
 ///好蠢
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int maxn = 5e5 + 5 ;
ll save[maxn] ;
ll pre[maxn] ;

int n , r ; ll k ;
ll temp[maxn] ;
/// 贪心，每次 archer 放在最右边
bool check(ll m) {
    ll tot = k , now_add = 0 ;
    memset(temp , 0 , sizeof temp) ;
    for(int i = 1 ; i <= n ; i ++) {
        now_add += temp[i] ;
        ///前缀和 i,j = pre[j] - pre[i - 1]
        ll now_val = pre[min(i + r , n)] - pre[max(i - r - 1 , 0)] + now_add ;
        if(now_val >= m) continue ;
        ll margin = m - now_val ;
        if(margin > tot) return false ;
        tot -= margin ;
        now_add += margin ;
        /// position : i + r
        temp[min(i + (r << 1) , n) + 1] -= margin ;
    }
    return true ;
}

int main() {

    scanf("%d %d %lld" , &n , &r , &k) ;
    pre[0] = 0 ;
    ll a = 1e18 , b = 1e20 ;
    for(int i = 1 ; i <= n ; i ++) {
        scanf("%lld" , &save[i]) ;
        pre[i] = pre[i - 1] + save[i] ;
        a = min(a , save[i]) ;
    }
    if(n == 1) {
        printf("%lld\n" , save[1] + k) ;
        return 0 ;
    }
    //for(int i = 1 ; i <= 120 ; i ++) {
    ll ans ;
    while(a < b){
        ll m =(a + b)>>1ll;
        if(check(m)) ans = m , a = m + 1 ;
        else b = m ;
    }
    printf("%lld\n" , ans);

    return 0 ;
}
