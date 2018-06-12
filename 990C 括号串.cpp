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

const int maxn = 3e5 + 5;
//const int maxm = 1e6 + 5;

char c[maxn];
int mark[maxn];
int num[maxn];

int lll[maxn];
int rrr[maxn];

int main() {
    int n = read();
    int safe = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%s", c);
        int l = 0, r = 0, nn = 0;
        for(int j = 0; j < strlen(c); j ++) {
            if(c[j] == '(') {
                l ++;

            } else {
                r ++;
                if(r > l) { mark[i] = 1;
                    nn += r - l;
                    l = 0, r = 0;

                }
            }
        }
        //cout << l << " " << r << endl;
        if(mark[i]) {
            /// )()())()
            ///)(())(
            ///)))((
            if(l == r) {
                mark[i] = 1;
                num[i] = nn;
                rrr[ num[i] ] ++;
            } else if(l > r) {
                mark[i] = 100;
            } else if(r > l) {
                /// )))())
                mark[i] = 1;
                num[i] = r - l + nn;
                rrr[ num[i] ] ++;
            }
            continue;
        }
        if(l == r) mark[i] = 0, safe ++;
        ///
        else if(l > r) {
            mark[i] = 2;
            num[i] = l - r;
            lll[ num[i] ] ++;
        }
        else if(r > l) {
            mark[i] = 1;
            num[i] = r - l;
            rrr[ num[i] ] ++;
        }
    }
    ll ans = (ll)safe*safe;
    for(int i = 1; i <= n; i ++) {
            //cout << mark[i] << " " << num[i] << endl;;
        if(mark[i] == 1) {
            ans = ans + lll[ num[i] ];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
