#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
char str[maxn+5];
int cost[maxn+5];
int n;
long long dp[maxn+5][5];
const long long inf = 1e18;
const char hard[] = "hard";

int main() {
    scanf("%d\n", &n);
    scanf("%s\n", str);
    for(int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 4; j++) {
            if(j > 0 && i == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = inf;
            }
        }
    }

    for(int j = 1; j <= 4; j++) {
        for(int i = 1; i <= n; i++) {
            if(str[i-1] == hard[j-1]) {
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j] + cost[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
            //printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
        }
    }

    printf("%lld\n", *min_element(dp[n] + 1, dp[n] + 5));

    return 0;
}