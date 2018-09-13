/*
 * @Samaritan_infi
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
char arr[N];

struct node {
    int num_1, num_0, up, down, lazy;
    node () { lazy = 0; }
    node (int a, int b, int c, int d) {
        num_1 = a; num_0 = b;
        up = c; down = d;
        lazy = 0;
    }
};

node tree[N << 2];
#define lson x<<1
#define rson x<<1|1
inline void push_up (int x) {
    tree[x] = node(tree[lson].num_1 + tree[rson].num_1,
                   tree[lson].num_0 + tree[rson].num_0,
        max(tree[lson].num_0 + tree[rson].up, tree[lson].up + tree[rson].num_1),
        max(tree[lson].num_1 + tree[rson].down, tree[lson].down + tree[rson].num_0));
}
inline void push_down(int x) {
    if (tree[x].lazy) {
        swap(tree[lson].num_0, tree[lson].num_1);
        swap(tree[lson].up, tree[lson].down);
        tree[lson].lazy ^= 1;
        swap(tree[rson].num_0, tree[rson].num_1);
        swap(tree[rson].up, tree[rson].down);
        tree[rson].lazy ^= 1;
        tree[x].lazy = 0;
    }
}
void build (int l, int r, int x) {
    if (l == r) {
        int num = arr[l] == '4' ? 0 : 1;
        tree[x] = node(num, num ^ 1, 1, 1);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    push_up(x);
}

void modify (int x, int l, int r, int L, int R) {
    if (L <= l && r <= R) {\
        tree[x].lazy ^= 1;
        swap(tree[x].num_0, tree[x].num_1);
        swap(tree[x].down, tree[x].up);
        return;
    }
    int mid = (l + r) >> 1;
    push_down(x);
    if (L <= mid) modify(lson, l, mid, L, R);
    if (mid < R) modify(rson, mid + 1, r, L, R);
    push_up(x);
}

int main () {
    int n, m; scanf("%d %d", &n, &m);
    scanf("%s", arr + 1);
    build(1, n, 1);
    char op[10];
    int l, r;
    while (m --) {
        scanf("%s", op);
        if (op[0] == 's') {
            scanf("%d %d", &l, &r);
            modify(1, 1, n, l, r);
        } else {
            printf("%d\n", tree[1].up);
        }
        //for (int i = 1; i <= n << 1; i ++) cout << tree[i].num_0 << " " << tree[i].num_1 << endl;
    }
    return 0;
}
