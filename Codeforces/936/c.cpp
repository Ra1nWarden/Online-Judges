#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 1e5;
vector<int> adj_mat[maxn+5];
int n, k;
int fa[maxn+5];
int vis[maxn+5];
int cnt[maxn+5];

bool check(int mid) {
    memset(vis, -1, sizeof vis);
    memset(cnt, -1, sizeof cnt);
    stack<int> s;
    s.push(1);
    vis[1] = 0;
    int components = 0;
    while(!s.empty()) {
        int u = s.top();
        int cur = 1;
        bool done = true;
        for(int i = 0; i < adj_mat[u].size(); i++) {
            int v = adj_mat[u][i];
            if(vis[v] == -1) {
                s.push(v);
                vis[v] = 0;
                done = false;
            } else if(vis[v] == 1) {
                cur += cnt[v];
            }
        }
        if(done) {
            cnt[u] = cur;
            vis[u] = 1;
            s.pop();
            if(cnt[u] >= mid) {
                components++;
                cnt[u] = 0;
            }
        }
    }
    return components > k;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
            adj_mat[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj_mat[u].push_back(v);
            adj_mat[v].push_back(u);
        }
        int l = 1, r = n / (k + 1);
        while(l < r) {
            int mid = ((l + r) >> 1) + 1;
            if(check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}