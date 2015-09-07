#include <cstdio>
#include <map>
#include <string>
#include <vector>
#define MAXN 1005

using namespace std;

int cnt;
map<string, int> id;

struct Component {
  int price, quality;
};
int n, b;
vector<Component> comp[MAXN];

bool ok(int q) {
  int sum = 0;
  for(int i = 0; i < cnt; i++) {
    int cheapest = b + 1, m = comp[i].size();
    for(int j = 0; j < m; j++) {
      if(comp[i][j].quality >= q)
	cheapest = min(cheapest, comp[i][j].price);
    }
    sum += cheapest;
    if(sum > b)
      return false;
  }
  return true;
}

int getId(string s) {
  if(id.count(s) == 0) {
    return id[s] = cnt++;
  }
  return id[s];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &b);
    cnt = 0;
    for(int i = 0; i < n; i++) {
      comp[i].clear();
    }
    id.clear();
    
    int maxq = 0;
    for(int i = 0; i < n; i++) {
      char type[30], name[30];
      int p, q;
      scanf("%s %s%d%d", type, name, &p, &q);
      maxq = max(maxq, q);
      comp[getId(type)].push_back((Component){p, q});
    }

    int L = 0, R = maxq;
    while(L < R) {
      int M = L + (R - L + 1) / 2;
      if(ok(M))
	L = M;
      else
	R = M - 1;
    }
    printf("%d\n", L);
  }
  return 0;
}

