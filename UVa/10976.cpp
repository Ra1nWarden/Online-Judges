#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int k;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

typedef pair<int, int> II;

int main() {
  while(scanf("%d", &k) != EOF) {
    vector<II> v;
    for(int y = k + 1; y <= 2 * k; y++) {
      int denom = lcm(y, k);
      if(denom % (denom / k - denom / y) == 0) {
	int x = denom / (denom / k - denom / y);
	v.push_back(make_pair(y, x));
      }
    }
    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++)
      printf("1/%d = 1/%d + 1/%d\n", k, v[i].second, v[i].first);
  }
  return 0;
}
