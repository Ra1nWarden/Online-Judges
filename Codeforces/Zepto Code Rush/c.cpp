#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int weight[2];
int utility[2];

int main() {
  int c, hr, hb, wr, wb;
  scanf("%d %d %d %d %d", &c, &hr, &hb, &wr, &wb);
  if((double) hr / wr > (double) hb / wb) {
    weight[0] = wr;
    weight[1] = wb;
    utility[0] = hr;
    utility[1] = hb;
  } else {
    weight[0] = wb;
    weight[1] = wr;
    utility[0] = hb;
    utility[1] = hr;
  }

  if(max(weight[0], weight[1]) > sqrt(c)) {
    int lw, lv, sw, sv;
    // printf("weight[0]=%d, weight[1]=%d\n", weight[0], weight[1]);
    if(weight[0] > weight[1]) {
      lw = weight[0];
      lv = utility[0];
      sw = weight[1];
      sv = utility[1];
    } else {
      lw = weight[1];
      lv = utility[1];
      sw = weight[0];
      sv = utility[0];
    }
    long long ans = 0;
    for(int i = 0; i * lw <= c; i++) {
      ans = max(ans, (long long) i * lv + (long long) (c - i * lw) / sw * sv);
      //printf("ans=%I64d lw= %d\n", ans, lw);
    }
    printf("%I64d\n", ans);
    return 0;
  }


  int take = c / weight[0];
  int othertake = (c - take * weight[0]) / weight[1];
  long long maxVal = (long long) take * utility[0] + (long long) othertake * utility[1];
  for(int t = take - 1; t >= 0; t--) {
    int othertake = (c - t * weight[0]) / weight[1];
    if(othertake > weight[0])
      break;
    maxVal = max(maxVal, (long long) t * utility[0] + (long long) othertake * utility[1]);
    if(t * weight[0] + othertake * weight[1] == c)
      break;
  }
  printf("%I64d\n", maxVal);
  return 0;
}
