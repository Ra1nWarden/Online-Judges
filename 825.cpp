#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  bool init = true;
  while(tc--) {
    if(!init)
      cout << endl;
    int w, n;
    cin >> w >> n;
    string line;
    getline(cin, line);
    int ways[w+1][n+1];
    memset(ways, 0, sizeof ways);
    for(int i= 1; i <= w; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      int blocks;
      iss >> blocks;
      while(iss >> blocks)
	ways[i][blocks] = -1;
    }
    ways[1][1] = 1;
    for(int i = 1; i <= w; i++) {
      for(int j= 1; j <= n; j++) {
	if(ways[i][j] != -1) {
	  if(j - 1 > 0 && ways[i][j-1] != -1)
	    ways[i][j] = ways[i][j] + ways[i][j-1];
	  if(i - 1 > 0 && ways[i-1][j] != -1)
	    ways[i][j] = ways[i][j] + ways[i-1][j];
	}
      }
    }

    // for(int i= 1; i<= w; i++) {
    //   for(int j= 1; j <=n; j++) {
    // 	cout << ways[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    cout << ways[w][n] << endl;
    init = false;
  }
  return 0;
}
