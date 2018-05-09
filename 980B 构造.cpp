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

int ans[4][150];

int main() {
    int n = read(), k = read();
    puts("YES");
    memset(ans, 0, sizeof ans);

    if(k == 2 * (n - 2)) {
        for(int i = 1; i <= n; i ++) putchar('.');
        printf("\n.");
        for(int i = 2; i <= n - 1; i ++) putchar('#');
        printf(".\n.");
        for(int i = 2; i <= n - 1; i ++) putchar('#');
        printf(".\n");
        for(int i = 1; i <= n; i ++) putchar('.');
        puts("");
        return 0;
    }

    int yu;
    if(k & 1) yu = 1, k --;
    else yu = 0;

    bool f = true;
    int l = 2, r = n - 1, now = 1;
    while(k --) {
        if(f) {
            ans[now][l ++] = 1;
            f = false;
        } else {
            ans[now][r --] = 1;
            f = true;
        }
        if(l == r) {
            l = 2, r = n - 1;
            now ++;
            f = true;
        }
    }

    if(yu) ans[1][n / 2 + 1] = 1;
    for(int i = 0; i < 4; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(ans[i][j]) putchar('#');
            else putchar('.');
        }puts("");
    }
    return 0;
}
