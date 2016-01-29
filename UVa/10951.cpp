#include <cstdio>
#include <vector>

using namespace std;

int mod;
vector<int> coeffs[2];

int power_mod(int b, int p) {
  int ans = 1;
  while(p) {
    if(p & 1) {
      ans = (ans * b) % mod;
    }
    b = (b * b) % mod;
    p >>= 1;
  }
  return ans;
}

vector<int> poly_gcd(vector<int> a, vector<int> b) {
  if(b.empty())
    return a;
  int t = a.size() - b.size();
  vector<int> c;
  for(int i = 0; i <= t; i++) {
    int tmp = a[i] * power_mod(b[i], mod - 2) % mod;
    for(int j = 0; j < b.size(); j++)
      a[i+j] = (a[i+j] - tmp * b[j] % mod + mod) % mod;
  }
  int p = -1;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != 0) {
      p = i;
      break;
    }
  }
  if(p >= 0) {
    for(int i = p; i < a.size(); i++)
      c.push_back(a[i]);
  }
  return poly_gcd(b, c);
}

int main() {
  int kase = 1;
  while(scanf("%d", &mod) != EOF && mod) {
    coeffs[0].clear();
    coeffs[1].clear();
    for(int i = 0; i < 2; i++) {
      int n;
      scanf("%d", &n);
      for(int j = 0; j < n + 1; j++) {
	int c;
	scanf("%d", &c);
	coeffs[i].push_back(c);
      }
    }
    vector<int> ans = poly_gcd(coeffs[0], coeffs[1]);
    int inv = power_mod(ans[0], mod - 2);
    printf("Case %d: %d", kase++, ans.size() - 1);
    for(int i = 0; i < ans.size(); i++) {
      printf(" %d", ans[i] * inv % mod);
    }
    printf("\n");
  }
  return 0;
}
