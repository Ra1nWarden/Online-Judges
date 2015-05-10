#include <bits/stdc++.h>
#define MAXN 1005

using namespace std;

char board[MAXN][MAXN];
int n, m;
int cnt[4*MAXN];
int height[MAXN][MAXN];
typedef pair<int, int> II;
II s[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++)
      scanf("%s\n", board[i]);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
	if(i == 0)
	  height[i][j] = board[i][j] == '#' ? 0 : 1;
	else
	  height[i][j] = board[i][j] == '#' ? 0 : height[i-1][j] + 1;
      }
    }
    int rear;
    for(int i = 0; i < n; i++) {
      rear = 0;
      for(int j = 0; j < m; j++) {
	int nexth = height[i][j];
	int c = j;
	if(nexth != 0) {
	  while(rear > 0) {
	    if(nexth <= s[rear-1].first) {
	      c = s[rear-1].second;
	      rear--;
	    }
	    else
	      break;
	  }
	  if(rear == 0 || s[rear-1].first - s[rear-1].second < nexth - c)
	    s[rear++] = make_pair(nexth, c);
	  II nextn = s[rear-1];
	  //printf("at (%d, %d), nextn is (%d, %d)\n", i, j, nextn.second, nextn.first);
	  cnt[2*(nextn.first - nextn.second + j + 1)]++;
	} else {
	  rear = 0;
	}
      }
    }
    for(int i = 4; i <= (m+n)*2; i++) {
      if(cnt[i] > 0)
	printf("%d x %d\n", cnt[i], i);
    }
  }
  return 0;
}
