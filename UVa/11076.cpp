#include <cstdio>
#include <cstring>

using namespace std;

const int maxd = 10;
const int maxl = 13;
int cnt[maxd];
int total;
typedef unsigned long long ULL;
ULL fact[maxl];

void init() {
  fact[0] = 1;
  for(int i = 1; i < maxl; i++)
    fact[i] = fact[i-1] * i;
}

ULL calc(int dig) {
  ULL ans = fact[total-1];
  for(int i = 0; i < maxd; i++) {
    if(i == dig) {
      ans /= fact[cnt[i] - 1];
    } else {
      ans /= fact[cnt[i]];
    }
  }
  return ans * dig;
}

int main() {
  init();
  while(scanf("%d", &total) != EOF && total) {
    memset(cnt, 0, sizeof cnt);
    int digit;
    for(int i = 0; i < total; i++) {
      scanf("%d", &digit);
      cnt[digit]++;
    }
    ULL base = 0;
    for(int i = 0; i < maxd; i++) {
      if(cnt[i]) {
	base += calc(i);
      }
    }
    ULL ans = 0;
    ULL mult = 1;
    for(int i = 0; i < total; i++, mult *= 10) {
      ans += base * mult;
    }
    printf("%llu\n", ans);
  }
  return 0;
}
