#include <cstdio>
#include <stack>

using namespace std;

long long m;
typedef pair<long long, long long> LL;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    stack<LL> s;
    scanf("%lld", &m);
    long long prod = m;
    long long prod_lower = 1;
    for(long long k = 1; k > 0; k++) {
      prod *= k;
      long long right = m;
      long long left = 2 * k;
      long long prod_lower = 1;
      bool done = false;
      for(long long i = 0; i < k; i++) {
	if(prod / prod_lower < (2 * k - i)) {
	  done = true;
	  break;
	}
	prod_lower *= (2 * k - i);
      }
      if(done)
	break;
      while(left <= right) {
	long long mid = (left + right) >> 1;
	long long run = 1;
	bool too_large = false;
	for(long long i = 0; i < k; i++) {
	  if(prod / run < (mid - i)) {
	    too_large = true;
	    break;
	  }
	  run *= (mid - i);
	}
	if(too_large || run > prod) {
	  right = mid - 1;
	} else if(run == prod) {
	  s.push(make_pair(mid, mid-k));
	  if(mid-k != k)
	    s.push(make_pair(mid, k));
	  break;
	} else {
	  left = mid + 1;
	}
      }
    }
    printf("%d\n", s.size());
    while(!s.empty()) {
      LL next = s.top();
      s.pop();
      printf("(%lld,%lld)", next.first, next.second);
      if(!s.empty()) {
	printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
