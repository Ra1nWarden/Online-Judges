#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 1005

using namespace std;

bool vis[MAXN];
vector<int> primes;

int main() {
  memset(vis, false, sizeof vis);
  for(int i = 2; i <= 1000; i++) {
    if(!vis[i]) {
      primes.push_back(i);
      for(int j = i+i; j <= 1000; j+=i)
	vis[j] = true;
    }
  }
  int n;
  scanf("%d", &n);
  vector<int> ans;
  for(int i = 0; i < primes.size(); i++) {
    int p = primes[i];
    int prod = p;
    while(prod <= n) {
      ans.push_back(prod);
      prod *= p;
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
