/*
 * @Samaritan_infi
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
#define ll long long
int ccnt=0;
int n,cnt,f[maxn],d[maxn],siz[maxn],son[maxn],rk[maxn],top[maxn],tid[maxn];//tid:dfs rk:anti-dfs
int d_mx;
struct edge
{
    int to,next;
}e[maxn];
int head[maxn];
inline void addedge(int u,int v)
{
    e[++ccnt].to=v;
    e[ccnt].next=head[u];
    head[u]=ccnt;
}
void dfs1(int u,int fa,int depth)
{
    f[u]=fa;
    d[u]=depth;
    d_mx=max(d_mx,d[u]);
    siz[u]=1;
    for(int i=head[u]; i ; i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)
            continue;
        dfs1(v,u,depth+1);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}
void dfs2(int u,int t)
{
    top[u]=t;
    tid[u]=++cnt;
    rk[cnt]=u;
    if(!son[u])
        return;
    dfs2(son[u],t);
    for(int i=head[u]; i ; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=son[u]&&v!=f[u])
            dfs2(v,v);
    }
}
int LCA(int x,int y)
{
    if(x==y)
        return x;
    int fx=top[x],fy=top[y];
    while(fx!=fy)
    {
        if(d[fx]>=d[fy])
        {
            x=f[fx];
        }
        else
        {
            y=f[fy];
        }
        fx=top[x];
        fy=top[y];
    }
    if(tid[x]<=tid[y]) return x;
    else return y;
}
#define lson o*2
#define rson o*2+1
#define m (l+r)/2
struct segment
{
    int mx,mn;
}tr[4*maxn];
inline void pushup(int o)
{
    tr[o].mx=max(tr[lson].mx,tr[rson].mx);
    tr[o].mn=min(tr[lson].mn,tr[rson].mn);
}
inline int ret(int o,int flag)
{
    if(flag) return tr[o].mx;
    else return tr[o].mn;
}
void build(int o,int l,int r)
{
    if(l==r)
    {
        tr[o].mx=tr[o].mn=tid[l];
        return;
    }
    build(lson,l,m);
    build(rson,m+1,r);
    pushup(o);
}
int query(int o,int l,int r,int ql,int qr,int flag)//1 mx 0 mn
{
    if(ql>qr)
    {
        if(flag) return 0;
        else return maxn;
    }
    if(ql<=l&&qr>=r)
        return ret(o,flag);
    if(qr<=m)
        return query(lson,l,m,ql,qr,flag);
    if(ql>m)
        return query(rson,m+1,r,ql,qr,flag);
    if(flag)
        return max(query(lson,l,m,ql,qr,flag),query(rson,m+1,r,ql,qr,flag));
    else
        return min(query(lson,l,m,ql,qr,flag),query(rson,m+1,r,ql,qr,flag));
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int j;
        scanf("%d",&j);
        addedge(j,i);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    build(1,1,n);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==r) printf("%d %d\n",l,d_mx);
        int mx=query(1,1,n,l,r,1);
        int mn=query(1,1,n,l,r,0);
        mx=rk[mx];
        mn=rk[mn];
        int cmx=max(query(1,1,n,l,mx-1,1),query(1,1,n,mx+1,r,1));
        int cmn=min(query(1,1,n,l,mn-1,0),query(1,1,n,mn+1,r,0));
        cmx=rk[cmx];
        cmn=rk[cmn];
        int lca1=LCA(mx,cmn);
        int lca2=LCA(mn,cmx);
        if(d[lca1]<d[lca2])
            printf("%d %d\n",mx,d[lca2]);
        else
            printf("%d %d\n",mn,d[lca1]);
    }
}
