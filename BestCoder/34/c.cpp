#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 50005
#define INF 10000000000LL

using namespace std;

int n, w, h;
long long v[MAXN];

int main() {
  while(scanf("%d %d %d", &n, &w, &h) != EOF) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      sum += v[i];
    }
    long long prod = h * 1LL * w;
    if(sum < prod) {
      printf("-1\n");
      continue;
    }
    long long maxh = sum / w;
    long long start = h;
    long long end = maxh;

    long long res = INF;
    for(int i = -(w-1); i < n; i++) {
      int end = i + w - 1;
      long long movein = 0;
      if(i < 0)
	movein += (-i * 1LL * h);
      if(end >= n) {
	movein += (end - n) * h;
      }
      for(int j = i; j <= min(n-1, end); j++) {
	movein += abs(h - v[j]);
      }
      //movein += sub[min(n - 1, end)] - (i > 0 ? sub[i-1] : 0);
      res = min(res, movein);
      printf("start res = %lld for i=%d\n", res, i);
    }
    
    long long minval = res;
    printf("start minval=%lld\n", minval);
    while(start < end) {
      printf("bs: %lld %lld\n", start, end);
      long long mid = (start + end) / 2 + 1;
      long long res = INF;
      for(int i = -(w-1); i < n; i++) {
	int end = i + w - 1;
	long long movein = 0;
	if(i < 0)
	  movein += (-i * 1LL * mid);
	if(end >= n) {
	  movein += (end - n) * mid;
	}
	for(int j = i; j <= min(n-1, end); j++) {
	  movein += abs(mid - v[j]);
	}
	//movein += sub[min(n - 1, end)] - (i > 0 ? sub[i-1] : 0);
	res = min(res, movein);
      }
      printf("res is %lld for mid = %lld\n", res, mid);
      if(res <= minval) {
	minval = res;
	start = mid;
      } else {
	end = mid - 1;
      }
    }
    printf("%lld %lld\n", start, minval);
  }
  return 0;
}
