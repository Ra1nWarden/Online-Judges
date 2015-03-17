#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXL 25

using namespace std;

typedef pair<int, int> II;

int n, b;
char t[MAXL];
char prevt[MAXL];
char name[MAXL];
vector<int> resv;
vector<vector<II> > v;

bool _cmp(const II& one, const II& two) {
  return one.second < two.second;
}

int ok(int quality) {
  int price = 0;
  for(int i = 0; i < v.size(); i++) {
    price += (lower_bound(v[i].begin(), v[i].end(), make_pair(0, quality), _cmp))->first;
  }
  return price <= b;
}

int f(int start, int end) {
  if(start == end)
    return ok(resv[start]) ? resv[start] : -1;
  int mid = (start + end) / 2;
  if(ok(resv[mid])) {
    return max(resv[mid], f(mid+1, end));
  } else {
    return f(start, mid - 1);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    v.clear();
    resv.clear();
    memset(t, 0, sizeof t);
    memset(prevt, 0, sizeof prevt);
    memset(name, 0, sizeof name);
    scanf("%d %d\n", &n, &b);
    vector<II> subv;
    while(n--) {
      int price;
      int quality;
      scanf("%s %s %d %d\n", t, name, &price, &quality);
      resv.push_back(quality);
      if(strcmp(prevt, t) != 0) {
	if(!subv.empty()) {
	  sort(subv.begin(), subv.end(), _cmp);
	  v.push_back(subv);
	}
	subv.clear();
      }
      subv.push_back(make_pair(price, quality));
      memcpy(prevt, t, strlen(t) + 1);
    }
    if(!subv.empty()) {
      sort(subv.begin(), subv.end(), _cmp);
      v.push_back(subv);
    }
    sort(resv.begin(), resv.end());
    resv.resize(distance(resv.begin(), unique(resv.begin(), resv.end())));
    printf("%d\n", f(0, resv.size() - 1));
  }
  return 0;
}
