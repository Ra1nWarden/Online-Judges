#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

bool DEBUG = false;

int main() {
  int r, c;
  while(cin >> r >> c && (r || c)) {
    int v[r][c];
    for(int i= 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
	int x;
	cin >> x;
	v[i][j] = x;
      }
    }
    if(DEBUG) {
      cout << "printing v matrix" << endl;
      for(int j = 0; j < r; j++) {
	for(int k = 0; k < c; k++) {
	  cout << v[j][k] << " " ;
	}
	cout << endl;
      }
      cout << endl;
    }
    int sum[r][c];
    memset(sum, 0, sizeof sum);
    for(int j = 0; j < r; j++) {
      for(int k = 0; k < c; k++) {
	int subsum = v[j][k];
	if(j > 0)
	  subsum += sum[j-1][k];
	if(k > 0)
	  subsum += sum[j][k-1];
	if(j > 0 && k > 0)
	  subsum -= sum[j-1][k-1];
	sum[j][k] = subsum;
      }
    }
    if(DEBUG) {
      cout << "sum matrix" << endl;
      for(int j = 0; j < r; j++) {
	for(int k = 0; k < c; k++) {
	  cout << sum[j][k] << " ";
	}
	cout << endl;
      }
      cout << endl;
    }
    int result = 0;
    for(int j = 0; j < r; j++) {
      for(int k = 0; k < c; k++) {
	for(int l = j; l < r; l++) {
	  for(int m = k; m < c; m++) {
	    int subsum = sum[l][m];
	    if(j > 0)
	      subsum -= sum[j-1][m];
	    if(k > 0)
	      subsum -= sum[l][k-1];
	    if(j > 0 && k > 0)
	      subsum += sum[j-1][k-1];
	    if(subsum == 0) {
	      result = max(result, (l-j+1) * (m-k+1));
	    }
	  }
	}
      }
    }
    cout << result << endl;
  }
  return 0;
}
