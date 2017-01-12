#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n, n1, n2;

int main() {
  scanf("%d%d%d", &n, &n1, &n2);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v, v+n, greater<int>());
  long long s1 = 0, s2 = 0, s = 0;
  for(int i = 0; i < n1; i++)
    s1 += v[i];
  for(int i = 0; i < n2; i++)
    s2 += v[i];
  for(int i = 0; i < n1 + n2; i++)
    s += v[i];
  printf("%.8lf\n", max(s1 * 1.0f * n2 + (s - s1) * n1, s2 * 1.0f * n1 + (s - s2) * n2) / (n1 * 1ll * n2));
  return 0;
}
