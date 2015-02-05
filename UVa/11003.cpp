#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int memo[1001][3001];

int main() {
  int n;
  while(cin >> n && n) {
    memset(memo, 0, sizeof memo);
    vector<pair<int, int> > boxes;
    int maxLoad = 0;
    for(int i= 0; i < n; i++) {
      int weight, load;
      cin >> weight >> load;
      boxes.push_back(make_pair(weight, load));
      maxLoad = max(maxLoad, load);
    }
    for(int i = 1; i <= n; i++) {
      if(i == 1) {
	int firstLoad = boxes.front().second;
	for(int j = 0; j <= maxLoad; j++) {
	  if(j == firstLoad)
	    memo[i][j] = 1;
	  else
	    memo[i][j] = 0;
	}
      } else {
	int currentLoad = boxes[i].second;
	int currentWeight = boxes[i].first;
	for(int j = 0; j <= maxLoad; j++) {
	  if(j < currentLoad) {
	    // take j
	    if(j + currentWeight > 3000) {
	      memo[i][j] = memo[i-1][j];
	    } else {
	      memo[i][j] = memo[i-1][j+currentWeight] + 1;
	    }
	  } else if (j == currentLoad) {
	    if(j + currentWeight > 3000) {
	      memo[i][j] = max(memo[i-1][j], 1);
	    } else {
	      memo[i][j] = max(memo[i-1][j+currentWeight] + 1, memo[i-1][j]+1);
	    }
	  } else {
	    // j > currentLoad
	    memo[i][j] = memo[i-1][j];
	  }
	}
      }
    }
    int result = 0;
    for(int j = 0; j <= maxLoad; j++) {
      result = max(result, memo[n][j]);
    }
    cout << result << endl;
  }
  return 0;
}
