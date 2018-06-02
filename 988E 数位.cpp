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

char a[30];
int num[30];
int b[20];

/// 00 25 50 75
int check(int x, int y, int len) {
    /// end with x y
    //for(int i = 0; i < 10; i ++) cout << b[i] << " "; cout << endl;
    if(b[x] == 0 || b[y] == 0) return -1;
    if(x == 0 && y == 0 && b[0] == 1) return -1;
    if(num[len - 1] == 0 && num[len - 2] == 0) return 0;

    if(num[len - 1] == x && num[len - 2] == y) return 1;

    int y_pos = -1, x_pos = -1;
    for(int i = len - 1; i >= 0; i --) {
        if(num[i] == y && y_pos == -1) y_pos = i;
        else if(num[i] == x && x_pos == -1) x_pos = i;
//        zhuyi 00
    }

    if(x_pos == len - 1) {
        if(! y_pos) {
            int zlen = 0;
            for(int i = 1; i < len; i ++) {
                if(num[i] == 0) zlen ++;
                else break;
            }

            return zlen + (len - 2 - y_pos) + 1;
        } else {
            return (len - 2 - y_pos) + 1;
        }
    }

    if(y == 0) {
        if(! x_pos) {
            int zlen = 0;
            for(int i = 1; i < len; i ++) {
                if(num[i] == 0) zlen ++;
                else break;
            }
//            int aa = zlen + (len - 1 - y_pos) + (len - 2 - x_pos);
//            int bb =
            if(y_pos == x_pos + zlen) return zlen - 1 + (len - 1 - y_pos) + (len - 2 - x_pos);
            if(x_pos > y_pos) return zlen + (len - 1 - y_pos) + (len - 2 - x_pos) + 1;
            return zlen + (len - 1 - y_pos) + (len - 2 - x_pos);
        } else {
            if(x_pos > y_pos) return (len - 1 - y_pos) + (len - 2 - x_pos) + 1;
            return (len - 1 - y_pos) + (len - 2 - x_pos);
        }
    }
//cout << " ??" << endl;
    if(! y_pos ) {
        int zlen = 0;
        for(int i = 1; i < len; i ++) {
            if(num[i] == 0) zlen ++;
            else break;
        }
//        cout << " ??" << endl;
//        cout << x << y << endl;
//        cout << y_pos << " " << x_pos << endl;
//        cout << len << endl;
        if(x_pos > y_pos) return zlen + (len - 1 - y_pos) + (len - 2 - x_pos) + 1;
        return zlen + (len - 1 - y_pos) + (len - 2 - x_pos);
    } else if(! x_pos) {
        int zlen = 0;
        for(int i = 1; i < len; i ++) {
            if(num[i] == 0) zlen ++;
            else break;
        }
        //cout << zlen << endl;
        if(x_pos > y_pos) return zlen + (len - 1 - y_pos) + (len - 2 - x_pos) + 1;
        return zlen + (len - 1 - y_pos) + (len - 2 - x_pos);
    } else {
//        cout << x << y << endl;
//        cout << y_pos << " " << x_pos << endl;
//        cout << len << endl;
        if(x_pos > y_pos) return (len - 1 - y_pos) + (len - 2 - x_pos) + 1;
        return (len - 1 - y_pos) + (len - 2 - x_pos);
    }
}

int main() {

    while(~ scanf("%s", a)) {
    int len = strlen(a);
    memset(b, 0, sizeof b);
    for(int i = 0; i < len; i ++) {
        num[i] = a[i] - '0';
        b[ a[i] - '0' ] ++;
    }
    int ans = 1e9;
    int x1 = check(0, 0, len);
    if(x1 != -1) ans = min(ans, x1);
    int x2 = check(2, 5, len);
    if(x2 != -1) ans = min(ans, x2);
    int x3 = check(7, 5, len);
    if(x3 != -1) ans = min(ans, x3);
    int x4 = check(5, 0, len);
    if(x4 != -1) ans = min(ans, x4);

  //cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;

    if(ans == 1e9) puts("-1");
    else printf("%d\n", ans);
    }
	return 0;
}
