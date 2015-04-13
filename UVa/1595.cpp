#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#define MAXN 1005

using namespace std;

map<int, vector<int> > m;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    m.clear();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      m[y].push_back(x);
    }
    bool ok = true;
    int mid_point = 40000;
    for(map<int, vector<int> >::iterator itr = m.begin(); itr != m.end(); itr++) {
      vector<int> v = itr->second;
      sort(v.begin(), v.end());
      int next_mid = v.front() + v.back();
      if(mid_point != 40000 && next_mid != mid_point) {
	ok = false;
	break;
      }
      for(int i = 1; i <= v.size() / 2; i++) {
	if(v[i] + v[v.size() - 1 - i] != next_mid) {
	  ok = false;
	  break;
	}
      }
      if(!ok)
	break;
      mid_point = next_mid;
    }


    if(ok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
