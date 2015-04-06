#include <cstdio>
#include <algorithm>
#define MAXN 1000005

using namespace std;

int n, q;
long long v[MAXN];

long long solve(long long x) {
  long long ans = n;
  for(int i = 1; i <= n; i++) {
    if(v[i] > x)
      break;
    int pointer = i;
    long long sub = 1;
    while(true) {
      long long sum = v[pointer] + x;
      int next_pointer = lower_bound(v+1, v+n+1, sum) - v;
      if(next_pointer == n+1) {
	if(v[next_pointer - 1] - v[pointer] + v[i] > x)
	  sub++;
	break;
      } else {
	if(v[next_pointer] > sum)
	  next_pointer--;
	pointer = next_pointer;
	sub++;
      }
    }
    ans = min(ans, sub);
  }
  return ans;
}

int main() {
  scanf("%d %d", &n, &q);
  v[0] = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", &v[i]);
    v[i] += v[i-1];
  }
  long long x;
  for(int i = 0; i < q; i++) {
    scanf("%I64d", &x);
    printf("%d\n", (int) solve(x));
  }
  return 0;
}
