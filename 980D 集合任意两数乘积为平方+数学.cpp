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
const int maxn = 5e3 + 5;

const int P=1e5;
bool isprime[P] = {0};
vector<int> prime;
void get_prime(){
    for(int i = 2; i < P; i ++)
        if(! isprime[i]) {
            prime.push_back(i);
            for(int j = i; j < P; j += i) isprime[j]=true;
        }
}


int pre[maxn];
//int factor[maxn][15];
int num[maxn];
int mask[maxn];
map<int, int> pq;
/// set<int> s; will Time exceed
int ans[maxn] = {0};
/// 分解要先用素数晒，只选出素数，不然会T。。
void decompose(int pos, int x) {
    if(x == 0) { num[pos] = 0; return; }
    int res = x;
    x = abs(x);
    for(int i : prime) {
        if((ll) i * i > x) break;
        while(x % (i * i) == 0) {
            res /= (i * i);
            x /= (i * i);
        }
    }
    num[pos] = res;
}

int temp[maxn];
int main() {
    get_prime();
    int n = read(), x;
    vector<int> li;
    for(int i = 1; i <= n; i ++) {
        pre[i] = read();
        decompose(i, pre[i]);
        li.push_back(num[i]);
    }

    sort(li.begin(), li.end());
    li.resize(unique(li.begin(), li.end())-li.begin());
    for(int i = 1; i <= n; i ++)
        mask[i] = lower_bound(li.begin(), li.end(), num[i]) - li.begin();


    for(int i = 1; i <= n; i ++) {
        for(int k = 0; k <= n; k ++) temp[k] = 0;
        int ac = 0;

        for(int j = i; j <= n; j ++) {
            if(pre[j]) {
                temp[ mask[j] ] ++;
                if(temp[ mask[j] ] == 1) ac ++;
            }
            ans[ max(1, ac) ] ++;
        }
    }
    for(int i = 1; i <= n; i ++) printf("%d ", ans[i]);
    puts("");
    return 0;
}
