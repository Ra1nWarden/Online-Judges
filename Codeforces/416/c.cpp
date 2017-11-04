#include <cstdio>
#include <map>
#include <set>

using namespace std;

const int maxn = 5000;
int v[maxn+5];
int dp[maxn+5];
int n;
map<int, int> start;
map<int, int> endm;

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    int num = v[i];
    if(start.count(num)) {
      endm[num] = i;
    } else {
      start[num] = i;
      endm[num] = i;
    }
  }

  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i] = dp[i-1];
    int num = v[i];
    if(endm[num] != i) {
      continue;
    }
    
    set<int> all;
    all.insert(num);
    int add = num;
    bool ok = true;
    int ss = start[num];
    for(int j = endm[num]; j >= ss; j--) {
      if(endm[v[j]] > i) {
	ok = false;
	break;
      } else {
	ss = min(ss, start[v[j]]);
      }

      if(!all.count(v[j])) {
	add ^= v[j];
	all.insert(v[j]);
      }
    }
    
    if(ok) {
      dp[i] = max(dp[i], dp[ss-1] + add);
    }
  }

  printf("%d\n", dp[n]);
  return 0;
}
