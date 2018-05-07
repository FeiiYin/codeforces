/*
 * @Samaritan_infi
 */
/// dp 数组可以用map 开， 学到了
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

const int maxn = 2e5 + 5;
map<int, int> dp;
int a[maxn];

vector<int> res;
int main() {
    int n = read();
    for (int i = 0; i < n; i ++) {
        a[i] = read();
    }
    int ans = 0;
    int r = 0;
    for (int i = 0; i < n; i ++) {
        int x = a[i];
        dp[x] = dp[x - 1] + 1;
        if(ans < dp[x]) {
            ans = dp[x];
            r = x;
        }
    }

    for(int i = n - 1; i >= 0; i --) {
        if(a[i] == r) {
            res.push_back(i);
            r --;
        }
    }
    printf("%d\n", ans);
    for(int i = res.size() - 1; i >= 0; i --)
        printf("%d ", res[i] + 1);
    puts("");
    return 0;
}
