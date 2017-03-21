#include <cstdio>

using namespace std;

int f(int n) {
  int ans = 0;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0)
      ans++;
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += f(i);
  }
  printf("%d\n", ans);
  return 0;
}
