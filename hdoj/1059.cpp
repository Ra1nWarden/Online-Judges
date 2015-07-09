#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 120050

using namespace std;

int cnt[10];
int sum;
int dp[7][MAXN];

bool input() {
  bool ret = false;
  sum = 0;
  for(int i = 1; i <= 6; i++) {
    scanf("%d", &cnt[i]);
    sum += cnt[i] * i;
    if(cnt[i] != 0) {
      ret = true;
    }
  }
  return ret;
}

int main() {
  int kase = 1;
  while(input()) {
    if(sum % 2 == 1) {
      printf("Collection #%d:\n", kase++);
      printf("Can't be divided.\n\n");
      continue;
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    int v = sum / 2;
    for(int i = 1; i <= 6; i++) {
      for(int j = 0; j <= v; j++) {
	if(dp[i-1][j] >= 0)
	  dp[i][j] = cnt[i];
	else
	  dp[i][j] = -1;
      }
      
      for(int j = 0; j <= v - i; j++) {
	if(dp[i][j] > 0) {
	  dp[i][j+i] = max(dp[i][j+i], dp[i][j] - 1);
	}
      }
    }

    if(dp[6][v] > -1) {
      printf("Collection #%d:\n", kase++);
      printf("Can be divided.\n\n");
    } else {
      printf("Collection #%d:\n", kase++);
      printf("Can't be divided.\n\n");
    }
  }
  return 0;
}
