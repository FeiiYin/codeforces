/*
 * @Samaritan_infi
 */
/// 网络流思想
/// 最大流 == 最小割
/// 求建立边之后的最大流，最小割一定是一个l区间内的边
/// 或者想成一堆青蛙 ，每次都只移动最左边的青蛙
/// 建图
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

const int maxn = 1e5 + 5;
int a[maxn];
int main() {
	int n = read(), k = read();
	for (int i = 0; i < n - 1; i ++) {
        a[i] = read();
	}

	ll cur = 0;
	for (int i = 0; i < k; i ++) cur += a[i];
	ll ans = cur;
	for (int i = k, j = 0; i < n - 1; i ++, j ++) {
		cur += a[i];
		cur -= a[j];
		ans = min(ans, cur);
	}
	printf("%lld\n", ans);
	return 0;
}
