#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105

using namespace std;

int n, k;
int v[MAXN];

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int ans[MAXN][2];
  int ansi = 0;
  for(int i = 0; i < k; i++) {
    int maxval = -1;
    int maxi = -1;
    int minval = 2000000000;
    int mini = -1;
    for(int j = 0; j < n; j++) {
      if(v[j] > maxval) {
	maxval = v[j];
	maxi = j+1;
      }
      if(v[j] < minval) {
	minval = v[j];
	mini = j+1;
      }
    }
    if(maxval - minval <= 1)
      break;
    v[maxi-1]--;
    v[mini-1]++;
    ans[ansi][0] = maxi;
    ans[ansi][1] = mini;
    ansi++;
  }
  int maxval = -1;
  int minval = 2000000000;
  for(int j = 0; j < n; j++) {
    maxval = max(maxval, v[j]);
    minval = min(minval, v[j]);
  }
  printf("%d %d\n", maxval - minval, ansi);
  for(int i = 0; i < ansi; i++)
    printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
