#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
const int maxh = 2000;
int n, h, l, r;
int v[maxn+5];
int dp[maxh+5][maxn+5];

int f(int a, int b) {
    if(dp[a][b] != -1) {
        return dp[a][b];
    }
    if(b == n) {
        return dp[a][b] = 0;
    }
    int idx = (a + v[b]) % h;
    int ans = f(idx, b+1);
    if(idx >= l && idx <= r) {
        ans++;
    }
    int idx2 = (a + v[b] - 1) % h;
    int ans2 = f(idx2, b+1);
    if(idx2 >= l && idx2 <= r) {
        ans2++;
    }
    return dp[a][b] = max(ans, ans2);
}

int main() {
    scanf("%d %d %d %d", &n, &h, &l, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0, 0));
    return 0;
}