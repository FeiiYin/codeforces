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
char arr[200][200];
//string arr[200];
bool cmp(char a[], char b[]) {
    int al = strlen(a);
    int bl = strlen(b);
//    int k = min(al, bl);
//    for(int i = 0; i < k; i ++) {
//        if(a[i] == b[i]) continue;
//        if(a[i] < b[i]) return true;
//        return false;
//    }
    return al < bl;
}
pair<int, int> len[200];

bool check(char a[], char b[], int id) {
    int bl = strlen(b);
    for(int i = id; i < id + bl; i ++) {
        if(a[i] != b[i - id]) return false;
    }
    return true;
}

int main() {
    int n = read();

    for(int i = 0; i < n; i ++) {
        scanf("%s", arr[i]);
        len[i].first = strlen(arr[i]);
        len[i].second = i;
        //cin >> arr[i];
    }
    //sort(arr[0], arr[0] + n, cmp);
    sort(len, len + n);
    //for(int i = 0; i < n; i ++) cout << len[i].first << " " << len[i].second << endl;

    bool flag = true;

    for(int i = 0; i < n; i ++) {
        int id = len[i].second;
        for(int j = 0; j < i; j ++) {
            int bid = len[j].second;
            int al = len[i].first - len[j].first;
            //cout << al << endl;
            bool f = false;
            for(int k = 0; k <= al; k ++) {

                if(check(arr[id], arr[bid], k)) {
                    f = true;
                    break;
                } else {
                    continue;
                }
            }
            if(f) continue;
            else {
//                cout << i << " " << j << endl;
//                cout << id << " " << bid << endl;
//printf("%s\n%s\n", arr[id], arr[bid]);
//cout << al << endl;
                flag = false;
                break;
            }
        }
        if(! flag) break;
    }

    if(flag) {
        puts("YES");
        for(int i = 0; i < n; i ++) {
            printf("%s\n", arr[ len[i].second ]);
        }
    } else {
        puts("NO");
    }
	return 0;
}
