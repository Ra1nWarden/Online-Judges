#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2000;
long long dp[maxn+5][maxn+5];
int n;
int v[maxn+5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i <= n-len; i++) {
            if(len == 1) {
                dp[i][i+len-1] = 0;
                continue;
            }
            int diff = v[i+len-1] - v[i];
            dp[i][i+len-1] = min(dp[i][i+len-2] + diff, dp[i+1][i+len-1] + diff);
        }
    }
    printf("%lld\n", dp[0][n-1]);
}