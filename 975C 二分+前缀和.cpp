/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const int maxn = 2e5 + 5;
const ll max_damage = 2e14;
ll a[maxn];
ll pre[maxn];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    pre[0] = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    ll op = 0, x;
    for(int i = 1; i <= q; i ++) {
        scanf("%lld", &x);
        op += x;
        if(op >= max_damage) op = max_damage;
        if(op >= pre[n]) {
            op = 0;
            printf("%d\n", n);
            continue;
        }
        int pos = lower_bound(pre + 1, pre + 1 + n, op) - pre;
        if(op < pre[pos]) {
            pos --;
        }
        //cout << pos << endl;
        printf("%d\n", n - pos);
    }
	return 0;
}
