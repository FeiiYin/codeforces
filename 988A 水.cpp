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

const int maxn = 1e6 + 5;

map <int, int> pq;
int v[300];
vector<int> k;
int main() {
    int n = read(), kk = read();
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int x = read();
        if(ans >= kk) continue;
        if(v[x]) continue;
        v[x] = true;
        k.push_back(i + 1);
        ans ++;
    }
    if(ans == kk) {
        puts("YES");
        for(int i = 0; i < kk; i ++) printf("%d ", k[i]);
        puts("");
    } else {
        puts("NO");
    }
	return 0;
}
