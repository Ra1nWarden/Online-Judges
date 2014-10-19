#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int n;
  cin >> n;
  int v[n][n];
  for(int i= 0; i < n; i++) {
    for(int j= 0; j < n; j++) {
      int x;
      cin >> x;
      v[i][j] = x;
    }
  }
  int sum[n][n];
  memset(sum, 0, sizeof sum);
  sum[0][0] = v[0][0];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int subsum = v[i][j];
      if(i > 0)
	subsum += sum[i-1][j];
      if(j > 0)
	subsum += sum[i][j-1];
      if(i > 0 && j > 0)
	subsum -= sum[i-1][j-1];
      sum[i][j] = subsum;
    }
  }
  int maxSum = 0;
  for(int i= 0; i < n; i++) {
    for(int j=0; j < n; j++) {
      for(int k = i; k < n; k ++) {
	for(int l = j; l < n; l++) {
	  int result = sum[k][l];
	  if(i > 0) {
	    result -= sum[i-1][l];
	  }
	  if(j > 0) {
	    result -= sum[k][j-1];
	  }
	  if(i > 0 && j > 0)
	    result += sum[i-1][j-1];
	  maxSum = max(result, maxSum);
	}
      }
    }
  }
  cout << maxSum << endl;
  return 0;
}
