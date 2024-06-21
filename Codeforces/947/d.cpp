#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 2e5;
vector<int> adj_mat[maxn+5];
int fa[maxn+5];
int n, a, b;

void init() {
    for(int i = 1; i <= n; i++)
        adj_mat[i].clear();
}

int solve() {
    memset(fa, -1, sizeof fa);
    fa[a] = a;
    queue<int> q;
    q.push(a);
    while(fa[b] == -1 && !q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj_mat[u].size(); i++) {
            int v = adj_mat[u][i];
            if(fa[v] != -1)
                continue;
            fa[v] = u;
            q.push(v);
        }
    }
    vector<int> chain;
    int u = b;
    while(u != a) {
        chain.push_back(u);
        u = fa[u];
    }
    chain.push_back(u);
    int ans = chain.size() / 2;
    int start = chain[ans];

    int d = 0;
    memset(fa, -1, sizeof fa);
    fa[start] = 0;
    queue<int> qq;
    qq.push(start);
    while(!qq.empty()) {
        int u = qq.front();
        qq.pop();
        for(int i = 0; i < adj_mat[u].size(); i++) {
            int v = adj_mat[u][i];
            if(fa[v] != -1)
                continue;
            fa[v] = fa[u] + 1;
            qq.push(v);
            d = max(d, fa[v]);
        }
    }

    return ans + 2 * (n - 1) - d;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d %d", &n, &a, &b);
        init();
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj_mat[u].push_back(v);
            adj_mat[v].push_back(u);
        }
        printf("%d\n", solve());
    }
    return 0;
}