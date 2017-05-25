#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n, c;

bool check(int m) {
  int prev = v[0];
  int cnt = 1;
  for(int i = 1; i < n; i++) {
    if(v[i] - prev >= m) {
      prev = v[i];
      cnt++;
      if(cnt >= c) {
	return true;
      }
    }
  }
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    sort(v, v+n);
    int left = 1, right = v[n-1] - v[0];
    while(left != right) {
      int mid = (left + right) / 2 + 1;
      if(check(mid)) {
	left = mid;
      } else {
	right = mid - 1;
      }
    }
    printf("%d\n", left);
  }
}
