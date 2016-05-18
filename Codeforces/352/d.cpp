#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 500000;
int n, k;
int v[maxn+5];
long long prefix[maxn+5];
long long postfix[maxn+5];

bool oks(int num) {
  long long add = 0;
  for(int i = 0; i < n; i++) {
    add += num - v[i];
    if(add > k)
      return false;
  }
  return add < n;
}

bool okl(int num) {
  long long add = 0;
  for(int i = n - 1; i >= 0; i--) {
    add += v[i] - num;
    if(add > k)
      return false;
  }
  return add < n;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v, v+n);
  if(v[0] == v[n-1]) {
    printf("0\n");
    return 0;
  }
  if(k == 0) {
    printf("%d\n", v[n-1] - v[0]);
    return 0;
  }
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    sum += v[i];
    prefix[i] = sum;
  }
  sum = 0;
  for(int i = n-1; i >= 0; i--) {
    sum += v[i];
    postfix[i] = sum;
  }
  int sl = v[0], sr = v[n-1];
  while(sl != sr) {
    int sm = ((sl + sr) >> 1) + 1;
    if(oks(sm)) {
      sl = sm;
    } else {
      sr = sm - 1;
    }
  }
  int ll = v[0], lr = v[n-1];
  while(ll != lr) {
    int lm = ((ll + lr) >> 1);
    if(okl(lm)) {
      lr = lm;
    } else {
      ll = lm + 1;
    }
  }
  printf("%d\n", ll - sl);
  
  // bool ok = false;
  // int small, large;
  // for(int i = 1; i < n; i++) {
  //   long long total = v[i] * 1LL * (i + 1);
  //   long long time = total - prefix[i];
  //   if(time >= (long long) k) {
  //     small = v[i-1] + (((long long) k - v[i-1] * 1LL * i + prefix[i-1]) / i);
  //     break;
  //   }
  // }
  // for(int i = n - 2; i > 0; i--) {
  //   long long total = v[i] * 1LL * (n - i);
  //   long long time = postfix[i] - total;
  //   if(time >= (long long) k) {
  //     large = v[i+1] - ((long long) k - postfix[i+1] + v[i+1] * 1LL * (n - i - 1)) / (n - i - 1);
  //     break;
  //   }
  // }
  // printf("%d\n", large - small);
  return 0;
}
