#include <cstdio>
#include <unordered_map>

using namespace std;

const int maxn = 2500;
int v[4][maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int j = 0; j < n; j++) {
    for(int i = 0; i < 4; i++) {
      scanf("%d", &v[i][j]);
    }
  }
  unordered_map<int, int> cnt;
  cnt.reserve(2 * n * n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int sum = v[0][i] + v[1][j];
      if(cnt.count(sum))
	cnt[sum] = cnt[sum] + 1;
      else
	cnt[sum] = 1;
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int sum = v[2][i] + v[3][j];
      if(cnt.count(-sum)) {
	ans += cnt[-sum];
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
