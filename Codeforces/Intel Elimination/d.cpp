#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main() {
  int n;
  set<int> s;
  priority_queue<int> pq;
  scanf("%d", &n);
  int num;
  while(n--) {
    scanf("%d", &num);
    pq.push(num);
    s.insert(num);
  }
  while(!pq.empty()) {
    int u = pq.top();
    pq.pop();
    int uu = u;
    while(true) {
      uu >>= 1;
      if(uu == 0)
	break;
      if(s.count(uu) == 0) {
	s.erase(u);
	s.insert(uu);
	pq.push(uu);
	break;
      }
    }
    if(uu == 0) {
      pq.push(u);
      break;
    }
  }
  bool start = true;
  while(!pq.empty()) {
    if(!start)
      printf(" ");
    printf("%d", pq.top());
    pq.pop();
    start = false;
  }
  printf("\n");
  return 0;
}
