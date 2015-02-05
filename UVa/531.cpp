#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

int main() {
  string line;
  while(!cin.eof()) {
    //cout << "outer while" << endl;
    vector<string> a;
    vector<string> b;
    while(getline(cin, line)) {
      if(line[0] == '#')
	break;
      stringstream ss(line.c_str());
      string word;
      while(ss >> word)
	a.push_back(word);
    }
    //cout << "finished reading a" << endl;
    while(getline(cin, line)) {
      if(line[0] == '#')
	break;
      stringstream ss(line.c_str());
      string word;
      while(ss >> word)
	b.push_back(word);
    }
    //cout << "finished reading b" << endl;
    int dp[a.size() + 1][b.size() + 1];
    int dir[a.size() + 1][b.size() + 1];
    memset(dp, 0, sizeof dp);
    memset(dir, 0, sizeof dir);

    // 1 -> up
    // 2 -> left
    for(int i = 1; i <= a.size(); i++)
      dir[i][0] = 1;
    for(int j = 1; j <= b.size(); j++)
      dir[0][j] = 2;

    for(int i = 1; i <= a.size(); i++) {
      for(int j = 1; j <= b.size(); j++) {
	//cout << "filling dp " << i << ", " << j << endl;
	dp[i][j] = dp[i-1][j];
	dir[i][j] = 1;
	if(dp[i][j-1] > dp[i][j]) {
	  dp[i][j] = dp[i][j-1];
	  dir[i][j] = 2;
	}
	if(a[i-1] == b[j-1] && dp[i-1][j-1] + 1 > dp[i][j]) {
	  dp[i][j] = dp[i-1][j-1] + 1;
	  dir[i][j] = 3;
	}
      }
    }
    stack<string> printw;
    int starti = a.size();
    int startj = b.size();
    while(starti != 0 || startj != 0) {
      //cout << starti << " and " << startj << endl;
      if(dir[starti][startj] == 3) {
	printw.push(a[starti-1]);
	starti--;
	startj--;
      } else if (dir[starti][startj] == 1){
	starti = starti - 1;
      } else if (dir[starti][startj] == 2) {
	startj = startj - 1;
      }
    }
    bool init = true;
    while(!printw.empty()) {
      if(!init)
	cout << " ";
      cout << printw.top();
      printw.pop();
      init = false;
    }
    cout << endl;
  }
  return 0;
}
