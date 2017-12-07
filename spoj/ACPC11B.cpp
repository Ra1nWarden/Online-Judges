#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1000;
int v0[maxn+5];
int v1[maxn+5];
int s0, s1;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &s0);
    for(int i = 0; i < s0; i++)
      scanf("%d", &v0[i]);
    sort(v0, v0 + s0);
    scanf("%d", &s1);
    for(int i = 0; i < s1; i++)
      scanf("%d", &v1[i]);
    sort(v1, v1 + s1);
    int i0 = 0, i1 = 0;
    int ans = 1000000;
    while(i0 < s0 && i1 < s1) {
      ans = min(ans, abs(v0[i0] - v1[i1]));
      if(v0[i0] < v1[i1]) {
	i0++;
      } else if(v0[i0] > v1[i1]) {
	i1++;
      } else {
	break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
