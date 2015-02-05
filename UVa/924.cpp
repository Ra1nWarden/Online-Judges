#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

bool v[2500][2500];
int bfsIndex[2500];
int n;

void bfs(int u) {
  bfsIndex[u] = 0;
  queue<int> q;
  q.push(u);
  while(!q.empty()) {
    int next = q.front();
    q.pop();
    for(int i = 0; i < n; i++) {
      if(v[next][i] && bfsIndex[i] == -1) {
	bfsIndex[i] = bfsIndex[next] + 1;
	q.push(i);
      }
    }
  }
}

int main() {
  while(cin >> n) {
    memset(v, false, sizeof v);
    for(int i = 0; i < n; i++) {
      int sideCount;
      cin >> sideCount;
      for(int j= 0; j < sideCount; j++) {
	int side;
	cin >> side;
	v[i][side] = true; 
      }
    }
    int query;
    cin >> query;
    // cout << "outside query is " << query << endl;
    for(int i=  0; i < query; i++) {
      memset(bfsIndex, -1, sizeof bfsIndex);
      int start;
      cin >> start;
      bfs(start);
      map<int, int> increaseMap;
      for(int j= 0; j < n; j++) {
	int depth = bfsIndex[j];
	if(depth > 0) {
	  if(increaseMap.count(depth) == 0)
	    increaseMap[depth] = 1;
	  else
	    increaseMap[depth] = increaseMap[depth] + 1;
	}
      }
      int maxLength = -1;
      int maxDay = -1;
      for(map<int, int>::iterator itr = increaseMap.begin(); itr != increaseMap.end(); itr++) {
	if(itr->second > maxLength) {
	  // cout << "maxLength is " << maxLength << " new number is " << itr->second << endl;
	  maxLength = itr->second;
	  maxDay = itr->first;
	}
      }
      if(maxDay == -1)
	cout << 0 << endl;
      else
	cout << maxLength << " " << maxDay << endl;
    }
  }
  return 0;
}
