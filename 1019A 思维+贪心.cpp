/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 5;

pair<ll, int> arr[N];
int num[N], temp[N];
bool vis[N];

int main() {
    int n, party;
    scanf("%d %d", &n, &party);
    ll ans = 1e18;
    int p; ll r;
    memset(num, 0, sizeof (int) * (n + 2));
    int max_for = 0;
    for(int i = 0; i < n; i ++) {
       scanf("%d %lld", &p, &r);
       arr[i] = make_pair(r, p);
       num[p] ++;
       max_for = max(max_for, num[p]);
    }
    sort(arr, arr + n);
//    for(int i = 0; i < n; i ++)
//        cout << arr[i].first << " ";cout << endl;
    for(int i = 0; i <= max_for + 1; i ++) {
        memset(vis, 0, sizeof (vis[0]) * (n + 2));
        for(int j = 1; j <= party; j ++) temp[j] = num[j];
        ll now_ans = 0;
        int now_num = 0;
        for(int j = 0; j < n; j ++) if(arr[j].second != 1 && num[1] + i <= temp[ arr[j].second ]) {
            temp[ arr[j].second ] --;
            now_num ++;
            now_ans += arr[j].first;
            vis[j] = true;
        }
        if(now_num > i) continue;
        for(int j = 0; j < n && now_num < i; j ++) if(! vis[j] && arr[j].second != 1) {
            now_num ++;
            now_ans += arr[j].first;
        }
//        cout << now_ans << endl;
        ans = min(ans, now_ans);
    }
    printf("%lld\n", ans);
    return 0;
}
