#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

const int DFS_WHITE = 0;
const int DFS_GRAY = 1;
const int DFS_BLACK = 2;

const int maxn = 200000;
vector<int> adj[maxn+5];
queue<int> next_node[maxn+5];
int n;
bool white[maxn+5];
int dp[maxn+5];
int vis[maxn+5];
int ans[maxn+5];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        white[i] = x == 1;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(vis, DFS_WHITE, sizeof(vis));
    stack<int> dfs;
    dfs.push(1);
    vis[1] = DFS_GRAY;
    while(!dfs.empty()) {
        int u = dfs.top();
        bool done = true;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(vis[v] == DFS_WHITE) {
                dfs.push(v);
                vis[v] = DFS_GRAY;
                done = false;
            }
        }
        if(done) {
            dp[u] = white[u] ? 1 : -1;
            for(int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if(vis[v] == DFS_BLACK) {
                    dp[u] += max(0, dp[v]);
                }
            }
            dfs.pop();
            vis[u] = DFS_BLACK;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int v : adj[i]) {
            next_node[i].push(v);
        }
    }

    memset(vis, DFS_WHITE, sizeof(vis));
    dfs.push(1);
    vis[1] = DFS_GRAY;
    int root = 1;
    while(!dfs.empty()) {
        int u = dfs.top();
        bool done = true;
        if(root != u) {
            dp[root] -= max(0, dp[u]);
            dp[u] += max(0, dp[root]);
            root = u;
        }
        while(!next_node[u].empty()) {
            int v = next_node[u].front();
            next_node[u].pop();
            if(vis[v] == DFS_WHITE) {
                dfs.push(v);
                vis[v] = DFS_GRAY;
                done = false;
                break;
            }
        }
        if(done) {
            dfs.pop();
            vis[u] = DFS_BLACK;
            ans[u] = dp[u];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}