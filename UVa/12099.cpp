#include <cstdio>
#include <algorithm>
#define MAXN 75
#define MAXW 2200
#define INF 2e9

using namespace std;

typedef pair<int, int> book;

bool _cmp(const book& a, const book& b) {
  return a.first > b.first;
}

book books[MAXN];
int n;
int dp[2][MAXW][MAXW];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &books[i].first, &books[i].second);
      sum += books[i].second;
    }
    sort(books, books+n, _cmp);
    
    for(int i =0 ; i < 2; i++) {
      for(int j = 0; j <= n * 30; j++) {
	for(int k = 0; k <= n * 30; k++) {
	  dp[i][j][k] = INF;
	}
      }
    }

    dp[1][0][0] = 0;

    int ans = INF;

    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= n * 30; j++) {
	for(int k = 0; k <= n * 30; k++) {
	  if(i < n && dp[i&1][j][k] != INF) {
	    dp[(i+1)&1][j][k] = min(dp[(i+1)&1][j][k], dp[i&1][j][k]);
	    dp[(i+1)&1][j+books[i].second][k] = min(dp[(i+1)&1][j+books[i].second][k], j == 0 ? dp[i&1][j][k] + books[i].first : dp[i&1][j][k]);
	    dp[(i+1)&1][j][k+books[i].second] = min(dp[(i+1)&1][j][k+books[i].second], k == 0 ? dp[i&1][j][k] + books[i].first : dp[i&1][j][k]);
	    if(i == n - 1) {
	      if(j != 0 && k != 0)
		ans = min(ans, max(max(j, k), (sum - j - k)) * (books[0].first + dp[(i+1)&1][j][k]));
	      
	      if(k != 0)
		ans = min(ans, max(max(j+books[i].second, k), (sum - j - k - books[i].second)) * (books[0].first + dp[(i+1)&1][j+books[i].second][k]));
	      
	      if(j != 0)
		ans = min(ans, max(max(j, k+books[i].second), (sum - j - k - books[i].second)) * (books[0].first + dp[(i+1)&1][j][k+books[i].second]));
	    }
	  }
	}
      }
    }
    
    printf("%d\n", ans);
  }
  return 0;
}
