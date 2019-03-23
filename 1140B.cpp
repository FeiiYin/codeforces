/**
`* @Samaritan
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PII pair<int, int>
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define fi  first
#define se second

const int N = 1e3 + 5;
char arr[N];



int main(){
    int n;
    scanf("%d", &n);
    while (n--) {
        int len; scanf("%d", &len);
        scanf("%s", arr);
        if (arr[0] == '>') {
            puts("0");
            continue;
        }
        if (arr[len-1] == '<') {
            puts("0");
            continue;
        }
        printf("%d\n", 1);
    }
    return 0;
}
