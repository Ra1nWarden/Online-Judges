#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool v[1001][1001];
bool visited[1001];
int n;

int main() {
  int l;
  while(cin >> n >> l && (n || l)) {
    //cout << "n is " << n << " l is " << l << endl;
    memset(v, false, sizeof v);
    for(int i= 0; i < l; i++) {
      int x, y;
      cin >> x >> y;
      //cout << "read edge " << x << " and " << y << endl;
      v[x][y] = true;
    }

    vector<int> zeroNodes;
    
    for(int i= 1; i <= n; i++) {
      bool zeroIn = true;
      for(int j = 1; j<= n; j++) {
	if(v[j][i]) {
	  zeroIn = false;
	  break;
	}
      }
      if(zeroIn) {
	zeroNodes.push_back(i);
      }
    }

    memset(visited,false, sizeof visited);
    
    bool multiple = false;
    bool possible = true;
    if(zeroNodes.size() == 0) {
      possible = false;
    }
    if(possible) {
      int next = zeroNodes[0];
      visited[next] = true;
      while(true) {
	bool terminate = true;
	for(int i= 1; i<=n; i++) {
	  if(v[next][i] && !visited[i]) {
	    next = i;
	    visited[i] = true;
	    terminate = false;
	    break;
	  }
	  if(v[next][i] && visited[i]) {
	    possible = false;
	    break;
	  }
	}
	if(terminate)
	  break;
      }
    }
    if(possible) {
      for(int i =1; i<=n; i++) {
	if(!visited[i]) {
	  multiple = true;
	  break;
	}
      }
      cout << (multiple ? 2 : 1) << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  return 0;
}
