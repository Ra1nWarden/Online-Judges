#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 2e5;
long long v[maxn + 5];
long long diff[maxn + 5];
long long dp[maxn + 5][20];
int n;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long query(int i, int len) {
    int j;
    for (j = 0; (1 << j) <= len; j++) {
    }
    j--;
    return gcd(dp[i][j], dp[i + len - (1 << j)][j]);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &v[i]);
            if (i) {
                diff[i] = abs(v[i] - v[i - 1]);
                dp[i][0] = diff[i];
            }
        }

        for (int i = 1; (1 << i) <= n; i++) {
            int len = 1 << i;
            for (int j = 1; j + len - 1 < n; j++) {
                dp[j][i] = gcd(dp[j][i - 1], dp[j + len / 2][i - 1]);
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            int l = 1, r = n - i;
            while (l < r) {
                int mid = ((l + r) >> 1) + 1;
                if (query(i, mid) > 1) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (query(i, l) > 1) {
                ans = max(ans, l);
            }
        }

        printf("%d\n", ans + 1);
    }
    return 0;
}