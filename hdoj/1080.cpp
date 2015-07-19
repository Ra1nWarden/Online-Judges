#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 105

using namespace std;

char a[MAXN], b[MAXN];
int av[MAXN], bv[MAXN];
int al, bl;
int score[5][5] = {{5,-1,-2,-1,-3}, {-1,5,-3,-2,-4}, {-2,-3,5,-2,-2}, {-1,-2,-2,5,-1}, {-3,-4,-2,-1,0}};
int dp[MAXN][MAXN];
bool dpv[MAXN][MAXN];

int f(int ai, int bi) {
  if(dpv[ai][bi])
    return dp[ai][bi];
  if(ai == 0 && bi == 0) {
    return dp[0][0] = 0;
  }
  int ans = -1000;
  if(bi > 0) {
    ans = max(ans, f(ai, bi-1) + score[4][bv[bi-1]]);
  }
  if(ai > 0) {
    ans = max(ans, f(ai-1, bi) + score[av[ai-1]][4]);
  }
  if(ai > 0 && bi > 0) {
    ans = max(ans, f(ai-1, bi-1) + score[av[ai-1]][bv[bi-1]]);
  }
  dpv[ai][bi] = true;
  return dp[ai][bi] = ans;
}

void decode(char* charv, int* intv, int len) {
  for(int i = 0; i < len; i++) {
    switch(charv[i]) {
    case 'A':
      intv[i] = 0;
      break;
    case 'C':
      intv[i] = 1;
      break;
    case 'G':
      intv[i] = 2;
      break;
    case 'T':
      intv[i] = 3;
      break;
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %s\n", &al, a);
    scanf("%d %s\n", &bl, b);
    decode(a, av, al);
    decode(b, bv, bl);
    memset(dpv, false, sizeof dpv);
    printf("%d\n", f(al, bl));
  }
  return 0;
}
