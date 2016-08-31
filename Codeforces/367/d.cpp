#include <cstdio>
#include <set>

using namespace std;

typedef multiset<int>::iterator Iter;

int main() {
  int q;
  scanf("%d\n", &q);
  multiset<int> s;
  s.insert(0);
  while(q--) {
    char cmd;
    int n;
    scanf("%c %d\n", &cmd, &n);
    if(cmd == '+') {
      s.insert(n);
    } else if(cmd == '-') {
      s.erase(s.find(n));
    } else {
      // '?'
      int shift = 30;
      int submask = 0;
      while(shift >= 0) {
	if((1 << shift) & n) {
	  // want 0
	  Iter it = s.lower_bound(submask);
	  if(it == s.end() || (submask >> shift) != (*it >> shift))
	    submask |= (1 << shift);
	} else {
	  // want 1
	  submask |= (1 << shift);
	  Iter it = s.lower_bound(submask);
	  if(it == s.end() || (submask >> shift) != (*it >> shift))
	    submask ^= (1 << shift);
	}
	shift--;
      }
      printf("%d\n", n ^ submask);
    }
  }
  return 0;
}
