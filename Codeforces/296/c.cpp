#include <cstring>
#include <vector>
#include <cstdio>
#define MAXN 200005

using namespace std;

int w, h, n;
int VL[MAXN];
int VR[MAXN];
int HL[MAXN];
int HR[MAXN];

typedef pair<char, int> CI;

int main() {
  scanf("%d %d %d\n", &w, &h, &n);
  vector<CI> cuts;
  memset(VL, -1, sizeof VL);
  memset(VR, -1, sizeof VR);
  memset(HL, -1, sizeof HL);
  memset(HR, -1, sizeof HR);
  VL[0] = 0;
  VR[0] = 0;
  VL[w] = 0;
  VR[w] = 0;
  HL[0] = 0;
  HR[0] = 0;
  HL[h] = 0;
  HR[h] = 0;
  while(n--) {
    char dir;
    int cut;
    scanf("%c %d\n", &dir, &cut);
    cuts.push_back(make_pair(dir, cut));
    if(dir == 'H') {
      HL[cut] = HR[cut] = 0;
    } else {
      VL[cut] = VR[cut] = 0;
    }
  }

  int maxh = -1;
  int prev = 0;
  for(int i = 1; i < h; i++) {
    if(HL[i] != -1) {
      HL[i] = prev;
      if(prev > 0)
	HR[prev] = i;
      maxh = max(maxh, i - prev);
      prev = i;
    }
  }
  HR[prev] = h;
  if(maxh == -1)
    maxh = h;
  else
    maxh = max(maxh, h - prev);
  
  int maxw = -1;
  prev = 0;
  for(int i = 1; i < w; i++) {
    if(VL[i] != -1) {
      VL[i] = prev;
      if(prev > 0)
	VR[prev] = i;
      maxw = max(maxw, i - prev);
      prev = i;
    }
  }
  VR[prev] = w;
  if(maxw == -1)
    maxw = w;
  else
    maxw = max(maxw, w - prev);

  vector<long long> res;
  res.push_back(maxh * 1LL * maxw);
  for(int i = cuts.size() - 1; i > 0; i--) {
    char dir = cuts[i].first;
    int cut = cuts[i].second;
    if(dir == 'H') {
      maxh = max(maxh, HR[cut] - HL[cut]);
      res.push_back(maxh * 1LL * maxw);
      HR[HL[cut]] = HR[cut];
      HL[HR[cut]] = HL[cut];
    } else {
      maxw = max(maxw, VR[cut] - VL[cut]);
      res.push_back(maxh * 1LL * maxw);
      VR[VL[cut]] = VR[cut];
      VL[VR[cut]] = VL[cut];
    }
  }

  for(int i = res.size() - 1; i > - 1; i--)
    printf("%I64d\n", res[i]);

  return 0;
}
