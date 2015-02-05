#include <iostream>
#include <cstring>

using namespace std;

int v[21];
// dp[i][j] (i sides left, j is the bit mask representing left over sticks): stores whether its possible to reach the state
// 0 init value, -1 not possible, 1 possible
int dp[4][1 << 20];
int n;
int l;

int bitsum(int bitmask) {
  int result = 0;
  for(int i= 0; i < n ; i++) {
    int newmask = bitmask >> i;
    if((newmask >> 1 << 1) ^ newmask) {
      result += v[i];
    }
  }
  return result;
}

int possible(int i, int j) {
  int left = bitsum(j) - i * l;
  if(left == l)
    return dp[i][j] = possible(i+1, j);
  else if (i == 4)
    return 1;
  else if(dp[i][j] != 0)
    return dp[i][j];
  else {
    int result = -1;
    for(int k = 0; k < n; k++) {
      if((!((1 << k) & j))  && left + v[k] <= l) {
	int subresult = possible(i, j | (1 << k));
	if(subresult == 1) {
	  result = 1;
	  break;
	}
      }
    }
    return dp[i][j] = result;
  }
}

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int sum = 0;
    cin >> n;
    for(int i= 0; i < n; i++) {
      cin >> l;
      v[i] = l;
      sum += l;
    }
    int result;
    if(sum % 4 != 0)
      result = -1;
    else {
      l = sum / 4;
      memset(dp, 0, sizeof dp);
      result = possible(0, 0);
    }
    cout << (result > 0 ? "yes" : "no") << endl;
  }
  return 0;
}
