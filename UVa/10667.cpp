#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

bool DEBUG = false;

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int n;
    cin >> n;
    int v[n][n];
    memset(v, 0, sizeof v);
    int blocks;
    cin >> blocks;
    for(int j = 0; j < blocks; j++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      for(int k = x1-1; k <= x2-1; k++) {
	for(int l = y1-1; l <= y2-1; l++) {
	  v[k][l] = 1;
	}
      }
    }
    if(DEBUG) {
      cout << "printing v matrix" << endl;
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < n; k++) {
	  cout << v[j][k] << " " ;
	}
	cout << endl;
      }
      cout << endl;
    }
    int sum[n][n];
    memset(sum, 0, sizeof sum);
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
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
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < n; k++) {
	  cout << sum[j][k] << " ";
	}
	cout << endl;
      }
      cout << endl;
    }
    int result = 0;
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
	for(int l = j; l < n; l++) {
	  for(int m = k; m < n; m++) {
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
