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
const int maxn = 3005;

int a[maxn];
int c[maxn];


int dp[maxn][3];

int main() {
    int n = read();
    for(int i = 0; i < n; i ++) a[i] = read();
    for(int i = 0; i < n; i ++) {
        c[i] = read();
        dp[i][0] = dp[i][1] = 1e9;
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < i; j ++) {
            if(a[i] > a[j]) {
                dp[i][0] = min(dp[i][0], c[i] + c[j]);
                dp[i][1] = min(dp[i][1], dp[j][0] + c[i]);
            }
        }
    }
    int ans = 1e9;
    for(int i = 2; i < n; i ++) {
        ans = min(ans, dp[i][1]);
    }
    printf("%d\n", ans == 1e9 ? -1 : ans);
    return 0;
}
