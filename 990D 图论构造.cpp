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

const int maxn = 1050;

int ans[maxn][maxn];

void out(int n) {
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            printf("%d", ans[i][j]);
        }puts("");
    }
}

int main() {
    int n = read(), a = read(), b = read();
    memset(ans, 0, sizeof ans);

    if(n == 1) {
        if(a == 1 && b == 1) {
            puts("YES");
            printf("0\n");
        } else {
            puts("NO");
        }
        return 0;
    }

    if(n == 2) {
        if(a == 1 && b == 2) {
            puts("YES");
            printf("01\n10\n");
        } else if(a == 2 && b == 1) {
            puts("YES");
            printf("00\n00\n");
        } else {
            puts("NO");
        }
        return 0;
    }

    if(n == 3) {
        if(a == 1 && b == 2) {
            puts("YES");
            printf("011\n100\n100\n");
        } else if(a == 2 && b == 1) {
            puts("YES");
            printf("010\n100\n000");
        } else if(a == 3 && b == 1) {
            puts("YES");
            printf("000\n000\n000\n");
        } else if(a == 1 && b == 3) {
            puts("YES");
            printf("011\n101\n110\n");
        } else {
            puts("NO");
        }
        return 0;
    }

    if(a == 1 && b == 1) {
        puts("YES");
        for(int i = 1; i <= n; i ++) {
            ans[i][i + 1] = 1;
            ans[i + 1][i] = 1;
        }
        out(n);
        return 0;
    }
    if( a <= n && b == 1) {
        for(int i = 1; i <= n - a; i ++) {
            ans[1][i + 1] = 1;
            ans[i + 1][1] = 1;
        }
        puts("YES");
        out(n);
        return 0;
    }
    if(a == 1 && b == 2) {
        for(int i = 2; i <= n; i ++) {
            ans[1][i] = ans[i][1] = 1;
        }
        puts("YES");
        out(n);
        return 0;
    } else if(a == 1 && b <= n) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) ans[i][j] = 1;
        }
        for(int i = 1; i <= n; i ++) ans[i][i] = 0;
        for(int i = 1; i <= n - b; i ++) {
            ans[1][i + 1] = 0;
            ans[i + 1][1] = 0;
        }
        puts("YES");
        out(n);
        return 0;
    }
    puts("NO");

    return 0;
}
