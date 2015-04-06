#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 100005

using namespace std;

vector<int> v[MAXN];
int n, t;

int f(int root) {
  if(v[root].empty())
    return 1;
  vector<int> count;
  for(int i = 0; i < v[root].size(); i++)
    count.push_back(f(v[root][i]));
  sort(count.begin(), count.end());
  int add = (int) ceil(count.size() * 1.0 * t / 100);
  int ans = 0;
  for(int i = 0; i < add; i++) {
    ans += count[i];
  }
  return ans;
}

int main() {
  while(scanf("%d %d", &n, &t) != EOF && (n || t)) {
    for(int i = 0; i <= n; i++)
      v[i].clear();
    for(int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      v[x].push_back(i);
    }
    printf("%d\n", f(0));
  }
  return 0;
}
