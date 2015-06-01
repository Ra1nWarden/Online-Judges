#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define MAXN 100005

using namespace std;

bool check[MAXN];
int primes[MAXN];
int pos[MAXN];
int pi;
int n;
int v[MAXN];

typedef pair<int, int> II;
vector<II> ans;

void swap_pos(int i, int j) {
  int x = v[i], y = v[j];
  v[i] = y;
  v[j] = x;
  pos[y] = i;
  pos[x] = j;
  ans.push_back(make_pair(i, j));
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    pos[v[i]] = i;
  }
  memset(check, false, sizeof check);
  pi = 0;
  for(int i = 2; i <= n; i++) {
    if(!check[i])
      primes[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(i * primes[j] > n)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
  for(int i = 1; i <= n; i++) {
    while(v[i] != i) {
      int target = pos[i];
      int swap_i = lower_bound(primes, primes+pi, target - i + 1) - primes;
      if(swap_i == pi)
	swap_i--;
      int swap_length = primes[swap_i];
      if(swap_length > target - i + 1) {
	swap_length = primes[swap_i - 1];
      }
      swap_pos(target - swap_length + 1, target);
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
