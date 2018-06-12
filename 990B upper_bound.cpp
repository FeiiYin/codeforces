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

int arr[maxn];

int main() {
    int n = read(), k = read();
    for(int i = 0; i < n; i ++) {
        arr[i] = read();
    }
    sort(arr, arr + n);
    //n = unique(arr + 1, arr + 1 + n) - (arr + 1);
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int pos = upper_bound(arr, arr + n, arr[i] + k) - (arr);
        int now = upper_bound(arr, arr + n, arr[i]) - arr;
        if(pos == now) ans ++;
    }
    cout << ans << endl;
    return 0;
}
