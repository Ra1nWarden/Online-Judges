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
  return add > -n && add <= 0;
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
    int lm = ((ll + lr) >> 1) + 1;
    if(okl(lm)) {
      ll = lm;
    } else {
      lr = lm - 1;
    }
  }
  printf("ll=%d sl=%d\n", ll, sl);
  printf("%d\n", ll - sl);
  return 0;
}
