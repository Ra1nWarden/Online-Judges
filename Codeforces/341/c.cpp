#include <cstdio>

using namespace std;

int n, p;
const int maxn = 100000;
double ok[maxn+1];

int main() {
  scanf("%d%d", &n, &p);
  for(int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    int total = r - l + 1;
    int lower = l / p;
    if(l % p == 0)
      lower--;
    int upper = r / p;
    ok[i] = (upper - lower) * 1.0 / total;
  }
  double ans = 0;
  for(int i = 0; i < n; i++) {
    int l = (i - 1 + n) % n;
    int r = (i + 1) % n;
    ans += ok[l] * (1 - ok[i]) * (1 - ok[r]);
    ans += (1 - ok[l]) * ok[i] * (1 - ok[r]) * 2;
    ans += (1 - ok[l]) * (1 - ok[i]) * ok[r];
    ans += ok[l] * ok[i] * (1 - ok[r]) * 2;
    ans += (1 - ok[l]) * ok[i] * ok[r] * 2;
    ans += ok[l] * (1 - ok[i]) * ok[r] * 2;
    ans += ok[l] * ok[i] * ok[r] * 2;
  }
  printf("%.8lf\n", ans * 1000);
  return 0;
}
