#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>
#include <cstdlib>

using namespace std;

// 0 means leading and 1 means not leading
string dpmin[101][901][2];
string dpmax[101][901][2];

string itos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}

string fmin(int m, int s, int l) {
  if(dpmin[m][s][l] != "*")
    return dpmin[m][s][l];
  string result = itos(-1);
  if(m == 1) {
    result = s >= 10 ? itos(-1) : itos(s);
  }
  else if(s == 0) {
    if(l == 0)
      result = m == 1 ? itos(0) : itos(-1);
    else
      result = itos(0);
  } else {
    int start = l == 1 ? 0 : 1;
    for(int i = start; i <= s && i <= 9; i++) {
      if(fmin(m-1, s-i, 1) != itos(-1)) {
	result = fmin(m-1, s-i, 1);
	while(result.length() != m - 1)
	  result = "0" + result;
	result = itos(i) + result;
	break;
      }
    }
  }
  dpmin[m][s][l] = result;
  return result;
}

string fmax(int m, int s, int l) {
  if(dpmax[m][s][l] != "*")
    return dpmax[m][s][l];
  string result = itos(-1);
  if(m == 1) {
    result = s >= 10 ? itos(-1) : itos(s);
  } else if(s == 0) {
    if(l == 0)
      result = m == 1 ? itos(0) : itos(-1);
    else
      result = itos(0);
  } else {
    int end = l == 1 ? 0 : 1;
    for(int i= 9; i >= end; i--) {
      if(s - i < 0)
	continue;
      if(fmax(m-1, s-i, 1) != itos(-1)) {
	result = fmax(m-1, s-i, 1);
	 //cout << "before resultStr is " << resultStr << endl;
	 while(result.length() != m - 1)
	   result = "0" + result;
	 //cout << "resultStr is" << endl;
	 result = itos(i) + result;
	 break;
      }
    }
  }
  dpmax[m][s][l] = result;
  //cout << "calling famx with " << m << ", " << s << ", " << l << " result is " << result << endl;
  return result;
}

void init(int m, int s) {
  for(int i = 0; i <= m; i++) {
    for(int j= 0; j <= s; j++) {
      for(int k = 0; k < 2; k++) {
	dpmin[i][j][k] = "*";
	dpmax[i][j][k] = "*";
      }
    }
  }
}

int main() {
  int m, s;
  cin >> m >> s;
  init(m, s);
  cout << fmin(m, s, 0) << " "<< fmax(m, s, 0) << endl;
  return 0;
}
