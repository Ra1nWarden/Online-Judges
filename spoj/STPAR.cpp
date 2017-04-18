#include <cstdio>
#include <stack>

using namespace std;

int main() {
  int n;
  while(scanf("%d", &n)) {
    if(n == 0)
      break;
    int top = 0;
    stack<int> s;
    int x;
    bool ok = true;
    while(n--) {
      scanf("%d", &x);
      if(!ok)
	continue;
      if(x == top + 1) {
	top++;
      } else if(s.empty()) {
	s.push(x);
      } else if(s.top() == top + 1) {
	s.pop();
	top++;
      } else if(s.top() > x) {
	s.push(x);
      } else {
	ok = false;
      }
      while(!s.empty() && s.top() == top + 1) {
	s.pop();
	top++;
      }
    }
    printf("%s\n", ok ? "yes" : "no");
  }
  return 0;
}
