#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int n, x, y;
vector<string> ans;

int main() {
  scanf("%d%d%d", &n, &x, &y);
  int cntx = 0, cnty = 0;
  while(cntx < x || cnty < y) {
    long long xx = (cntx + 1) * 1LL * y;
    long long yy = (cnty + 1) * 1LL * x;
    if(xx < yy) {
      ans.push_back("Vanya");
      cntx++;
    } else if(xx > yy) {
      ans.push_back("Vova");
      cnty++;
    } else {
      ans.push_back("Both");
      ans.push_back("Both");
      cntx++;
      cnty++;
    }
  }
  int cnt;
  while(n--) {
    scanf("%d", &cnt);
    cnt--;
    printf("%s\n", ans[cnt % (x + y)].c_str());
  }
  return 0;
}
