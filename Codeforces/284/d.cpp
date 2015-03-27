#include <cstdio>
#include <iostream>
#include <cmath>
#define EPS 1e-15

using namespace std;

// dp[time][song]
double dp[5001][5001];
int songs[5001][2];
int n, t;

int leastfinish(int time) {
  for(int i = 0; i < n; i++) {
    time -= songs[i][1];
    if(time < 0)
      return i;
  }
  return n;
}

int main() {
  scanf("%d %d", &n, &t);
  for(int i = 0; i < n; i++) {
    int p, ti;
    scanf("%d %d", &p, &ti);
    songs[i][0] = p;
    songs[i][1] = ti;
  }
  // at the beginning finished
  dp[0][0] = 1.0;
  for(int i = 0; i <= t; i++)
    for(int j = 1; j <= n; j++)
      dp[i][j] = 0.0;
  //cout << "done" << endl;
  for(int i = 1; i <= t; i++) {
    for(int j = 1; j <= n; j++) {
      for(int k = 1; k <= songs[j-1][1] && i - k >= 0; k++) {
	if(dp[i-k][j-1] < EPS)
	  continue;
	if(k == songs[j-1][1])
	  dp[i][j] += dp[i-k][j-1] * pow((1.0 - (double)songs[j-1][0] /  100), k-1);
	else
	  dp[i][j] += dp[i-k][j-1] * pow((1.0 - (double)songs[j-1][0] /  100), k-1) * (double)songs[j-1][0] / 100;
      }
    }
  }
  double expected = 0;

  // cout << "debug" << endl;
  // for(int i = 0; i <= t; i++) {
  //   for(int j = 0; j <= n; j++) {
  //     cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
  //   }
  // }
 
  //cout << "leastfinish " << leastfinish(t) << endl;
  for(int i = leastfinish(t); i < n; i++) {
    for(int k = 0; k < songs[i][1] && t - k >= 0; k++) {
      if(k != 0)
	expected += (i * dp[t-k][i] * pow((1.0 - (double)songs[i][0] / 100), k)); 
      else
	expected += (i * dp[t][i]);
      //cout << "finished " << i << " holding for " << k << " expected value is " << expected << endl;
    }
  }
  for(int i = 0; i <= t; i++)
    expected += n * dp[i][n];
  
  printf("%.9f\n", expected);
  return 0;
}
