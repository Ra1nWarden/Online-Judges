#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

long long dp[301][301][301];
long long dp2[301][301];
long long dp3[301][301];

long long f(int i, int j, int k) {
  if(dp[i][j][k] > -1)
    return dp[i][j][k];
  long result = 0;
  if(i >= k) {
    int remain = i - k;
    for(int x = k; remain >= (j-1)*x; x++) {
      result += f(remain, j-1, x);
    }
  } else {
    // i < k
    result = 0;
  }
  dp[i][j][k] = result;
  return result;
}

// build i with j
long long f2(int i, int j) {
  if(j == 0) {
    return i == 0 ? 1 : 0;
  }
  if(dp2[i][j] > -1)
    return dp2[i][j];
  long long result = 0;
  for(int x = 1; x <= i/j; x++)
    result += f(i, j, x);
  dp2[i][j] = result;
  return result;
}

// build i with j or less
long long f3(int i, int j) {
  if(dp3[i][j] > -1)
    return dp3[i][j];
  long long result = 0;
  for(int x = 0; x <= j; x++) {
    result += f2(i, x);
  }
  dp3[i][j] = result;
  return result;
}

int main() {
  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  memset(dp3, -1, sizeof dp3);
  for(int i = 0; i <= 300; i++) {
    for(int j= 0; j <= 300; j++) {
      for(int k = 0; k <= 300; k++) {
	if(j == 0)
	  dp[i][j][k] = 0;
	else if (j == 1) {
	  if(i == k)
	    dp[i][j][k] = 1;
	  else
	    dp[i][j][k] = 0;
	}
	else if(k * j  > i)
	  dp[i][j][k] = 0;
      }
    }
  }
  dp[0][0][0] = 1;
  string line;
  while(getline(cin, line)) {
    istringstream iss(line.c_str());
    vector<int> input;
    int x;
    iss >> x;
    input.push_back(x);
    while(iss >> x)
      input.push_back(x > 300 ? 300 : x);
    if(input.size() == 1) {
      cout << f3(input[0], input[0]) << endl;
    } else if (input.size() == 2) {
      cout << f3(input[0], input[1]) << endl;
    } else {
      long long result = 0;
      for(int y = input[1]; y <= input[2]; y++)
	result += f2(input[0], y);
      cout << result << endl;
    }
  }
  return 0;
}
