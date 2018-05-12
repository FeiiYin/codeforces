/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vec;
typedef vector<vec> mat;
 
const int MOD = 1000 * 1000 * 1000 + 7;
 
int add(int x, int y)
{
    int z = x + y;
    while(z >= MOD)
        z -= MOD;
    return z;   
}
 
int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}
 
vec mul(const vec& a, const mat& b)
{
    int n = a.size();
    vec c(n, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c[i] = add(c[i], mul(a[j], b[j][i]));
    return c;
}
 
mat mul(const mat& a, const mat& b)
{
    int n = a.size();
    mat c(n, vec(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                c[i][k] = add(c[i][k], mul(a[i][j], b[j][k]));
    return c;
}
 
int main() { 
    int x, n;
    cin >> n >> x;
    string s;
    cin >> s;
    vector<int> p(n);
    for(int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while(s[j] != s[i] && j > 0)
        {
            j = p[j - 1];
        }
        if(s[j] == s[i])
            j++;
        p[i] = j;
    }
    vector<vector<int> > a(n + 1, vector<int>(2, 0));
    a[n][0] = a[n][1] = n;
    for(int i = 0; i <= n; i++)
    {
        if (s[i] == '0')
            a[i][0] = i + 1;
        else if (i > 0)
            a[i][0] = a[p[i - 1]][0];
        if (s[i] == '1')
            a[i][1] = i + 1;
        else if (i > 0)
            a[i][1] = a[p[i - 1]][1];
    }
    vec v(n + 2, 0);
    v[0] = 1;
    vector<mat> f;
    mat f0(n + 2, vec(n + 2, 0));
    for(int i = 0; i < n + 1; i++)
    {
        f0[i][i] = add(f0[i][i], 1);
        int z = a[i][0];
        f0[i][z] = add(f0[i][z], 1);
        if (z == n)
            f0[i][n + 1] = add(f0[i][n + 1], 1);
    }
    f0[n + 1][n + 1] = add(f0[n + 1][n + 1], 2);
    mat f1(n + 2, vec(n + 2, 0));
    for(int i = 0; i < n + 1; i++)
    {
        f1[i][i] = add(f1[i][i], 1);
        int z = a[i][1];
        f1[i][z] = add(f1[i][z], 1);
        if (z == n)
            f1[i][n + 1] = add(f1[i][n + 1], 1);
    }
    
    f1[n + 1][n + 1] = add(f1[n + 1][n + 1], 2);
    f.push_back(f0);
    f.push_back(f1);
    for(int i = 2; i <= x; i++)
        f.push_back(mul(f[i - 1], f[i - 2]));
    v = mul(v, f[x]);
    cout << v.back() << endl;
    return 0;
}
