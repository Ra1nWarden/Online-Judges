#include <cstdio>
#include <algorithm>
#define MAXN 1000005

using namespace std;

int s[MAXN], p[MAXN], h[MAXN];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &p[i]);
    for(int i = 0; i < n; i++)
      scanf("%d", &s[i]);
    int height = s[0];
    for(int i = 0; i < n; i++) {
      if(height < p[i])
	height = p[i];
      else if(height > s[i])
	height = s[i];
      h[i] = height;
    }
    height = s[n-1];
    int ans = 0;
    for(int i = n - 1; i > -1; i--) {
      if(height < p[i])
	height = p[i];
      else if(height > s[i])
	height = s[i];
      ans += min(height, h[i]) - p[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
