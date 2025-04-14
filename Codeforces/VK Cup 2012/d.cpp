#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 50000;
const int maxk = 500;
vector<int> adj[maxn+5];
int fa[maxn+5];
int vis[maxn+5];
int n, k;
long long dp[maxn+5][maxk+5];

void update_node(int u) {
    dp[u][0] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(fa[u] == v)
            continue;
        for(int len = 0; len < k; len++) {
            dp[u][len+1] += dp[v][len];
        }
    }
}

void init_tree() {
    memset(vis, -1, sizeof vis);
    stack<int> st;
    st.push(1);
    fa[1] = 0;
    vis[1] = 0;
    while(!st.empty()) {
        int u = st.top();
        if(vis[u] == 1) {
            update_node(u);
            st.pop();
        }
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(vis[v] != -1) {
                continue;
            }
            fa[v] = u;
            st.push(v);
            vis[v] = 0;
        }
        vis[u] = 1;
    }
}

long long calc() {
    long long ans = 0;
    for(int u = 1; u <= n; u++) {
        ans += dp[u][k];
        long long cur = 0;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(fa[u] == v)
                continue;
            for(int x = 1; x < k; x++) {
                cur += dp[v][x - 1] * (dp[u][k-x] - dp[v][k-x-1]);
            }
        }
        cur /= 2;
        ans += cur;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    int u, v;
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, 0, sizeof dp);
    init_tree();
    printf("%lld\n", calc());
    return 0;
}