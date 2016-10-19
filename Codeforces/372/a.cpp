#include <cstdio>

using namespace std;

int main() {
  int n, c;
  scanf("%d%d", &n, &c);
  int prev = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    if(v - prev <= c) {
      ans++;
    } else {
      ans = 1;
    }
    prev = v;
  }
  printf("%d\n", ans);
  return 0;
}
