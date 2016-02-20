#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n, m;
  map<int, vector<int> > memo;
  while(scanf("%d%d", &n, &m) != EOF) {
    for(int i = 1; i <= n; i++) {
      int num;
      scanf("%d", &num);
      memo[num].push_back(i);
    }
    for(int i = 0; i < m; i++) {
      int k, v;
      scanf("%d%d", &k, &v);
      if(memo.count(v) == 0 || k > memo[v].size())
	printf("0\n");
      else
	printf("%d\n", memo[v][k-1]);
    }
  }
  return 0;
}
