#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 50;

bool painted[maxn+1][2];
int n;

int main() {
  scanf("%d", &n);
  memset(painted, false, sizeof painted);
  vector<int> ans;
  for(int i = 1; i <= n * n; i++) {
    int h, v;
    scanf("%d%d", &h, &v);
    if(!painted[h][0] && !painted[v][1]) {
      ans.push_back(i);
      painted[h][0] = painted[v][1] = true;
    }
  }
  for(int i = 0; i < ans.size(); i++) {
    if(i > 0)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
