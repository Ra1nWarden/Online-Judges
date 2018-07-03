#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 200000;
vector<int> primes;
int v[maxn+5], ans[maxn+5], power[21], vis[maxn+5];
int n;
vector<int> adjMat[maxn+5];

void init() {
  vector<bool> check(maxn+1, false);
  for(int i = 2; i <= maxn; i++) {
    if(!check[i])
      primes.push_back(i);
    for(int j = 0; j < primes.size(); j++) {
      if(i * primes[j] > maxn)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
  for(int i = 1; i <= n; i++)
    ans[i] = 1;
}

void calc(int p) {
  memset(vis, -1, sizeof vis);
  memset(power, 0, sizeof power);
  stack<int> s;
  s.push(1);
  while(!s.empty()) {
    int u = s.top();
    int exp = 0;
    int num = v[u];
    while(num % p == 0) {
      num /= p;
      exp++;
    }
    if(vis[u] == -1) {
      power[exp]++;
      vis[u] = 0;
      bool one = false;
      int jj = 0;
      for(int j = 0; j <= 20; j++) {
	if(power[j] == 0)
	  continue;
	else if(power[j] == 1) {
	  if(one) {
	    jj = j;
	    break;
	  }
	  else
	    one = true;
	} else {
	  jj = j;
	  break;
	}
      }
      if(jj == 0)
	continue;
      while(jj--) {
	ans[u] *= p;
      }
      for(int j = 0; j < adjMat[u].size(); j++) {
	int v = adjMat[u][j];
	if(vis[v] == -1)
	  s.push(v);
      }
    } else if(vis[u] == 0) {
      power[exp]--;
      vis[u] = 1;
      s.pop();
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
    scanf("%d", &v[i]);
  int x, y;
  for(int i = 0; i < n - 1; i++) {
    scanf("%d%d", &x, &y);
    adjMat[x].push_back(y);
    adjMat[y].push_back(x);
  }
  init();
  for(int i = 0; i < primes.size(); i++) {
    calc(primes[i]);
  }
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
