#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  vector<long long> val;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
	long long av = v[i] * 1LL * v[j] + v[k];
	val.push_back(av);
      }
    }
  }
  sort(val.begin(), val.end());
  long long ans = 0LL;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
	if(v[k] == 0)
	  continue;
	long long av = (v[i] + v[j]) * 1LL * v[k];
	ans += upper_bound(val.begin(), val.end(), av) - lower_bound(val.begin(), val.end(), av);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
