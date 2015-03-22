#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

int n, s;
int v[MAXN];
int sum[MAXN];

int main() {
  while(scanf("%d %d", &n, &s) != EOF) {
    sum[0] = 0;
    v[0] = -1;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      sum[i] = v[i] + sum[i-1];
    }
    int res = n+1;
    //int start = 0;
    // for(int j = 1; j <= n; j++) {
    //   if(sum[j] - sum[start] < s)
    // 	continue;
    //   while(sum[j] - sum[start+1] >= s)
    // 	start++;
    //   res = min(res, j - start);
    // }
    int end = 1;
    for(int i = 1; i <= n; i++) {
      while(sum[end] - sum[i-1] < s && end <= n)
	end++;
      if(sum[end] - sum[i-1] >= s)
	res = min(res, end - i + 1);
    }
    printf("%d\n", res == n+1 ? 0 : res);
  }
  return 0;
}
