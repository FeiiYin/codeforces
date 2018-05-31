/*
 * @Samaritan_infi
 */
/// 考虑到交换，且原来数组中每一个数都是一定的，所以每次交换会改变 逆序对数量的奇偶性，所以BIT
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

int tree[maxn];
int low_bit(int x) {return x & -x;}
void add(int pos, int n) {
    for(; pos <= n; pos += low_bit(pos)) tree[pos] ++;
}
int query(int pos) {
    int ans = 0;
    for(; pos > 0; pos -= low_bit(pos)) ans += tree[pos];
    return ans;
}
int main() {
    int n = read();
    int x;
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        x = read();
        ans += query(n) - query(x);
        add(x, n);
    }
    printf("%s\n", (n + ans) % 2 != 1 ? "Petr" : "Um_nik");
    return 0;
}
