#include <cstdio>
#include <utility>
#include <vector>
#define MAXN 10005

using namespace std;

int v[MAXN];
int n;
typedef pair<int, int> Ans;
vector<Ans> ans;
int iv[MAXN];

void swaps() {
  Ans range = ans.back();
  int lp = range.first;
  int rp = (range.first + range.second) / 2 + 1;
  int mid = rp - range.first;
  for(int i = 0; i < mid; i++) {
    swap(iv[v[lp+i]], iv[v[rp+i]]);
    swap(v[lp+i], v[rp+i]);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      iv[v[i]] = i;
    }
    ans.clear();
    for(int i = 1; i <= n; i++) {
      int pos = iv[i];
      if(pos == i)
	continue;
      if(pos <= (i + n) / 2) {
	ans.push_back(make_pair(i, (pos - i) * 2 - 1 + i));
      } else {
	if((n - i + 1) % 2 == 1)
	  ans.push_back(make_pair(i+1, n));
	else
	  ans.push_back(make_pair(i, n));
	i--;
      }
      swaps();
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
