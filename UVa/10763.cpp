#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

map<int, vector<int> > in_map;
map<int, vector<int> > out_map;
set<int> s;

int main() {
  int n;
  while(scanf("%d", &n) && n) {
    s.clear();
    in_map.clear();
    out_map.clear();
    for(int i = 0; i < n; i++) {
      int from, to;
      scanf("%d%d", &from, &to);
      s.insert(from);
      s.insert(to);
      in_map[to].push_back(from);
      out_map[from].push_back(to);
    }
    bool ok = true;
    for(set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
      int num = *itr;
      vector<int> in_v = in_map[num];
      vector<int> out_v = out_map[num];
      if(in_v.size() != out_v.size()) {
	ok = false;
	break;
      }
      sort(in_v.begin(), in_v.end());
      sort(out_v.begin(), out_v.end());
      for(int i = 0; i < in_v.size(); i++) {
	if(in_v[i] != out_v[i]) {
	  ok = false;
	  break;
	}
      }
      if(!ok)
	break;
    }
    if(ok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
