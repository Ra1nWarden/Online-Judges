#include <cstdio>
#include <cstring>

using namespace std;

int n, k;
const int maxn = 500;
int v[maxn+5];
long long vv[maxn+5];
int ans[maxn+5];
int r[maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  scanf("%d", &k);
  for(int i = 0; i < k; i++)
    scanf("%I64d", &vv[i]);
  memset(ans, -1, sizeof ans);
  bool ok = true;
  long long sum = 0;
  int vvi = 0;
  for(int i = 0; i < n; i++) {
    sum += v[i];
    if(sum == vv[vvi]) {
      sum = 0;
      r[vvi] = i;
      vvi++;
    } else if(sum > vv[vvi]) {
      ok = false;
      break;
    }
  }
  ok = ok && (vvi == k);
  if(!ok) {
    printf("NO\n");
    return 0;
  }
  vvi = 0;
  int prev = -1;
  int maxval = -1;
  for(int i = 0; i < n; i++) {
    if(i > r[vvi]) {
      if(r[vvi] - prev == 1) {
	ans[vvi] = r[vvi];
      }
      if(ans[vvi] == -1) {
	ok = false;
	break;
      }
      //printf("ans[%d]=%d\n", vvi, ans[vvi]);
      prev = r[vvi];
      maxval = -1;
      vvi++;
    }
    if(i - 1 > prev && v[i] > v[i-1] && v[i] > maxval) {
      maxval = v[i];
      ans[vvi] = i;
    }
    if(i + 1 <= r[vvi] && v[i] > v[i+1] && v[i] > maxval) {
      maxval = v[i];
      ans[vvi] = i;
    }
  }
  if(ans[vvi] == -1) {
    if(r[vvi] - prev == 1) {
      ans[vvi] = r[vvi];
    } else {
      ok = false;
    }
  }
  ok = ok && (vvi == k - 1);
  if(!ok) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  prev = -1;
  for(int i = 0; i < k; i++) {
    int idx = ans[i];
    //printf("prev = %d r[i] = %d ans[i] = %d\n", prev, r[i], ans[i]);
    int pidx = ans[i] - prev + i;
    // if(pidx < 0)
    //   printf("ERROR: %d - %d + %d\n", ans[i], prev, i);
    if(idx - 1 > prev && v[idx] > v[idx-1]) {
      for(int j = 0; j < ans[i] - prev - 1; j++) {
	printf("%d L\n", pidx--);
      }
      for(int j = 0; j < r[i] - ans[i]; j++) {
	printf("%d R\n", i + 1);
      }
    } else {
      for(int j = 0; j < r[i] - ans[i]; j++) {
	printf("%d R\n", pidx);
      }
      for(int j = 0; j < ans[i] - prev - 1; j++) {
	printf("%d L\n", pidx--);
      }
    }
    prev = r[i];
  }
  return 0;
}
