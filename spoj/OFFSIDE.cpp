#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 11;
int bv[maxn+5];
int cv[maxn+5];
int bn, cn;

int main() {
  while(scanf("%d%d", &bn, &cn)) {
    if(bn == 0 && cn == 0) {
      break;
    }
    for(int i = 0; i < bn; i++)
      scanf("%d", &bv[i]);
    for(int i = 0; i < cn; i++)
      scanf("%d", &cv[i]);
    sort(bv, bv + bn);
    sort(cv, cv + cn);
    bool offside = bv[0] < cv[1];
    printf("%s\n", offside ? "Y" : "N");
  }
  return 0;
}
