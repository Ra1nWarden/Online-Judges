#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 50000;
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d", &n);
    double ans = 0;
    double logs = 0;
    for(int i = 0; i < n; i++) {
      double num;
      scanf("%lf", &num);
      if(num > 0) {
	ans += exp(logs + log(num) - (n - 1) * log(2.0));
      } else if(num < 0) {
	ans -= exp(logs + log(-num) - (n - 1) * log(2.0));
      }
      logs += log((double) (n - i - 1)) - log((double) i + 1);
    }
    printf("Case #%d: %.3lf\n", kase, ans);
  }
  return 0;
}
