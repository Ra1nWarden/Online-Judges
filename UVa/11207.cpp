#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n) != EOF && n) {
    int v[n][2];
    for(int i = 0; i < n; i++) {
      scanf("%d %d", &v[i][0], &v[i][1]);
    }
    double maxval = 0;
    int maxi = -1;
    for(int i = 0; i < n; i++) {
      int m = max(v[i][0], v[i][1]);
      int n = min(v[i][0], v[i][1]);
      if(m >= 4 * n) {
	if(maxval < n) {
	  maxval = n;
	  maxi = i + 1;
	}
      } 
      if((double) m / 4 <= n) {
	if(maxval < (double) m / 4) {
	  maxval = (double) m / 4;
	  maxi = i + 1;
	}
      }
      if(maxval < (double) n / 2) {
	maxval = (double) n / 2;
	maxi = i + 1;
      }
    }
    printf("%d\n", maxi);
  }
  return 0;
}
