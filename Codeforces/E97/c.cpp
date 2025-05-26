#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 200;
int v[maxn+5];
int dp[maxn+5][maxn*2+5];
int n;

int main() {
   int q;
   scanf("%d", &q);
   while (q--) {
      scanf("%d", &n);
      for (int i = 0; i < n; i++) {
         scanf("%d", &v[i]);
      }
      sort(v, v + n);
      dp[0][0] = 0;
      for(int i = 0; i <= n; i++) {
         for(int j = i; j <= 2*n; j++) {
             if(i == 0) {
                dp[i][j] = 0;
                continue;
             }
             if(j == i)
                dp[i][j] = dp[i-1][j-1] + abs(v[i-1] - j);
             else {
                dp[i][j] = min(dp[i-1][j-1] + abs(v[i-1] - j), dp[i][j-1]);
             }
         }
      }
      printf("%d\n", dp[n][2*n]);
   }
}