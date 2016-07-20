#include <cstdio>

using namespace std;

int main() {
  int n, h;
  scanf("%d%d", &n, &h);
  int ans = n;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(num > h)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
