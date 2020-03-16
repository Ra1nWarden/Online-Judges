#include <cstdio>
#include <cstring>
#include <set>
#include <map>
 
using namespace std;
 
const int mod = 1e9 + 7;
const int bits = 19;
int primes[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int dp[2][1 << bits];
 
int power_two(int n) {
  int ans = 1;
  for(int i = 0; i < n - 1; i++) {
    ans = (ans * 1LL * 2) % mod;
  }
  return ans;
}
 
int main() {
  int n;
  scanf("%d", &n);
  map<int, int> cnts;
  while(n--) {
    int num;
    scanf("%d", &num);
    int mask = 0;
    for(int i = 0; i < bits; i++) {
      if(num % primes[i] == 0) {
	int pwr = 0;
	int cpy = num;
	while(cpy % primes[i] == 0) {
	  cpy /= primes[i];
	  pwr++;
	}
	if(pwr & 1)
	  mask |= (1 << i);
      }
    }
    if(cnts.count(mask)) {
      cnts[mask] = cnts[mask] + 1;
    } else {
      cnts[mask] = 1;
    }
  }
  set<int> vis;
  memset(dp, 0, sizeof dp);
  int idx = 1;
  for(auto each : cnts) {
    int mask = each.first;
    int cnt = each.second;
    //printf("mask=%d cnt=%d\n", mask, cnt);
    memcpy(dp[idx], dp[idx^1], sizeof dp[0]);
    //printf("before odd\n");
    int odd = power_two(cnt);
    //printf("before even\n");
    int even = odd - 1;
    //printf("mask=%d cnt=%d odd=%d even=%d\n", mask, cnt, odd, even);
    set<int> newVis(vis);
    if(mask < (1 << 11))
      newVis.insert(mask);
    dp[idx][mask] = (dp[idx][mask] + odd) % mod;
    newVis.insert(0);
    dp[idx][0] = (dp[idx][0] + even) % mod;
    for(auto eachVis : vis) {
      int newVal = eachVis ^ mask;
      if(mask < (1 << 11))
	newVis.insert(newVal);
      dp[idx][newVal] = (dp[idx][newVal] + (dp[idx^1][eachVis] * 1LL * odd) % mod) % mod;
      //printf("c. dp[%d]=%d\n", newVal, dp[idx][newVal]);
      dp[idx][eachVis] = (dp[idx][eachVis] + (dp[idx^1][eachVis] * 1LL * even) % mod) % mod;
      //printf("d. dp[%d]=%d\n", eachVis, dp[idx][eachVis]);
    }
    vis = newVis;
    idx ^= 1;
  }
  printf("%d\n", dp[idx^1][0]);
  return 0;
}
