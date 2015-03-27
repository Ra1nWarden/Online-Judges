#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  for(int et = 1; et <= tc; et++) {
    set<long long> odd;
    set<long long> even;
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    long long prev = 0;
    bool ok = false;
    for(long long i = 0; i < n; i++) {
      long long num;
      scanf("%I64d", &num);
      prev += (i % 2 == 0 ? num : -num);
      if(!ok)
	ok = prev == k || odd.count(prev - k) > 0 || even.count(prev + k) > 0;
      if(i % 2 == 0)
	even.insert(prev);
      else
	odd.insert(prev);
    }
    printf("Case #%d: %s.\n", et, ok ? "Yes" : "No");
  }
  
  return 0;
}
