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

const int maxn = 2e5 + 5;

ll a[maxn];
map<ll, int> pq;
ll dp[40];


int a1, a2, a3;
int work(int n) {
    bool k1 = false, k2 = false;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= 30; j ++) {
            if(pq.count(a[i] + dp[j])) {
                k1 = true;
                a1 = a[i], a2 = a[i] + dp[j];
                if( j < 30 && pq.count(a[i] + dp[j + 1])) {
                    a1 = a[i], a2 = a[i] + dp[j], a3 = a[i] + dp[j + 1];
                    return 3;
                }
            }
        }
    }
    if(k1) {
        return 2;
    }
    return 1;
}

int main() {
    dp[0] = 1;
    //cout << (1 << 30 ) << endl;
    for(int i = 1; i <= 30; i ++ ) {
        dp[i] = dp[i - 1] << 1;
        //cout << dp[i] << endl;
    }

    int n = read();
    for(int i = 0; i < n; i ++) {
        scanf("%lld", &a[i]);
        pq[ a[i] ] = 1;
    }
    sort(a, a + n);
    int num = work(n);
    printf("%d\n", num);
    if(num == 1) {
        printf("%d\n", a[0]);
    } else if(num == 2) {
        printf("%d %d\n", a1, a2);
    } else {
        printf("%d %d %d\n", a1, a2, a3);
    }
	return 0;
}
