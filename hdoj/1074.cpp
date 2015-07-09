#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#define MAXL 105
#define MAXN 20
#define INF 2000000000

using namespace std;

char subjects[MAXN][MAXL];
int deadline[MAXN];
int time[MAXN];
int n;
map<int, int> dpt;
map<int, int> dp;
map<int, vector<int> > dpv;

int f(int mask) {
  if(dp.count(mask))
    return dp[mask];
  if(mask == 0) {
    dpt[mask] = 0;
    vector<int> dummy;
    dpv[mask] = dummy;
    return dp[mask] = 0;
  }
  int val = INF;
  vector<int> valv;
  int valt;
  for(int i = 0; i < n; i++) {
    if(((1 << i) & mask) != 0) {
      int mmask = mask^(1 << i);
      int vval = f(mmask);
      int ttime = dpt[mmask] + time[i];
      vval += max(ttime - deadline[i], 0);
      if(vval <= val) {
	val = vval;
	valv = dpv[mmask];
	valv.push_back(i);
	valt = ttime;
      }
    }
  }
  dpt[mask] = valt;
  dpv[mask] = valv;
  return dp[mask] = val;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d\n", &n);
    dpt.clear();
    dp.clear();
    dpv.clear();
    for(int i = 0; i < n; i++) {
      scanf("%s %d %d\n", subjects[i], &deadline[i], &time[i]);
    }
    int full_mask = (1 << n) - 1;
    printf("%d\n", f(full_mask));
    for(int i = 0; i < dpv[full_mask].size(); i++) {
      printf("%s\n", subjects[dpv[full_mask][i]]);
    }
  }
  return 0;
}
