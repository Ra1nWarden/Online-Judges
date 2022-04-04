#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  int mv = 0;
  int amv = 1000000001;
  bool pos = false, neg = false;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(num < 0) {
      neg = true;
    } else {
      pos = true;
    }
    int anum = num;
    if(anum < 0)
      anum = -anum;
    ans += anum;
    if(anum < amv) {
      amv = anum;
      mv = num;
    }
  }
  if(n == 1) {
    printf("%d\n", mv);
    return 0;
  }
  if(pos ^ neg) {
    if(mv < 0)
      ans += mv * 2;
    else
      ans -= mv * 2;
  }
  printf("%lld\n", ans);
  return 0;
}
