/*
 * @Samaritan_infi
 */
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
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

template <class T>
void show(T a[], int len) {
    for(int i = 0; i <= len; i ++) cout << a[i] << " "; cout << endl;
}

struct node {
    ll hp, da;
    node() {}
    bool operator < (const node &k ) const {
        return hp - da > k.hp - k.da;
    }
}s[maxn];


int main() {
    int n = read(), a = read(), b = read();
    ll ans = 0, t = 0, out = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%lld %lld", &s[i].hp, &s[i].da);
        ans += s[i].da;
    }
    b = min(b, n);
    sort(s + 1, s + 1 + n);
    if (b == 0) return !printf("%lld\n", ans);
	for(int i = 1; i <= b; i ++) {
        if(s[i].hp > s[i].da) ans += s[i].hp - s[i].da;
    }

    out = ans;
    for(int i = 1; i <= n; i ++) {
        ll t = ans;
        if(i <= b) {
            t += max(s[i].hp << a, s[i].da) - s[i].da;
            t -= max(0LL, s[i].hp - s[i].da);
        } else {
            t += max(s[i].hp << a, s[i].da) - s[i].da;
            t -= max(0LL, s[b].hp - s[b].da);
        }
        out = max(out, t);
    }
    printf("%lld\n", out);
    return 0;
}
