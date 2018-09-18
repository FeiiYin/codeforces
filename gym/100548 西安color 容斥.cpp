/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int pow_mod(LL a, LL exp){
    LL ret = 1;
    while(exp){
        if (exp & 1) ret = ret * a % mod;
        a = a * a % mod;
        exp >>= 1;
    }
    return (int)ret;
}

int c[N];
int inv[N];

void init(){
    const int n = 1e6;
    inv[1] = 1;
    for (int i = 2; i <= n; i++){
        inv[i] = (long long)(mod - mod/i) * inv[mod % i] % mod;
    }
}

int cal(int n, int m, int k){
    if (k == 1 && n == 1) return m;
    if (k == 1 && n > 1) return 0;
    int ret = 1, lim = min(k, m - k);
    for (int i = 1; i <= lim; i++) ret = (long long)ret * (m-i+1) % mod * inv[i] % mod;
    c[0] = 1;
    for (int i = 1; i <= k; i++) c[i] = (long long)c[i-1] * (k-i+1) % mod * inv[i] % mod;
    int tmp, tot = (long long)k * pow_mod(k-1, n-1) % mod;
    for (int i = 1; i+1 < k; i++){
        tmp = (long long)c[i] * (k-i) % mod * pow_mod(k-i-1, n-1) % mod;
        if (i&1){
            tot = tot - tmp;
            if (tot < 0) tot += mod;
        }
        else{
            tot = tot + tmp;
            if (tot >= mod) tot -= mod;
        }
    }
    ret = (long long)ret * tot % mod;
    return ret;
}

int main () {
    init();
    int kase, _ = 1; scanf("%d", &kase);
    while (kase --) {
        int n, m, k; scanf("%d %d %d", &n, &m, &k);
        printf("Case #%d: %d\n", _++, cal(n, m, k));
    }
    return 0;
}
