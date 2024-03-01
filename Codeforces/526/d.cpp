#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> II;
const int maxn = 3e5;
int wv[maxn+5];
vector<II> adj_mat[maxn+5];
int n;
long long dp[maxn+5];
int fa[maxn+5];
bool vis[maxn+5];

long long f(int u) {
    if(vis[u])
        return dp[u];
    long long ans = wv[u];

    for(int i = 0; i < adj_mat[u].size(); i++) {
        int v = adj_mat[u][i].first;
        if(v == fa[u])
            continue;
        int c = adj_mat[u][i].second;
        ans = max(ans, f(v) - c + wv[u]);
    }

    vis[u] = true;
    return dp[u] = ans;
}

void fill_fa(int u, int p) {
    fa[u] = p;
    for(int i = 0; i < adj_mat[u].size(); i++) {
        int v = adj_mat[u][i].first;
        if(v == p)
            continue;
        fill_fa(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &wv[i]);
    }
    for(int i = 0; i < n-1; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj_mat[u].push_back(make_pair(v, c));
        adj_mat[v].push_back(make_pair(u, c));
    }
    
    fill_fa(1, 0);

    memset(vis, false, sizeof vis);
    long long ans = 0LL;
    for(int u = 1; u <= n; u++) {
        ans = max(ans, f(u));
        priority_queue<long long> pq;
        for(int i = 0; i < adj_mat[u].size(); i++) {
            int v = adj_mat[u][i].first;
            if(v == fa[u])
                continue;
            pq.push(f(v) - adj_mat[u][i].second);
        }
        if(pq.size() > 1) {
            long long t1 = pq.top();
            pq.pop();
            long long t2 = pq.top();
            ans = max(ans, wv[u] + t1 + t2);
        }
    }
    printf("%lld\n", ans);
    return 0;
}