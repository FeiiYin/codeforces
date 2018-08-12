/*
 * @Samaritan_infi
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (1 << 12) + 5;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;if(ch==EOF) return x;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


int a[N][N];
int pre[N][105];
int num[N];
int wal[20];
int status_wal[N];

char arr[20];

int n;
inline int into_num() {
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        ans = (ans << 1) + arr[i] - '0';
    }
    return ans;
}

int main() {
    n = read();
    int m = read(), op = read();
    for(int i = 0; i < n; i ++) wal[i] = read();
    int maxn = (1 << n);
    int p, q, pp, qq, temp;

    for(int i = 0; i < maxn; i ++) {
        p = i, temp = 0;
        for(int k = n - 1; k >= 0; k --) {
            if(p & 1) temp += wal[k];
            p >>= 1;
        }
        status_wal[i] = temp;
    }//cout << endl;

    for(int i = 0; i < maxn; i ++) {
        for(int j = i; j < maxn; j ++) {
            temp = i ^ j ^ (maxn - 1);
            //cout << temp << " ";
            a[i][j] = status_wal[temp];
        }//cout << endl;
    }


    for(int i = 0; i < m; i ++) {
        scanf("%s", arr);
        int to = into_num();
        num[to] ++;


    }

    for(int to = 0; to < maxn; to ++) {
        for(int j = 0; j <= to; j ++) {
            if(a[j][to] > 100) continue;
            pre[j][ a[j][to] ] += num[to];
        }

        for(int j = to + 1; j < maxn; j ++) {
            if(a[to][j] > 100) continue;
            pre[j][ a[to][j] ] += num[to];
            //cout << j << " " << a[to][j] << " ";
        }//cout << endl;
    }
//    for(int i = 0; i < maxn; i ++) {
//        for(int j = 0; j <= 100; j ++)
//            cout << pre[i][j] << " ";cout << endl;
//    }


    for(int i = 0; i < maxn; i ++) {
     //   cout << pre[i][0] << ">>"<< endl;
        for(int j = 1; j <= 100; j ++) {
            pre[i][j] += pre[i][j - 1];

       //     cout << pre[i][j] << " ";
        }//cout << endl;
    }

//    for(int i = 0; i < maxn; i ++) {
//        for(int j = 0; j <= 100; j ++)
//            cout << pre[i][j] << " ";cout << endl;
//    }

    //for(int i = 0; i < maxn; i ++) cout << num[i] << " ";cout << endl;

    int K, ans;
    for(int i = 0; i < op; i ++) {
        scanf("%s", arr);
        int to = into_num();
        scanf("%d", &K);
        //cout << to << endl;
        ans = 0;

        printf("%d\n", pre[to][K]);
    }
    return 0;
}
// 7 8 5 6 3 4 1 2
//7 8 9 4 5 6 1 2 3
