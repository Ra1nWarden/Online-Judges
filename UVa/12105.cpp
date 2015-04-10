#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXL 55
#define MAXM 3005
#define INF 2e9

using namespace std;

int matches[] = {6,2,5,5,4,5,6,3,7,6};
int n, m;
int dp[MAXL][MAXM];
int rmd[10][MAXL]; // leading digit and the number of zeros

int main() {
  int kase = 1;
  while(scanf("%d", &n ) != EOF && n) {
    scanf("%d", &m);
    for(int i = 0; i <= n / 2; i++) {
      for(int j = 0; j < m; j++) {
	dp[i][j] = INF;
      }
    }
    dp[0][0] = 0;
    for(int i = 0; i <= n / 2; i++) {
      for(int j = 0; j < m; j++) {
	if(dp[i][j] != INF) {
	  // next digit to add
	  for(int k = 0; k < 10; k++) {
	    int newrmd = (j * 10 + k) % m;
	    dp[i+1][newrmd] = min(dp[i+1][newrmd], dp[i][j] + matches[k]);
	  }
	}
      }
    }
    
    int maxlength = 0;
    for(int i = 1; i <= n / 2; i++) {
      if(dp[i][0] <= n) {
	maxlength = max(maxlength, i);
      }
    }
    
    if(maxlength == 0) {
      printf("Case %d: -1\n", kase++);
      continue;
    }

    for(int i = 0; i < 10; i++) {
      for(int j = 0; j <= n / 2; j++) {
	if(i == 0) {
	  rmd[i][j] = 0;
	  continue;
	}
	if(j == 0) {
	  rmd[i][j] = i % m;
	} else {
	  rmd[i][j] = (rmd[i][j-1] * 10) % m;
	}
      }
    }
    

    printf("Case %d: ", kase++);

    int nn = n;
    int rr = 0;

    for(int i = 1; i <= maxlength; i++) {
      for(int digit = 9; digit >= 0; digit--) {
	if(dp[maxlength - i][(rr - rmd[digit][maxlength - i] + m) % m] <= nn - matches[digit]) {
	  printf("%c", '0' + digit);
	  nn -= matches[digit];
	  rr = (rr - rmd[digit][maxlength - i] + m) % m;
	  break;
	}
      }
    }
    printf("\n");
    
  }
  return 0;
}
