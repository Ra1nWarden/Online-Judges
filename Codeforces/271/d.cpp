#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 100000;
int dp[maxn+5];
int t, k;

void init() {
    for(int i = 0; i <= maxn; i++) {
        if(i < k) {
            dp[i] = 1;
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-k]) % mod;
    }
    for(int i = 1; i <= maxn; i++) {
        dp[i] = (dp[i] + dp[i-1]) % mod;
    }
}

int main () {
    scanf("%d %d", &t, &k);
    init();
    while(t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = dp[b] - dp[a-1];
        if(ans < 0)
            ans += mod;
        ans %= mod;
        printf("%d\n", ans);
    }
    return 0;
}