#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXK 65
#define MAXB 110

using namespace std;

long long dp[MAXB][MAXK];

void init() {
  memset(dp, 0, sizeof dp);
  for(int i = 1; i <= 63; i++) {
    for(int j = 1; j <= 63; j++) {
      dp[i][j] = dp[i-1][j-1] + 1 + dp[i][j-1];
    }
  }
}

int main() {

  init();
  int k;
  long long n;
  while(scanf("%d %lld", &k, &n) != EOF && (k || n)) {
    bool found = false;
    k = min(k, 63);
    for(int i = 0; i <= 63; i++) {
      if(dp[k][i] >= n) {
	found = true;
	printf("%d\n", i);
	break;
      }
    }
    if(!found) {
      printf("More than 63 trials needed.\n");
    }
    
  }

  return 0;
}
