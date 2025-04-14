#include <cstdio>
#include <cstring>

using namespace std;

int n1, n2, k1, k2;
const int mod = 100000000;
const int maxn = 100;
int dp[maxn+5][maxn+5][11][2];

int f(int a, int b, int c, int d) {
    if(dp[a][b][c][d] != -1) {
        return dp[a][b][c][d];
    }
    if(a + b == 0) {
        return dp[a][b][c][d] = 1;
    }
    int cnt = 0;
    if(d == 0) {
        if(c + 1 < k1 && a > 0) {
            cnt = (cnt + f(a-1, b, c+1, 0)) % mod;
        }
        if(b > 0) {
            cnt = (cnt + f(a, b-1, 0, 1)) % mod;
        }
    } else {
        if(c + 1 < k2 && b > 0) {
            cnt = (cnt + f(a, b-1, c+1, 1)) % mod;
        }
        if(a > 0) {
            cnt = (cnt + f(a-1, b, 0, 0)) % mod;
        }
    }
    return dp[a][b][c][d] = cnt;
}

int main() {
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    memset(dp, -1, sizeof dp);
    printf("%d\n", (f(n1-1, n2, 0, 0) + f(n1, n2-1, 0, 1)) % mod);
    return 0;
}