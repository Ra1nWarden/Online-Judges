#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;

bool DEBUG = false;

double dist[17][17];
int x[17];
int y[17];
int n;
double memo[1 << 17];

double calculate(int bit_mask) {
  if(DEBUG)
    cout << "calling " << bit_mask << endl;
  if(memo[bit_mask] > -0.5)
    return memo[bit_mask];
  if(bit_mask == (1 << 2*n) - 1) {
    if(DEBUG)
      cout << "returning 0" << endl;
    return memo[bit_mask] = 0;
  }
  double minVal = 32767 * 32767;
  for(int i = 0; i < 2*n; i++) {
    if(!(bit_mask & (1 << i))) {
      if(DEBUG) {
	cout << "found 0 at " << i << endl;
      }
      for(int j = i+1; j < 2*n; j++) {
	if(!(bit_mask & (1 << j))) {
	  double nextMin =  dist[i][j] + calculate(bit_mask | (1 << i) | (1 << j));
	  minVal = min(minVal, nextMin);
	  if(DEBUG) {
	    cout << "dist[i][j]" << dist[i][j] << endl;
	    cout <<  "minVal compared to " << nextMin << endl;
	    cout << minVal << endl;
	  }
	}
      }
      break;
    }
  }
  memo[bit_mask] = minVal;
  return minVal;
}

int main() {
  int caseNo = 1;
  while(cin >> n && n) {
    string line;
    getline(cin, line);
    memset(x, -1, sizeof x);
    memset(y, -1, sizeof y);
    memset(memo, -1, sizeof memo);
    for(int i = 0; i < 2 * n; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      string name;
      int xx, yy;
      getline(iss, name, ' ');
      iss >> xx >> yy;
      x[i] = xx;
      y[i] = yy;
    }
    for(int i = 0; i < 2*n; i++) {
      for(int j = 0; j < 2*n; j++) {
	if(i == j)
	  dist[i][j] = 0;
	else {
	  if(DEBUG)
	    cout << pow(y[i] - y[j],2) << ", " <<  pow(x[i]- x[j], 2) << endl;
	  dist[i][j] = sqrt(pow(y[i] - y[j],2) + pow(x[i]- x[j], 2));
	}
      }
    }
    double result = calculate(0);
    printf("Case %d: %.2f\n", caseNo++, result);
  }
  return 0;
}
