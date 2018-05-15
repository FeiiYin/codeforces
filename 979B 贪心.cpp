/*
 * @Samaritan_infi
 */
/// 它如果是变奇数次，可以先变成a再变成b再变回去
/// 只有1的时候需要特殊判断
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


char a[maxn], b[maxn], c[maxn];
int num[100];

int cal(char d[], int n) {
    memset(num, 0, sizeof num);
    int l = strlen(d);
    for(int i = 0; i < l; i ++) {
        if(d[i] >= 'a' && d[i] <= 'z') num[ d[i] - 'a' ] ++;
        else  num[ d[i] - 'A' + 26 ] ++;
    }
//    for(int i = 0; i < 26 + 26; i ++) {
//        cout << num[i] << " ";
//    }cout << endl;
    int ans = 0;
    //memset(vis, 0, sizeof vis);
    int len = l;
    if(n == 1) {
        for(int i = 0; i < 26 + 26; i ++) {
            if(num[i] == len) ans = max(ans, len - 1);
            else
            ans = max(ans, num[i] + 1);
        }
        return ans;
    }
    for(int i = 0; i < 26 + 26; i ++) {
        if(num[i] + n < len)
            ans = max(ans, num[i] + n);
        else
            ans = max(ans, len);

    }
    return ans;
}

int main() {
    int n ;
    scanf("%d", &n);
    scanf("%s %s %s", a, b, c);


    int aa = cal(a, n);
    int bb = cal(b, n);
    int cc = cal(c, n);

    if(aa > bb && aa > cc) {
        puts("Kuro");
    } else if(bb > aa && bb > cc) {
        puts("Shiro");
    } else if(cc > aa && cc > bb){
        puts("Katie");
    } else {
        puts("Draw");
    }
    return 0;
}
