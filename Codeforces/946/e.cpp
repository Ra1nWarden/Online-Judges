#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int maxn = 100000;
long long dp[2][maxn+5];

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int m, x;
        scanf("%d %d", &m, &x);
        memset(dp, -1, sizeof dp);
        dp[0][0] = 0LL;
        set<int> s;
        s.insert(0);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int c, h;
            scanf("%d %d", &c, &h);
            int ii = i&1;
            int jj = ii^1;
            for(int each : s) {
                dp[jj][each] = max(dp[jj][each], dp[ii][each] + x);
                if(dp[ii][each] >= c) {
                    dp[jj][each+h] = max(dp[jj][each+h], dp[ii][each] - c + x);
                    s.insert(each+h);
                    ans = max(ans, each+h);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}