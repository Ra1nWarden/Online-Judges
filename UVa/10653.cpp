#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int r, c;
int v[1001][1001];

int bfs(int x1, int y1, int x2, int y2) {
  v[x1][y1] = 0;
  queue<pair<int, int> > q;
  q.push(make_pair(x1, y1));
  while(!q.empty() && v[x2][y2] == -1) {
    pair<int, int> next = q.front();
    q.pop();
    int x = next.first;
    int y = next.second;
    if(x - 1 >=0 && v[x-1][y] == -1) {
      v[x-1][y] = v[x][y] + 1;
      q.push(make_pair(x-1, y));
    }
    if(x+1 < r && v[x+1][y] == -1) {
      v[x+1][y] = v[x][y] + 1;
      q.push(make_pair(x+1, y));
    }
    if(y-1 >= 0 && v[x][y-1] == -1) {
      v[x][y-1] = v[x][y] + 1;
      q.push(make_pair(x, y-1));
    }
    if(y+1 < c && v[x][y+1] == -1) {
      v[x][y+1] = v[x][y] + 1;
      q.push(make_pair(x, y+1));
    }
  }
  return v[x2][y2];
}

int main() {
  while(cin >> r >> c && (r || c)) {
    int maxRow;
    cin >> maxRow;
    memset(v, -1, sizeof v);
    int x, y;
    for(int i= 0; i < maxRow; i++) {
      cin >> x;
      int ycount;
      cin >> ycount;
      for(int j= 0 ; j < ycount; j++) {
	cin >> y;
	v[x][y] = 0;
      }
    }
    // for(int i= 0; i < r; i++)  {
    //   for(int j = 0; j < c; j++) {
    // 	cout << v[i][j];
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    int xstart, ystart, xend, yend;
    cin >> xstart >> ystart >> xend >> yend;
    int result = bfs(xstart, ystart, xend, yend);
    cout << result << endl;
  }
  return 0;
}
