#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 50005

using namespace std;

int n, w, h;
long long add[MAXN];
long long sub[MAXN];

int main() {
  while(scanf("%d %d %d", &n, &w, &h) != EOF) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      int diff = num - h;
      add[i] = diff > 0 ? (long long) diff : 0LL;
      sub[i] = diff < 0 ? (long long)-diff : 0LL;
      if(i > 0) {
	add[i] += add[i-1];
	sub[i] += sub[i-1];
      }
      sum += num;
    }
    long long prod = h * 1LL * w;
    if(sum < prod) {
      printf("-1\n");
      continue;
    }
    long long res = 10000000000LL;
    for(int i = -(w-1); i < n; i++) {
      int end = i + w - 1;
      long long movein = 0;
      long long moveout = 0;
      if(i < 0)
	movein += (-i * 1LL * h);
      if(end >= n) {
	movein += (end - n + 1) * h;
      }
      moveout += add[min(n - 1, end)] - (i > 0 ? add[i-1] : 0);
      movein += sub[min(n - 1, end)] - (i > 0 ? sub[i-1] : 0);
      res = min(res, max(movein, moveout));

      // if(i < 0) {
      // 	long long movein = (-i * 1LL * h) + sub[w - i - 1];
      // 	long long moveout = add[w - i - 1];
      // 	res = min(res, max(movein, moveout));
      // } else if(i + w - 1 < n){
      // 	long long movein = sub[i+w-1] - (i > 0 ? sub[i-1] : 0);
      // 	long long moveout = add[i+w-1] - (i > 0 ? add[i-1] : 0);
      // 	res = min(res, max(movein, moveout));
      // } else {
      // 	long long movein = (n - i + 1) * h + sub[n-1] - (i > 0 ? sub[i-1] : 0);
      // 	long long moveout = add[n-1] - (i > 0 ? add[i-1] : 0);
      // 	res = min(res, max(movein, moveout));
      // }
      //printf("index=%d res=%I64d movein=%I64d moveout=%I64d\n", i, res, movein, moveout);
    }
    printf("%I64d\n", res);
  }
  return 0;
}
