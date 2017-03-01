#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int maxw = 100000;
int dpb[maxw+5];
int dph[maxw+5];
set<int> bs;
set<int> hs;
int h, b;

int test(int v, int nv) {
  if(v == -1)
    return nv;
  else
    return min(v, nv);
}

int main() {
  memset(dpb, -1, sizeof dpb);
  memset(dph, -1, sizeof dph);
  dph[0] = 0;
  dpb[0] = 0;
  hs.insert(0);
  bs.insert(0);
  scanf("%d", &h);
  int v;
  while(h--) {
    scanf("%d", &v);
    set<int> hsn = hs;
    for(set<int>::iterator itr = hs.begin(); itr != hs.end(); itr++) {
      hsn.insert(v + *itr);
      dph[v + *itr] = test(dph[v + *itr], dph[*itr] + 1);
    }
    hs = hsn;
  }
  scanf("%d", &b);
  while(b--) {
    scanf("%d", &v);
    set<int> bsn = bs;
    for(set<int>::iterator itr = bs.begin(); itr != bs.end(); itr++) {
      bsn.insert(v + *itr);
      dpb[v + *itr] = test(dpb[v + *itr], dpb[*itr] + 1);
    }
    bs = bsn;
  }
  const int inf = 2000000000;
  int ans = inf;
  for(set<int>::iterator itr = hs.begin(); itr != hs.end(); itr++) {
    if(*itr == 0)
      continue;
    if(bs.count(*itr)) {
      ans = min(ans, dph[*itr] + dpb[*itr]);
    }
  }
  if(ans == inf)
    printf("impossible\n");
  else
    printf("%d\n", ans);
  return 0;
}
