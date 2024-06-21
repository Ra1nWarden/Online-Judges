#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1e5;
int uv[maxn+5];
int vv[maxn+5];
int cv[maxn+5];
int n, m;
vector<int> adj_mat[maxn+5];
int vis[maxn+5];
int toposorted[maxn+5];
int topo_rev[maxn+5];
int ti;

bool dfs(int v, int u) {
    vis[v] = 0;
    for(int i = 0; i < adj_mat[v].size(); i++) {
        int idx = adj_mat[v][i];
        if(cv[idx] <= u) {
            continue;
        }
        if(vis[vv[idx]] == 0)
            return false;
        else if(vis[vv[idx]] == -1 && !dfs(vv[idx], u))
            return false;
    }
    vis[v] = 1;
    toposorted[--ti] = v;
    topo_rev[v] = ti;
    return true;
}

bool toposort(int u) {
    memset(vis, -1, sizeof vis);
    ti = n;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == -1) {
            if(!dfs(i, u))
                return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &uv[i], &vv[i], &cv[i]);
        adj_mat[uv[i]].push_back(i);
    }
    int l = 0, r = 1e9;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(!toposort(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    toposort(l);
    vector<int> ans;
    for(int i = 0; i < m; i++) {
        if(topo_rev[uv[i]] > topo_rev[vv[i]]) {
            ans.push_back(i+1);
        }
    }
    printf("%d %d\n", l, ans.size());
    for(int i = 0; i < ans.size(); i++) {
        if(i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}