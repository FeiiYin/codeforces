/*
 * @Samaritan_infi
 */
/// 题目求对给定的T，使总量最大， T = 求和（ai * ti）/求和（ai）
/// 二分答案，因为t是单调的，所以从两边贪心，如果存在该解，从小的贪心应该比T小，从大的贪心应该比T大

#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

template <class T>
inline void scan(T &ret) {
    char c ;
    ret = 0 ;
    while((c = getchar()) < '0' || c > '9') ;
    while(c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0' , c = getchar() ;
    }
}

const int maxn = 1e6 + 5 ;
struct node {
    int a , t ;
    bool operator < ( const node & k) const {
        return t < k.t ;
    }
};

node save[maxn] ;
int n , t ;

bool check(double mid) {
    double sum = mid * t;
    double tot = mid ;
    double a1 = 0 , a2 = 0 ;
    for(int i = 0 ; i < n ; i ++) {

        if(tot >= save[i].a) {
            tot -= save[i].a ;
            ///注意这个ll ，不然爆了int会wa
            a1 += (ll)save[i].a * save[i].t ;
        } else {
            a1 += (ll)save[i].t * tot ;
            tot -= tot ;
            break ;
        }
    }
    tot = mid ;
    for(int i = n - 1 ; i >= 0 ; i --) {

        if(tot >= save[i].a) {
            tot -= save[i].a ;
            a2 += (ll)save[i].a * save[i].t ;
        } else {
            a2 += (ll)save[i].t * tot ;
            tot -= tot ;
            break ;
        }
    }
    return (a1 <= sum) && (sum <= a2) ;
}

int main() {
    scan(n) ; scan(t) ;
    double sum = 0 ;
    for(int i = 0 ; i < n ; i ++) {
        scan(save[i].a) ;
        sum += save[i].a ;
    }
    for(int i = 0 ; i < n ; i ++) {
        scan(save[i].t) ;
    }
    sort(save , save + n) ;

    double l = 0 , r = sum ;

    //while(fabs(l - r) > 1e-8) {
    for(int i = 0 ; i < 120 ; i ++) {
        double mid = (l + r) / 2 ;
        if(check(mid)) l = mid ;
        else r = mid ;
    }
    double ans = (check(r) ? r : l) ;

    printf("%.15f\n" , ans) ;
    return 0 ;
}
