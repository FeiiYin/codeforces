/*
 * @Samaritan_infi
 */
///如果不记超时是个简单dp
///中间如果阻碍的数量和位置不变化，就可以用矩阵快速幂来加速
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;

inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int mod = 1e9 + 7 ;
const int maxn = 1e6 + 5 ;

struct mat{
    ll x[3][3] ;
}x , a[8] ;
inline mat operator * (const mat &a , const mat &b) {
	mat c ;
	memset(c.x , 0 , sizeof(c.x)) ;
	for(int i = 0 ; i < 3 ; i ++)
    for(int j = 0 ; j < 3 ; j ++)
    for(int k = 0 ; k < 3 ; k ++)
		c.x[i][k]=(c.x[i][k] + 1LL*a.x[i][j] * b.x[j][k]) % mod;
	return c;
};
void show(mat x) {
    for(int i = 0 ; i < 3 ; i ++) {
        for(int j = 0 ; j < 3 ; j ++) {
            cout << x.x[i][j] << " " ;
        }
        cout << endl ;
    }
}
void show() {
    for(int i = 0 ; i < 3 ; i ++) {
        for(int j = 0 ; j < 3 ; j ++) {
            cout << x.x[i][j] << " " ;
        }
        cout << endl ;
    }
}

inline mat quick_pow(mat x , ll y) {

	
	mat r ;
    for(int i = 0 ; i < 3 ; i ++)
        for(int j = 0 ; j < 3 ; j ++)
            r.x[i][j] = (i == j) ;

    for( ; y ; y >>= 1 , x = x * x)
        if(y & 1) r = r * x ;

    return r ;
}

struct node {
    ll column ;
    int row ;
    int flag ;
    bool operator < (const node & k) const {
        return column < k.column ;
    }
} save[maxn << 1];



int block[4] ;
int cal() {
    return (block[1] ? 4 : 0) + (block[2] ? 2 : 0) + (block[3] ? 1 : 0) ;
}

void init() {
    memset(block , 0 , sizeof block) ;
	for(int i = 0 ; i < 8 ; i ++) {
		if(!(i & 4))a[i].x[0][0] = a[i].x[1][0] = 1 ;
		if(!(i & 2))a[i].x[0][1] = a[i].x[1][1] = a[i].x[2][1] = 1 ;
		if(!(i & 1))a[i].x[1][2] = a[i].x[2][2] = 1 ;
	}
	memset(x.x , 0 , sizeof x.x) ;
	x.x[0][1] = 1 ;
	save[0].row = 2 ;
	save[0].column = 2 ;
}



int main() {
    int n = read() ; ll m = read() ;
    //scanf("%d %lld" , &n , &m) ;
    ll s ; int b , c ;
    for(int i = 1 ; i <= n ; i ++) {
        //scanf("%lld %d %d" , &s , &b , &c) ;
        s = read() ; b = read() ; c = read() ;
        save[i].row = save[i + n].row = s ;
        save[i].column = b ;
        save[i + n].column = c + 1 ;
        save[i].flag = 1 ;
        save[i + n].flag = -1 ;
    }

    sort(save + 1 , save + 2 * n + 1) ;
    init() ;
    for(int i = 1 ; i <= (n * 2) ; i ++) {
        x = x * quick_pow(a[cal()] , (save[i].column - save[i - 1].column)) ;
        block[ save[i].row ] += save[i].flag ;
        //show() ;
    }
    x = x * quick_pow(a[0] , m + 1 - save[n * 2].column) ;
    //show() ;

	printf("%d\n" , x.x[0][1]);
	return 0;
}
/// 正解
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define MN 10000
#define MOD 1000000007
struct P{ll x;int y,z;}p[MN*2+5];
bool cmp(const P&a,const P&b){return a.x<b.x;}
struct mat{int z[3][3];}x,a[8];
inline mat operator*(const mat&a,const mat&b)
{
	mat c;memset(c.z,0,sizeof(c.z));
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)for(int k=0;k<3;++k)
		c.z[i][k]=(c.z[i][k]+1LL*a.z[i][j]*b.z[j][k])%MOD;
	return c;
};
int u[4];
int cal(){return (u[1]?4:0)+(u[2]?2:0)+(u[3]?1:0);}
inline mat pw(mat x,ll y)
{
	mat r;
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)r.z[i][j]=i==j;
	for(;y;y>>=1,x=x*x)if(y&1)r=r*x;
	return r;
}
int main()
{
	int n=read(),i,j;ll m=read();
	for(i=1;i<=n;++i)j=read(),p[i]=(P){read(),j,1},p[i+n]=(P){read()+1,j,-1};
	sort(p+1,p+n+n+1,cmp);
	for(i=0;i<8;++i)
	{
		if(!(i&4))a[i].z[0][0]=a[i].z[1][0]=1;
		if(!(i&2))a[i].z[0][1]=a[i].z[1][1]=a[i].z[2][1]=1;
		if(!(i&1))a[i].z[1][2]=a[i].z[2][2]=1;
	}
	x.z[0][1]=1;p[0].x=2;
	for(i=1;i<=n+n;++i)x=x*pw(a[cal()],p[i].x-p[i-1].x),u[p[i].y]+=p[i].z;
	x=x*pw(a[0],m-p[n+n].x+1);
	printf("%d",x.z[0][1]);
	return 0;
}

