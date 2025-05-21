#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int r, g, b;
const int maxn = 200;
int rv[maxn+5], gv[maxn+5], bv[maxn+5];
long long dp[maxn+5][maxn+5][maxn+5];

long long f(int i, int j, int k) {
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(i == 0) {
        if(j == 0 || k == 0) {
            return dp[i][j][k] = 0;
        }
        return dp[i][j][k] = f(i, j - 1, k -1) + (gv[j-1] * bv[k-1]);
    }
    if(j == 0) {
        if(i == 0 || k == 0) {
            return dp[i][j][k] = 0;
        }
        return dp[i][j][k] = f(i - 1, j, k - 1) + (rv[i-1] * bv[k-1]);
    }
    if(k == 0) {
        if(i == 0 || j == 0) {
            return dp[i][j][k] = 0;
        }
        return dp[i][j][k] = f(i - 1, j - 1, k) + (rv[i-1] * gv[j-1]);
    }
    long long ij = f(i-1, j-1, k) + (rv[i-1] * gv[j-1]);
    long long ik = f(i-1, j, k-1) + (rv[i-1] * bv[k-1]);
    long long jk = f(i, j-1, k-1) + (gv[j-1] * bv[k-1]);
    return dp[i][j][k] = max(ij, max(ik, jk));
}

int main () {
    scanf("%d %d %d", &r, &g, &b);
    for(int i = 0; i < r; i++) {
        scanf("%d", &rv[i]);
    }
    sort(rv, rv+r);
    for(int i = 0; i < g; i++) {
        scanf("%d", &gv[i]);
    }
    sort(gv, gv+g);
    for(int i = 0; i < b; i++) {
        scanf("%d", &bv[i]);
    }
    sort(bv, bv+b);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", f(r, g, b));
    return 0;
}