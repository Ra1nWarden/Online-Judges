#include <cstdio>
#include <cstring>
#define MAXN 2000000

using namespace std;

char cards[9][4][4];
double dp[MAXN];
bool dpm[MAXN];
const int fullmask = 1953125;

bool read_input() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 4; j++) {
      if(scanf("%s", cards[i][j]) == EOF)
	return false;
    }
  }
  return true;
}

double f(int mask) {
  if(dpm[mask])
    return dp[mask];
  if(mask == 0) {
    return 1;
  }
  int left[9];
  int mask_cpy = mask;
  for(int i =0; i < 9; i++) {
    left[i] = mask_cpy % 5;
    mask_cpy /= 5;
  }
  int move_cnt = 0;
  dp[mask] = 0.0;
  for(int i = 0; i < 9; i++) {
    for(int j = i+1; j < 9; j++) {
      if(left[i] > 0 && left[j] > 0) {
	if(cards[i][left[i] - 1][0] == cards[j][left[j] - 1][0]) {
	  move_cnt++;
	  int nextmask = 0;
	  int base = 1;
	  left[i]--;
	  left[j]--;
	  for(int k = 0; k < 9; k++) {
	    nextmask += (base * left[k]);
	    base *= 5;
	  }
	  dp[mask] += f(nextmask);
	  left[i]++;
	  left[j]++;
	}
      }
    }
  }
  dpm[mask] = true;
  if(move_cnt != 0)
    dp[mask] /= move_cnt;
  return dp[mask];
}

int main() {
  while(read_input()) {
    memset(dpm, false, sizeof dpm);
    printf("%.6f\n", f(fullmask - 1));
  }
  return 0;
}
