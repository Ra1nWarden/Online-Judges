#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 998244353;
const int maxn = 100000;
int v[maxn+5];
int n;
int dp[2][201][2];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  memset(dp, 0, sizeof dp);
  for(int i = 0; i < n; i++) {
    if(v[i] == -1) {
      for(int cur = 1; cur <= 200; cur++) {
	dp[i&1][cur][0] = dp[i&1][cur][1] = 0;
	if(i == 0) {
	  if(v[i+1] == -1 || cur <= v[i+1]) {
	    dp[i&1][cur][0] = 1;
	  }
	} else if(i == n-1) {
	  dp[i&1][cur][1] = (dp[(i&1)^1][cur][0] + dp[(i&1)^1][cur][1]) % mod;
	  for(int prev = cur+1; prev <= 200; prev++) {
	    dp[i&1][cur][1] = (dp[i&1][cur][1] + dp[(i&1)^1][prev][1]) % mod;
	  }
	} else {
	  if(v[i+1] == -1) {
	    for(int prev = 1; prev <= 200; prev++) {
	      if(cur < prev) {
		dp[i&1][cur][1] = (dp[i&1][cur][1] + dp[(i&1)^1][prev][1]) % mod;
	      } else if(cur == prev) {
		dp[i&1][cur][1] = ((dp[i&1][cur][1] + dp[(i&1)^1][prev][1]) % mod + dp[(i&1)^1][prev][0]) % mod;
	      } else {
		dp[i&1][cur][0] = ((dp[i&1][cur][0] + dp[(i&1)^1][prev][1]) % mod + dp[(i&1)^1][prev][0]) % mod;
	      }
	    }
	  } else {
	    for(int prev = 1; prev <= 200; prev++) {
	      if(cur > max(prev, v[i+1]))
		continue;
	      if(cur < prev) {
		dp[i&1][cur][1] = (dp[i&1][cur][1] + dp[(i&1)^1][prev][1]) % mod;
	      } else if(cur == prev) {
		dp[i&1][cur][1] = ((dp[i&1][cur][1] + dp[(i&1)^1][prev][1]) % mod + dp[(i&1)^1][prev][0]) % mod;
	      } else {
		dp[i&1][cur][0] = ((dp[i&1][cur][0] + dp[(i&1)^1][prev][1]) % mod + dp[(i&1)^1][prev][0]) % mod;
	      }
	    }
	  }
	}
      }
    } else {
      for(int cur = 1; cur <= 200; cur++)
	dp[i&1][cur][0] = dp[i&1][cur][1] = 0;
      if(i == 0) {
	dp[i&1][v[i]][0] = 1;
      } else {
	if(v[i-1] == -1) {
	  for(int prev = 1; prev <= 200; prev++) {
	    if(v[i] < prev) {
	      dp[i&1][v[i]][1] = (dp[i&1][v[i]][1] + dp[(i&1)^1][prev][1]) % mod;
	    } else if(v[i] == prev) {
	      dp[i&1][v[i]][1] = ((dp[i&1][v[i]][1] + dp[(i&1)^1][prev][1]) % mod + dp[(i&1)^1][prev][0]) % mod;
	    } else {
	      dp[i&1][v[i]][0] = ((dp[i&1][v[i]][0] + dp[(i&1)^1][prev][0]) % mod + dp[(i&1)^1][prev][1]) % mod;
	    }
	  }
	} else {
	  if(v[i] < v[i-1]) {
	    dp[i&1][v[i]][1] = (dp[i&1][v[i]][1] + dp[(i&1)^1][v[i-1]][1]) % mod;
	  } else if(v[i] == v[i-1]) {
	    dp[i&1][v[i]][1] = ((dp[i&1][v[i]][1] + dp[(i&1)^1][v[i-1]][1]) % mod + dp[(i&1)^1][v[i-1]][0]) % mod;
	  } else {
	    dp[i&1][v[i]][0] = ((dp[i&1][v[i]][0] + dp[(i&1)^1][v[i-1]][0]) % mod + dp[(i&1)^1][v[i-1]][1]) % mod;
	  }
	}
      }
    }
  }
  
  int ans = 0;
  for(int cur = 1; cur <= 200; cur++) {
    ans = (ans + dp[(n-1)&1][cur][1]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
