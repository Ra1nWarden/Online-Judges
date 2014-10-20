#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

bool DEBUG = false;
int**** rangesum;
int** sum;
int** v;

int main() {
  rangesum = new int***[76];
  for( int i = 0 ; i < 76 ; i++ ) {
    rangesum[i] = new int**[76] ;
    for( int j = 0 ; j < 76 ; j++ ) {
      rangesum[i][j] = new int*[76] ;
      for( int k = 0 ; k < 76 ; k++ ) {
	rangesum[i][j][k] = new int[76] ;
      }
    }
  }
  
  sum = new int*[76];
  for(int i =0; i < 76; i++)
    sum[i] = new int[76];
  
  v = new int*[76];
  for(int i= 0; i < 76; i++)
    v[i] = new int[76];

  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int n;
    cin >> n;
    for(int j= 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
	int x;
	cin >> x;
	v[j][k] = x;
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
	    rangesum[j][k][l][m] = subsum;
	  }
	}
      }
    }
    int result = INT_MIN;
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
	for(int l = 0; l < n; l++) {
	  for(int m = 0; m < n; m++) {
	    if(l >= j && m >= k)
	      result = max(result, rangesum[j][k][l][m]);
	    else if(l >= j) {
	      // m < k
	      result = max(result, rangesum[j][k][l][n-1] + rangesum[j][0][l][m]);
	    }
	    else if(m >= k) {
	      // l < j
	      result = max(result, rangesum[j][k][n-1][m] + rangesum[0][k][l][m]);
	    } else {
	      result = max(result, rangesum[j][k][n-1][n-1] + rangesum[0][k][l][n-1] + rangesum[0][0][l][m] + rangesum[j][0][n-1][m]);
	    }
	  }
	}
      }
    }
    cout << result << endl;
  }
  delete[] rangesum;
  delete[] v;
  delete[] sum;
  return 0;
}
