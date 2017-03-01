#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 5005

using namespace std;

int v[MAXN];
bool seen[MAXN];

int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    memset(seen, false, sizeof seen);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    bool ok = true;
    int count = 0;
    for(int i =0; i < n; i++) {
      if(seen[v[i]]) {
	ok = false;
	break;
      }
      if(i > 0) {
	if(abs(v[i-1] - v[i]) == 1) {
	  ok = false;
	  break;
	}
      }
      if(i < n - 1) {
	if(abs(v[i] - v[i+1]) == 1) {
	  ok = false;
	  break;
	}
      }
      seen[v[i]] = true;
      count++;
    }
    if(!ok || count != n)
      printf("%d is not ok!\n", n);
  }
  
  return 0;
}
