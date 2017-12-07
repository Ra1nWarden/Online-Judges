#include <cstdio>
#include <map>
#include <set>
#include <queue>

using namespace std;

map<int, bool> pm;
typedef pair<int, int> Node;

bool check(int num) {
  if(pm.count(num))
    return pm[num];
  for(int i = 2; i * i <= num; i++) {
    if(num % i == 0) {
      return pm[num] = true;
    }
  }
  return pm[num] = false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int start, end;
    scanf("%d%d",&start, &end);
    set<int> vis;
    queue<Node> q;
    q.push(make_pair(start, 0));
    vis.insert(start);
    while(!q.empty()) {
      Node u = q.front();
      q.pop();
      if(u.first == end) {
	printf("%d\n", u.second);
	break;
      }
      int num = u.first;
      for(int base = 1; base < 10000; base *= 10) {
	for(int mult = 0; mult < 10; mult++) {
	  int new_num = (num - ((num / base) % 10) * base) + mult * base;
	  if(new_num < 1000 || vis.count(new_num) || check(new_num)) {
	    continue;
	  }
	  q.push(make_pair(new_num, u.second + 1));
	  vis.insert(new_num);
	}
      }
    }
  }
  return 0;
}
