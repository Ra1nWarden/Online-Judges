#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n, a;

int main() {
  scanf("%d%d", &n, &a);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v, v+n);
  if(n == 1) {
    printf("0\n");
    return 0;
  }
  if(a <= v[0]) {
    printf("%d\n", v[n-2] - a);
    return 0;
  }
  if(a >= v[n-1]) {
    printf("%d\n", a - v[1]);
    return 0;
  }
  // left leave out
  int left;
  if(a <= v[1])
    left = v[n-1] - a;
  else if(a >= v[n-1])
    left = a - v[1];
  else
    left = min(a - v[1] + v[n-1] - v[1], v[n-1] - a + v[n-1] - v[1]);
  // right leave out
  int right;
  if(a <= v[0])
    right = v[n-2] - a;
  else if(a >= v[n-2])
    right = a - v[0];
  else
    right = min(a - v[0] + v[n-2] - v[0], v[n-2] - a + v[n-2] - v[0]);
  printf("%d\n", min(left, right));
  return 0;
}
