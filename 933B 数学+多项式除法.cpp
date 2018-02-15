#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20050 ;

ll ans[maxn] ;
ll cal(ll p , ll k){
    return (p % k + k) % k ;
}

int main(){
    ll p , k ;
    scanf("%lld %lld" , &p , &k) ;
    int pos = 0 ;
    while(p){
        ans[ ++ pos ] = cal(p , k) ;
        p -= ans[pos] ;
        p /= (-k) ;
    }
    printf("%d\n" , pos) ;
    for(int i = 1 ; i <= pos ; i ++){
        printf("%lld%c" , ans[i] , i < pos ? ' ' : '\n') ;
    }
    return 0 ;
}
