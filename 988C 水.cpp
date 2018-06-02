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

int len[maxn], sum[maxn];
//vector<int> e[maxn];
int e[maxn];
map<int, pair<int, int> > pq;

int main() {

    int n = read(), x, ss;
    bool flag = false;
    pair<int, int> a1, a2;
    for(int i = 0; i < n; i ++) {
        len[i] = read();
        ss = 0;
        for(int j = 0; j < len[i]; j ++) {
            //x = read();
            e[j] = read();//.push_back(x);
            ss += e[j];
        }
        if(flag) continue;
        sum[i] = ss;
        for(int j = 0; j < len[i]; j ++) {
            int now = ss - e[j];
            if(pq.count(now)) {
                flag = true;
                a1 = pq[now];
                a2 = make_pair(i + 1, j + 1);
                break;
            }
        }
        for(int j = 0; j < len[i]; j ++) {
            int now = ss - e[j];

            pq[now] = make_pair(i + 1, j + 1);
        }
    }
    if(flag) {
        puts("YES");
        printf("%d %d\n%d %d\n", a1.first, a1.second, a2.first, a2.second);
    } else {
        puts("NO");
    }

	return 0;
}
