#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 5000;
int v[maxn+5], w[maxn+5];
int dp[maxn+5][maxn+5];
int n, vn, wn;

int main() {
    scanf("%d", &n);
    vn = wn = 0;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x == 1) {
            v[vn++] = i;
        } else {
            w[wn++] = i;
        }
    }
    int ans = -1;
    for(int i = 0; i <= wn; i++) {
        for(int j = 0; j <= min(i, vn); j++) {
            if(j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j-1] + abs(w[i-1] - v[j-1]);
                if(j <= i - 1)
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
            if(j == vn) {
                ans = ans == -1 ? dp[i][j] : min(ans, dp[i][j]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}