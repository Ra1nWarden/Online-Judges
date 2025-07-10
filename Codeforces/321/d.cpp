#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 18;
int n, m, k;
int v[maxn + 5];
long long dp[1 << maxn][maxn + 5];
int b[maxn + 5][maxn + 5];
bool vis[1 << maxn];

int check(int u) {
    if (vis[u])
        return false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (u & (1 << i)) {
            cnt++;
        }
    }
    return cnt <= m;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    memset(b, 0, sizeof(b));
    for (int i = 0; i < k; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        b[x][y] = c;
    }

    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    dp[0][0] = 0;
    queue<int> q;
    q.push(0);
    vis[0] = true;
    long long ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (u & (1 << i)) {
                if ((u ^ (1 << i)) == 0) {
                    dp[u][i + 1] = v[i + 1];
                    ans = max(ans, dp[u][i+1]);
                    continue;
                }
                long long cur = 0;
                for (int j = 0; j < n; j++) {
                    if (j == i)
                        continue;
                    if (u & (1 << j)) {
                        cur = max(cur, dp[u ^ (1 << i)][j + 1] + v[i + 1] + b[j + 1][i + 1]);
                    }
                }
                dp[u][i + 1] = cur;
                ans = max(ans, cur);
            } else {
                int uu = u | (1 << i);
                if (check(uu)) {
                    vis[uu] = true;
                    q.push(uu);
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}