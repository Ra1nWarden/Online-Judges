#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define INF 2e8

using namespace std;

typedef pair<int, int> coord;
// in priority queue with distance and coord
typedef pair<int, pair<int, int> > distpoint;

int r, c;
int m[1000][1000];
int minDist[1000][1000];

bool legal(int x, int y) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> r >> c;
    memset(m, -1, sizeof m);
    for(int i = 0; i < r; i++) {
      for(int j= 0; j < c; j++) {
	int x;
	cin >> x;
	m[i][j] = x;
      }
    }
    for(int i= 0 ;i < r; i++) {
      for(int j=  0; j < c; j++)
	minDist[i][j] = INF;
    }

    minDist[0][0] = 0;
    priority_queue<distpoint, vector<distpoint>, greater<distpoint> > pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    while(!pq.empty()) {
      distpoint next = pq.top();
      pq.pop();
      int d = next.first;
      int x = next.second.first;
      int y = next.second.second;
   
      if(d == minDist[x][y]) {
	if(legal(x-1, y)) {
	  int weight = m[x-1][y];
	  if(minDist[x][y] + weight < minDist[x-1][y]) {
	    minDist[x-1][y] = minDist[x][y] + weight;
	    pq.push(make_pair(minDist[x-1][y], make_pair(x-1, y)));
	  }
	}
	if(legal(x+1, y)) {
	  int weight = m[x+1][y];
	  if(minDist[x][y] + weight < minDist[x+1][y]) {
	    minDist[x+1][y] = minDist[x][y] + weight;
	    pq.push(make_pair(minDist[x+1][y], make_pair(x+1, y)));
	  }
	}
	if(legal(x, y-1)) {
	  int weight = m[x][y-1];
	  if(minDist[x][y] + weight < minDist[x][y-1]) {
	    minDist[x][y-1] = minDist[x][y] + weight;
	    pq.push(make_pair(minDist[x][y-1], make_pair(x, y-1)));
	  }
	}
	if(legal(x, y+1)) {
	  int weight = m[x][y+1];
	  if(minDist[x][y] + weight < minDist[x][y+1]) {
	    minDist[x][y+1] = minDist[x][y] + weight;
	    pq.push(make_pair(minDist[x][y+1], make_pair(x, y+1)));
	  }
	}
      }
    }
    cout << minDist[r-1][c-1] + m[0][0] << endl;
  }
  return 0;
}
