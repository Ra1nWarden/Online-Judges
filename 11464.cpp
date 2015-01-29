#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 16
#define INF 2e9

using namespace std;

int n;
int v[MAXN][MAXN];
int vc[MAXN][MAXN];

// nth bit of x
int bitat(int x, int n) {
  return (x >> n) & 1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 1; et <= tc; et++) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	scanf("%d", &v[i][j]);
      }
    }
    int result = INF;
    for(int change = 0; change < (1 << n); change++) {
      int res = 0;
      memcpy(vc, v, sizeof v);
      // try to fill first row first
      bool ok = true;
      for(int j = 0; j < n; j++) {
	if(vc[0][j] == 1 && bitat(change, j) == 0) {
	  ok = false;
	  break;
	} else if(vc[0][j] == 0 && bitat(change, j) == 1) {
	  vc[0][j] = 1;
	  res++;
	}
      }
      if(!ok)
	continue;
      for(int i = 1; i < n; i++) {
	int ci = i - 1;
	// check ci row
	for(int cj = 0; cj < n; cj++) {
	  int sum = 0;
	  if(ci - 1 > -1)
	    sum += vc[ci-1][cj];
	  if(cj - 1 > -1)
	    sum += vc[ci][cj-1];
	  if(cj + 1 < n)
	    sum += vc[ci][cj+1];
	  if(sum % 2 == 0 && vc[i][cj] == 1) {
	    ok = false;
	    break;
	  } else if(sum % 2 == 1 && vc[i][cj] == 0) {
	    res++;
	    vc[i][cj] = 1;
	  }
	}
	if(!ok)
	  break;
      }
      if(!ok)
	continue;
      // check last row
      for(int cj = 0; cj < n; cj++) {
	int sum = 0;
	if(n - 2 > -1)
	  sum += vc[n-2][cj];
	if(cj - 1 > -1)
	  sum += vc[n-1][cj-1];
	if(cj + 1 < n)
	  sum += vc[n-1][cj+1];
	ok = (sum % 2 == 0);
	if(!ok)
	  break;
      }
      if(ok) {
	result = min(result, res);
      }
    }
    if(result != INF)
      printf("Case %d: %d\n", et, result);
    else
      printf("Case %d: -1\n", et);
  }
  return 0;
}
