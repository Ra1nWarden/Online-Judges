#include <cstdio>

using namespace std;

const int maxn = 17;
const int nodes = (1 << 18) + 5;
int left[nodes], right[nodes], val[nodes], op[nodes];
int v[nodes];
int n, m, p, b;

void build_tree(int u, int l, int r) {
    left[u] = l;
    right[u] = r;
    if(l == r) {
        val[u] = v[l];
        op[u] = 0;
        return;
    }
    build_tree(u << 1, l, (l + r) >> 1);
    build_tree((u << 1) | 1, ((l + r) >> 1) + 1, r);
    if(op[u << 1]) {
        val[u] = val[u << 1] ^ val[(u << 1) | 1];
        op[u] = 0;
    } else {
        val[u] = val[u << 1] | val[(u << 1) | 1];
        op[u] = 1;
    }
}

void update(int u) {
    if(left[u] == right[u]) {
        val[u] = b;
        return;
    }
    
    if(p <= ((left[u] + right[u]) >> 1)) {
        update(u << 1);
    } else {
        update((u << 1) | 1);
    }

    if(op[u << 1]) {
        val[u] = val[u << 1] ^ val[(u << 1) | 1];
    } else {
        val[u] = val[u << 1] | val[(u << 1) | 1];
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= (1 << n); i++) {
        scanf("%d", &v[i]);
    }
    build_tree(1, 1, (1 << n));
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &p, &b);
        update(1);
        printf("%d\n", val[1]);
    }
    return 0;
}