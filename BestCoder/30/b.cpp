#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long num;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int tc = 1;
  while(scanf("%lld", &num) != EOF) {
    if(num == 1) {
      printf("Case #%d:\n", tc++);
      printf("0\n\n");
      continue;
    }
    long long cap = sqrt(num);
    vector<long long> res;
    for(long long gcdn = 1; gcdn <= cap; gcdn++) {
      if(num % gcdn == 0) {
	long long m = gcdn ^ num;
	if(m <= num && m % gcdn == 0 && gcd(num / gcdn, m / gcdn) == 1) {
	  res.push_back(m);
	}
	if(gcdn == 1 || gcdn * gcdn == num)
	  continue;
	m = (num / gcdn) ^ num;
	if(m <= num && m % (num / gcdn) == 0 && gcd(gcdn, m / (num / gcdn)) == 1) {
	  res.push_back(m);
	}
      }
    }
    sort(res.begin(), res.end());
    printf("Case #%d:\n", tc++);
    printf("%lu\n", res.size());
    for(int i = 0; i < res.size(); i++) {
      if(i != 0)
	printf(" ");
      printf("%lld", res[i]);
    }
    printf("\n");
  }
  return 0;
}
