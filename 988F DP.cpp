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

const int maxn = 2222;
const int INF = 2e9;


int l[maxn], r[maxn], x[maxn], p[maxn], dp[maxn];
int vis[maxn];

int main(){
    int a = read(), n = read(), m = read();

    for(int i = 1; i <= n; i ++) {
        l[i] = read(), r[i] = read();
    }

    for(int i = 1; i <= m; i ++) {
        x[i] = read(), p[i] = read();
        if(! vis[ x[i] ] || vis[ x[i] ] > p[i])
            vis[ x[i] ] = p[i];
    }

    for(int i = 1; i <= a; i ++){
        dp[i] = INF;
    }

    for(int i = 0; i < a; ++i){
        if(dp[i] == INF) continue;
        if(vis[i]) {
            int sum = 0;
            for(int j = i + 1; j <= a; j ++) {
                sum += vis[i];
                dp[j] = min(dp[j], dp[i] + sum);
            }
        }
        bool f = 1;
        for(int j = 1; j <= n; j ++){
            if(i >= l[j] && i + 1 <= r[j]){
                f = 0;
                break;
            }
        }
        if(f) dp[i + 1] = min(dp[i + 1], dp[i]); 
    }

    if(dp[a] == INF) dp[a] = -1;
    printf("%d\n", dp[a]);

    return 0;
}
