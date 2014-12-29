#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[21][21];
// 0 -> nop
// 1 -> insert
// 2 -> delete
// 3 -> change
int op[21][21];

string a, b;

void print(int i, int j) {
  //cout << "print " << i << " and " << j << endl;
  if(i == 0 && j == 0)
    return;
  if(op[i][j] == 1) {
    print(i, j-1);
   
    printf("I%c%02d", b[j-1], j);
  }
  else if (op[i][j] == 0) {
    print(i-1, j-1);
  }
  else if (op[i][j] == 2) {
    print(i-1, j);
   
    printf("D%c%02d", a[i-1], j+1);
  } else {
    print(i-1, j-1);
 
    printf("C%c%02d", b[j-1], j);
  }
}

int main() {
  string line;
  while(getline(cin, line)) {
    if(line[0] == '#')
      break;
    for(int i = 0; i < line.length(); i++) {
      if(line[i] == ' ') {
	a = line.substr(0, i);
	b = line.substr(i+1);
	break;
      }
    }
    memset(dp, 0, sizeof dp);
    memset(op, -1, sizeof op);
    for(int i = 1; i <= a.length(); i++) {
      dp[i][0] = i;
      op[i][0] = 2;
    }
    for(int j = 1; j <= b.length(); j++) {
      dp[0][j] = j;
      op[0][j] = 1;
    }

    for(int i = 1; i <= a.length(); i++) {
      for(int j = 1; j <= b.length(); j++) {
	dp[i][j] = dp[i][j-1] + 1;
	op[i][j] = 1;
	if(dp[i-1][j] + 1 < dp[i][j]) {
	  dp[i][j] = dp[i-1][j] + 1;
	  op[i][j] = 2;
	}
	if(a[i-1] != b[j-1] && dp[i-1][j-1] + 1 < dp[i][j]) {
	  dp[i][j] = dp[i-1][j-1] + 1;
	  op[i][j] = 3;
	}
	if(a[i-1] == b[j-1] && dp[i-1][j-1] < dp[i][j]) {
	  dp[i][j] = dp[i-1][j-1];
	  op[i][j] = 0;
	}
      }
    }
    
    
    // cout << a << " vs " << b << endl;
    
    // cout << "debug op:" << endl;
    // for(int i = 0; i <= a.length(); i++) {
    //   for(int j = 0; j <= b.length(); j++) {
    // 	cout << op[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << "done" << endl;
    
    // cout << "debug dp:" << endl;
    // for(int i = 0; i <= a.length(); i++) {
    //   for(int j = 0; j <= b.length(); j++) {
    // 	cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << "done" << endl;
    
    print(a.length(), b.length());
    cout << "E" << endl;
  }
  return 0;
}
