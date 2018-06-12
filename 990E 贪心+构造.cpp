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

const int maxn = 1e6 + 5;

int val[maxn];
int fail[maxn];
int pos[maxn];

int work(int l, int n) {
    int cur = 0, now = -1, num = 0;
    while(cur < n) {
        if(pos[cur] <= now) return -1;
        //cout << cur << " " << pos[cur] << " " << now << endl;
        now = pos[cur];
        cur = now + l;
        num ++;
    }
    return num;
}

int main() {
    int n = read(), a = read(), k = read();
    bool f = false;
    for(int i = 1; i <= a; i ++) {
        int x = read();
        fail[x] = true;
        if(! x) f = true;
    }
    for(int i = 1; i <= k; i ++) {
        val[i] = read();
    }
    if(f) {
        puts("-1");
        return 0;
    }
    int fail_len = 1, now_len = 0;
    for(int i = 0; i < n; i ++) {
        if(! fail[i]) pos[i] = i;
        else if(i) pos[i] = pos[i - 1];
        else pos[i] = -1;

        if(! fail[i]) fail_len = max(fail_len, now_len), now_len = 0;
        else now_len ++;
    }

    //for(int i = 0; i < n; i ++) cout << pos[i] << " "; cout << endl;

    ll ans = 1e18;
    for(int i = fail_len; i <= k; i ++) {
        int num = work(i, n);
        if(num > 0) ans = min(ans, (ll)num * val[i]);
    }
    printf("%lld\n", ans == 1e18 ? -1 : ans);
    return 0;
}
