#include <cstdio>
#include <algorithm>
#define MAXK 5010

using namespace std;

int v[MAXK];
int l[MAXK][MAXK], r[MAXK][MAXK];
int n;

bool solve() {
  for(int j = 2; j < n; j++) {
    for(int i = 1; i < j; i++) {
      if(i == 1 || l[i-1][j] == -1) {
	l[i][j] = v[i-1] < v[j] ? v[i-1] : -1;
      } else {
	if(v[i-1] < v[j]) {
	  l[i][j] = max(l[i-1][j], v[i-1]);
	} else {
	  l[i][j] = l[i-1][j];
	}
      }
    }
  }
  
  for(int i = n - 3; i > -1; i--) {
    for(int j = n - 2; j > i; j--) {
      if(j == n - 2 || r[i][j+1] == -1) {
	r[i][j] = v[j+1] > v[i] ? v[j+1] : -1;
      } else {
	if(v[j+1] > v[i]) {
	  r[i][j] = min(r[i][j+1], v[j+1]);
	} else {
	  r[i][j] = r[i][j+1];
	}
      }
    }
  }
  
  for(int i = 1; i < n; i++) {
    for(int j = i+1; j < n - 1; j++) {
      if(v[i] >= v[j] || l[i][j] == -1 || r[i][j] == -1)
	continue;
      int ii = r[i][j], jj = l[i][j];
      if(v[i] < ii && ii < jj && jj < v[j]) {
	return true;
      }
    }
  }
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    
    if(solve()) {
      printf("YES\n");
      continue;
    }
    
    reverse(v, v+n);

    if(solve()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
