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

struct node {
    int v;
    bool operator < (const node &k) const {
        return v < k.v;
    }
};

const int maxn = 1050;

int main() {
    ll n, m, a, b;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    if(n % m == 0) {
        printf("0\n");
        return 0;
    }
    ll k = n / m;
    ll aa = ((k + 1) * m - n) * a;
    ll bb = (n - m * k) * b;
    printf("%lld\n", min(aa, bb));
    return 0;
}
