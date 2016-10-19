#include <cstdio>

using namespace std;

int main() {
  int t, s, x;
  scanf("%d%d%d", &t, &s, &x);
  if(x == t) {
    printf("YES\n");
  } else if(x < t + s) {
    printf("NO\n");
  } else {
    bool ok = ((x - t) % s) <= 1;
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}
