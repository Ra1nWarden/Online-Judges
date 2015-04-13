#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int v1, v2, t, d;
  scanf("%d %d\n%d %d\n", &v1, &v2, &t, &d);
  int dis = 0;
  for(int i = 1; i <= t; i++) {
    if(i == 1) {
      dis += v1;
    } else if(i == t) {
      dis += v2;
    } else {
      int next = min(v1 + d, (t - i) * d + v2);
      dis += next;
      v1 = next;
    }
  }
  printf("%d\n", dis);
  return 0;
}
