/**
 * @Samaritan
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e4 + 5;
int arr[N];

int main(){
    int k, id, x, y, n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d", &arr[i]);
    }
    int ans = 0;
    int pos = 1, to = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] > to) to = arr[i];
        if (i < to) continue;
        if (i == to) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
