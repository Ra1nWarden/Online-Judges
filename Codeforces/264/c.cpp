#include <cstdio>
#define MAXN 2005

using namespace std;

long long prefix_sum[MAXN][MAXN][2];
int n;

int main() {
  scanf("%d", &n);
  for(int i =0 ; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      prefix_sum[i][j][0] = prefix_sum[i][j][1] = x;
      if(i > 0 && j > 0)
	prefix_sum[i][j][0] += prefix_sum[i-1][j-1][0];
      if(i > 0 && j < n - 1)
	prefix_sum[i][j][1] += prefix_sum[i-1][j+1][1];
    }
  }

  long long oddsum, evensum;
  int x1, y1, x2, y2;
  oddsum = evensum = 0;
  x1 = 1;
  x2 = 1;
  y1 = 1;
  y2 = 2;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      long long sum = 0;
      if(i == j) {
	sum += prefix_sum[n-1][n-1][0];
      } else if(i > j) {
	sum += prefix_sum[n-1][n-1-(i-j)][0];
      } else {
	sum += prefix_sum[n-1-(j-i)][n-1][0];
      }
      
      if(i > 0 && j < n -1)
	sum += prefix_sum[i-1][j+1][1];
      
      if(i + j == n - 1) {
	sum += (prefix_sum[n-1][0][1] - prefix_sum[i][j][1]);
      } else if(i + j  < n - 1) {
	sum += (prefix_sum[i+j][0][1] - prefix_sum[i][j][1]);
      } else {
	sum += (prefix_sum[n-1][i+j-n+1][1] - prefix_sum[i][j][1]);
      }
      
      if((i + j) % 2 == 0) {
	if(sum > evensum) {
	  evensum = sum;
	  x1 = i+1;
	  y1 = j+1;
	}
      } else {
	if(sum > oddsum) {
	  oddsum = sum;
	  x2 = i+1;
	  y2 = j+1;
	}
      }
      
    }
  }
  
  printf("%I64d\n", oddsum + evensum);
  printf("%d %d %d %d\n", x1, y1, x2, y2);

  return 0;
}
