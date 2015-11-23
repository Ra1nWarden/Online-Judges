#include <cstdio>

using namespace std;

const int maxn = 100;
int n, b, c;
int v[maxn+1];

int main() {
  while(scanf("%d%d%d", &n, &b, &c) != EOF) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      for(int j = 0; j < i; j++) {
	int diff = v[i] - v[j];
	if(diff < 0)
	  diff = -diff;
	if(diff % b == c) {
	  ans++;
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
