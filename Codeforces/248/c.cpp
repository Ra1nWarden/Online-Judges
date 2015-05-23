#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#define MAXN 100005

using namespace std;

map<int, long long> diffm;
map<int, vector<int> > memo;
int v[MAXN];
int n, m;

void add_diffm(int diffk, int diffv) {
  if(diffm.count(diffk))
    diffm[diffk] = diffm[diffk] + diffv;
  else
    diffm[diffk] = diffv;
}

int main() {
  scanf("%d %d", &n, &m);
  long long orig = 0;
  for(int i = 0; i < m; i++) {
    scanf("%d", &v[i]);
  }
  for(int i = 0; i < m; i++) {
    if(i > 0) {
      if(v[i-1] != v[i]) {
	memo[v[i]].push_back(v[i-1]);
	add_diffm(v[i], abs(v[i] - v[i-1]));
	orig += abs(v[i]- v[i-1]);
      }
    }
    if(i < m - 1) {
      if(v[i+1] != v[i]) {
	memo[v[i]].push_back(v[i+1]);
	add_diffm(v[i], abs(v[i+1] - v[i]));
      }
    }
  }
  long long ans = orig;
  for(map<int, vector<int> >::iterator itr = memo.begin(); itr != memo.end(); itr++) {
    long long next_ans = orig - diffm[itr->first];
    sort(itr->second.begin(), itr->second.end());
    for(int i = 0; i < itr->second.size() / 2; i++) {
      next_ans += (itr->second[itr->second.size() - 1 - i] - itr->second[i]);
    }
    ans = min(ans, next_ans);
  }
  printf("%I64d\n", ans);
  return 0;
}
