#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 100005

using namespace std;

int cn[MAXN];
typedef pair<int, int> II;
map<II, long long> m;

long long findMax(int start, int end) {
  if(m.count(make_pair(start, end)))
    return m[make_pair(start, end)];
  if(start > end)
    return 0;
  if(start == end) {
    return m[make_pair(start, end)] = start * 1LL * cn[start];
  }
  return m[make_pair(start, end)] = max(start * 1LL * cn[start] + findMax(start+2, end), (start + 1) * 1LL * cn[start+1] + findMax(start+3, end));
}

int main() {
  int n;
  scanf("%d", &n);
  memset(cn, 0, sizeof cn);
  int maxVal = 0;
  for(int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cn[x]++;
    maxVal = max(maxVal, x);
  }
  long long ans = 0;
  for(int i = 1; i <= maxVal; i++) {
    if(cn[i] > 0) {
      int start = i;
      for(; i <= maxVal; i++) {
	if(cn[i] == 0) {
	  break;
	}
      }
      int end = i - 1;
      ans += findMax(start, end);
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
