#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005

using namespace std;

int n;
char buf[10];
int dp[MAXN][MAXN];
int dpc[MAXN][MAXN];

struct Node {
  int p, j, i;
  Node() {}
  bool operator<(const Node& rhs) const {
    if(p != rhs.p)
      return p > rhs.p;
    return j < rhs.j;
  }
};

Node v[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d\n", &n);
    scanf("%s\n", buf);
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &v[i].p, &v[i].j);
      v[i].i = i;
    }
    bool petra = strcmp("Petra", buf) == 0;
    sort(v, v+n);
    int ps = 0;
    Node* start = v;
    if(petra) {
      ps += v[0].p;
      start = &v[1];
      n--;
    }
    dp[1][0] = 0;
    dp[1][1] = start[0].j;
    dpc[1][0] = start[0].p;
    dpc[1][1] = 0;
    for(int i = 2; i <= n; i++) {
      for(int j = 0; j <= (i + 1) / 2; j++) {
	int nottake = dp[i-1][j];
	int nottakep = dpc[i-1][j] + start[i-1].p;
	int take = 0;
	int takep = 0;
	if(j > 0) {
	  take = dp[i-1][j-1] + start[i-1].j;
	  takep = dpc[i-1][j-1];
	}
	if(take == nottake) {
	  if(nottakep > takep) {
	    dp[i][j] = nottake;
	    dpc[i][j] = nottakep;
	  }
	  else {
	    dp[i][j] = take;
	    dpc[i][j] = takep;
	  }
	} else {
	  dp[i][j] = max(take, nottake);
	  if(take > nottake)
	    dpc[i][j] = takep;
	  else
	    dpc[i][j] = nottakep;
	}
      }
    }
    printf("%d %d\n", ps + dpc[n][(n+1)/ 2], dp[n][(n+1)/2]);
  }
  return 0;
}
