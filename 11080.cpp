#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool v[201][201];
int color[201];
int n;

int bicolor(int start) {
  // 0 is red and 1 is blue
  int red = 1;
  int blue = 0;
  queue<int> q;
  q.push(start);
  color[start] = 0;
  bool possible = true;
  while(!q.empty() && possible) {
    int next = q.front();
    q.pop();
    int nextcolor = color[next] == 0 ? 1 : 0;
    for(int i = 0; i < n; i++) {
      if(v[next][i]) {
	if(color[i] == -1) {
	  color[i] = nextcolor;
	  q.push(i);
	  if(nextcolor == 0)
	    red++;
	  else
	    blue++;
	}
	else if(color[i] != nextcolor) {
	  // cout << i << " and " << next << " has the same color " << endl;
	  possible = false;
	  break;
	}
      }
    }
  }
  if(possible) {
    //cout << "red is " << red << " blue is " << blue << endl;
    if(blue == 0)
      return 1;
    else
      return min(blue, red);
  }
  else
    return -1;
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    memset(v, false, sizeof v);
    int street;
    cin >> n >> street;
    for(int i= 0; i < street; i++) {
      int x, y;
      cin >> x >> y;
      v[x][y] = v[y][x] = true;
    }
    memset(color, -1, sizeof color);
    int result = 0;
    for(int i= 0; i < n; i++) {
      if(color[i] == -1) {
	// cout << "bicolor on " << i << endl;
	int add = bicolor(i);
	if(add == -1) {
	  result = -1;
	  break;
	}
	else {
	  result += add;
	}
      }
    }
    cout << result << endl;
  }
  return 0;
}
