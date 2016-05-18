#include <cstdio>

using namespace std;

const int maxn = 90;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  v[n] = 90;
  int ans = 0;
  int time = 0;
  for(int i = 0; i <= n; i++) {
    if(v[i] - time > 15) {
      ans += 15;
      break;
    }
    ans += v[i] - time;
    time = v[i];
  }
  printf("%d\n", ans);
  return 0;
}
