#include <cstdio>

using namespace std;

const int maxn = 200000;
const int maxk = 50;
double t[maxn+5];
int n, k;
double dp[maxn+1][maxnk+1];

int main() {
  scanf("%d%d", &n, &k);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    t[i] = (long double) sum / num + 1;
    if(i)
      t[i] += t[i-1];
    sum += num;
  }
  for(int region = 1; region <= k; region++) {
    for(int levels = region; levels <= n; levels++) {
      if(region == 1) {
	dp[levels][region] = 
      }
    }
  }
  return 0;
}
