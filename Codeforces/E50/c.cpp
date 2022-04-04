#include <cstdio>
#include <vector>

using namespace std;

long long choose(long long a, long long b) {
  if(b == 0 || a == b)
    return 1;
  if(b > a / 2)
    return choose(a, a-b);
  return choose(a - 1, b - 1) + choose(a - 1, b);
}

long long calc(long long cap, int cnt) {
  //printf("calc(%lld %d)\n", cap, cnt);
  if(cap == 0)
    return 0;
  if(cnt == 0)
    return 1;
  if(cap == 1)
    return 1;
  long long cur = cap;
  vector<int> digs;
  while(cur) {
    digs.push_back(cur % 10);
    cur /= 10;
  }
  long long ans = 0;
  // check 100..
  if(digs.back() == 1) {
    bool zero = true;
    for(int i = 0; i < digs.size() - 1; i++) {
      if(digs[i] != 0)
	zero = false;
    }
    if(zero) {
      ans += 1;
      if(cnt >= 1 && digs.size() > 1) {
	ans += choose(digs.size() - 1, 1) * 9;
      }
      if(cnt >= 2 && digs.size() > 2) {
	ans += choose(digs.size() - 1, 2) * 9 * 9;
      }
      if(cnt >= 3 && digs.size() > 3) {
	ans += choose(digs.size() - 1, 3) * 9 * 9 * 9;
      }
      //printf("calc(%lld, %d)=%lld\n", cap, cnt, ans);
      return ans;
    }
  }
  // 100..
  long long one = 1LL;
  for(int i = 0; i < digs.size() - 1; i++)
    one *= 10;
  ans += calc(one, cnt);

  if(digs.back() > 1) {
    ans += calc(one, cnt-1) * (digs.back() - 1);
  }

  long long remain = 0;
  for(int i = digs.size() - 2; i >= 0; i--) {
    remain *= 10;
    remain += digs[i];
  }

  ans += calc(remain, cnt-1);

  //printf("calc(%lld, %d)=%lld\n", cap, cnt, ans);
  return ans;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", calc(r+1, 3) - calc(l, 3));
  }
  return 0;
}
